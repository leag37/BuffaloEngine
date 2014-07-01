// Filename: BuffRenderSystem.cpp
// Author: Gael Huber
#include "Rendering\BuffRenderSystem.h"
#include "Rendering\BuffRenderManager.h"
#include "Rendering\BuffRenderWindow.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	RenderSystem::RenderSystem()
	{
		
	}

	/**
	* Destructor
	*/
	RenderSystem::~RenderSystem()
	{

	}

	/**
	* Initialize the render system
	* @return
	*	bool Return true if the initialization succeeds
	*/
	bool RenderSystem::Initialize()
	{
		if(CreateDriver() == false)
		{
			return false;
		}

		if(CreateDevice() == false)
		{
			return false;
		}

		if(CreateSwapChain() == false)
		{
			return false;
		}

		if(CreateRenderTargetView() == false)
		{
			return false;
		}

		return true;
	}

	/**
	* Shutdown the render system
	*/
	void RenderSystem::Shutdown()
	{

	}

	/**
	* Prepare the scene for rendering
	*/
	void RenderSystem::BeginScene()
	{
		// Clear color
		float color[4] = {0.0f, 0.0f, 0.0f, 1.0f};

		// Clear the back buffer to black
		_device.GetImmediateContext()->ClearRenderTargetView(_renderTargetView, color);

		// Clear the depth buffer
		//_device.GetImmediateContext()->ClearDepthStencilBuffer(_depthStencilView);
	}

	/**
	* Render a render queue
	* @param
	*	const RenderQueue& The render queue to process
	*/
	//void Render(const RenderQueue& renderQueue);

	/**
	* Present the scene
	*/
	void RenderSystem::EndScene()
	{
		// Present the swap chain
		_swapChain->Present(0, 0);
	}

	/**
	* Get the render device owned by the system
	* @return
	*	const RenderDevice& The render device
	*/
	const RenderDevice& RenderSystem::GetRenderDevice() const
	{
		return _device;
	}

	/**
	* Create the device driver
	* @return
	*	bool Return true if the driver is created successfully
	*/
	bool RenderSystem::CreateDriver()
	{
		IDXGIFactory* factory;
		IDXGIAdapter* adapter;
		HRESULT result;

		// Create the DirectX graphics interface factory
		result = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&factory);
		if(FAILED(result))
		{
			return false;
		}

		// Create the list of available drivers
		for(uint i = 0; ; ++i)
		{
			// Attempt to create the adapter
			result = factory->EnumAdapters(i, &adapter);

			// No adapter is found
			if(FAILED(result))
			{
				break;
			}

			// An adapter is found, so create a driver and add it to the list
			_availableDrivers.push_back(RenderDeviceDriver(adapter));
		}

		// Iterate through the available drivers until one is selected
		bool adapterChosen = false;
		for(std::vector<RenderDeviceDriver>::iterator itr = _availableDrivers.begin(); itr != _availableDrivers.end(); ++itr)
		{
			// Select adapter by default
			if(adapterChosen == false)
			{
				adapterChosen = true;
				_activeDriver = *itr;
			}
			else
			{
				// TODO Choose appropriate profiles
			}
		}

		if(adapterChosen == false)
		{
			return false;
		}
		
		return true;
	}

	/**
	* Create the device
	* @return
	*	bool Return true if the device is created successfully
	*/
	bool RenderSystem::CreateDevice()
	{
		// Create the D3D device
		if(_device.Initialize(_activeDriver) == false)
		{
			return false;
		}
		return true;
	}

	/**
	* Create the swap chain
	* @return 
	*	bool Return true if successful
	*/
	bool RenderSystem::CreateSwapChain()
	{
		// Get the render manager
		RenderManager* renderManager = RenderManager::GetSingletonPtr();

		// Create the description
		DXGI_SWAP_CHAIN_DESC sd;
		sd.BufferDesc.Width = 800;
		sd.BufferDesc.Height = 600;
		sd.BufferDesc.RefreshRate.Numerator = 60;
		sd.BufferDesc.RefreshRate.Denominator = 1;
		sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.BufferCount = 1;
		sd.OutputWindow = renderManager->GetRenderWindow()->GetHWND();
		sd.Windowed = true;
		sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		sd.Flags = 0;

		// Get the DXGI factory parent of the active driver
		IDXGIFactory* factory = 0;
		HRESULT result = _activeDriver.GetAdapter()->GetParent(__uuidof(IDXGIFactory), (void**)&factory);
		if(FAILED(result))
		{
			return false;
		}

		// Create the swap chain from the factory
		result = factory->CreateSwapChain(_device.GetD3DDevice(), &sd, &_swapChain);
		if(FAILED(result))
		{
			return false;
		}

		return true;
	}

	/**
	* Create the render target view
	* @return 
	*	bool Return true if successful
	*/
	bool RenderSystem::CreateRenderTargetView()
	{
		// Get a pointer to the back buffer
		ID3D11Texture2D* backBuffer;
		HRESULT result;

		result = _swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&backBuffer);
		if(FAILED(result))
		{
			return false;
		}

		// Create the render target to the back buffer
		result = _device.GetD3DDevice()->CreateRenderTargetView(backBuffer, NULL, &_renderTargetView);
		if(FAILED(result))
		{
			return false;
		}

		// Release the back buffer
		backBuffer->Release();
		backBuffer = 0;

		return true;
	}

	/**
	* Create the depth stencil view
	* @return 
	*	bool Return true if successful
	*/
	bool RenderSystem::CreateDepthStencilView()
	{
		// Create and initialize a depth stencil description
		D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
		ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));

		depthStencilDesc.DepthEnable = true;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

		return true;
	}

}	// Namespace