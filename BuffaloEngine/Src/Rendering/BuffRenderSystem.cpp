// Filename: BuffRenderSystem.cpp
// Author: Gael Huber
#include "Rendering\BuffRenderSystem.h"

#include "Rendering\BuffConstantBuffer.h"
#include "Rendering\BuffMaterial.h"
#include "Rendering\BuffRenderComponent.h"
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

		if(CreateDepthStencilView() == false)
		{
			return false;
		}

		if(BindRenderTargets() == false)
		{
			return false;
		}

		if(CreateViewport() == false)
		{
			return false;
		}
		
		_position.x = 0.0f;
		_position.y = 0.0f;
		_position.z = -10.0f;

		_rotation.x = 0.0f;
		_rotation.y = 0.0f;
		_rotation.z = 0.0f;

		// Create the projection matrix
		float fieldOfView = (float)DirectX::XM_PI / 4.0f;
		float screenAspect = 800.0f / 600.0f;

		_camera = Camera(fieldOfView, screenAspect, 0.1f, 1000.0f);
		_camera.LookAt(0.0f, 0.0f, 1.0f);
		_camera.SetPosition(0.0f, 0.0f, -10.0f);

		_eventListener = EventListener<RenderSystem>(this);
		//_eventListener.AddEventListener(InputEvent::TYPE, &RenderSystem::OnMove);

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
		// Poll events
		while (_eventListener.Peek()) 
		{
			_eventListener.Dequeue();
		}

		// Clear color
		float color[4] = {1.0f, 1.0f, 1.0f, 1.0f};

		// Clear the back buffer to black
		_device.GetImmediateContext()->ClearRenderTargetView(_renderTargetView, color);

		// Clear the depth buffer
		_device.GetImmediateContext()->ClearDepthStencilView(_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);

		// Set the primitive topology
		_device.GetImmediateContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	}

	/**
	* Render a render queue
	* @param
	*	const RenderQueue& The render queue to process
	*/
	//void Render(const RenderQueue& renderQueue);
	void RenderSystem::Render(RenderComponent* renderable)
	{
		// Set the material as active
		Material* material = renderable->GetMaterial();
		material->SetActive(_device);

		// Create the world matrix
		DirectX::XMMATRIX worldMatrix = DirectX::XMMatrixIdentity();

		
		
		DirectX::XMMATRIX viewProjMatrix = _camera.GetViewProjMatrix();
		
		// Temp stuff
		DirectX::XMMATRIX w = DirectX::XMMatrixTranspose(worldMatrix);
		DirectX::XMMATRIX vp = DirectX::XMMatrixTranspose(viewProjMatrix);
		DirectX::XMMATRIX wvp = DirectX::XMMatrixMultiply(w, vp);

		DirectX::XMFLOAT4X4 mWorld, mViewProj;
		DirectX::XMStoreFloat4x4(&mWorld, DirectX::XMMatrixTranspose(worldMatrix));
		DirectX::XMStoreFloat4x4(&mViewProj, DirectX::XMMatrixTranspose(viewProjMatrix));

		// Map the frame values to the buffer
		material->UpdateCBufferParam("gViewProj", mViewProj);
		
		// Render the material frame requirements
		material->RenderFrame(_device);

		// Get the technique
		for (uint techniqueIndex = 0; techniqueIndex < 1; ++techniqueIndex)
		{
			const Technique& technique = material->GetTechniqueByIndex(techniqueIndex);
			
			// Iterate through each pass of the technique
			for (uint passIndex = 0; passIndex < 1; ++passIndex)
			{
				// Set the active pass
				const Pass& pass = technique.GetPassAtIndex(passIndex);

				// Activate the pass
				pass.SetActive(_device);

				// Render each object
				material->UpdateCBufferParam("gWorld", mWorld);
				material->RenderObject(_device);
				renderable->Render(_device);
			}
		}

		// Get the material's constant buffer and update its values
/*		ID3D11DeviceContext* context = _device.GetImmediateContext();
		D3D11_MAPPED_SUBRESOURCE mappedResource;
		ConstantBuffer* cb = material->GetConstantBuffer();
		ID3D11Buffer* buffer = cb->GetBuffer();

		// Lock the constant buffer so it can be written to.
		HRESULT result = context->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
		if(FAILED(result))
		{
			return;
		}

		// Get a pointer to the data in the constant buffer.
		DirectX::XMFLOAT4X4* wvpMatrix = (DirectX::XMFLOAT4X4*)mappedResource.pData;
		DirectX::XMStoreFloat4x4(wvpMatrix, worldViewProj);

		// Unmap the data
		context->Unmap(buffer, 0);

		// Update the constant buffer
		context->VSSetConstantBuffers(0, 1, &buffer);
	*/	
		// Draw indexed
		//renderable->Render(_device);
	}

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
		// Create the depth buffer description
		D3D11_TEXTURE2D_DESC depthBufferDesc;
		
		// Initialize the depth buffer description
		ZeroMemory(&depthBufferDesc, sizeof(depthBufferDesc));

		// Setup buffer descriptin
		depthBufferDesc.Width = 800;
		depthBufferDesc.Height = 600;
		depthBufferDesc.MipLevels = 1;
		depthBufferDesc.ArraySize = 1;
		depthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthBufferDesc.SampleDesc.Count = 1;
		depthBufferDesc.SampleDesc.Quality = 0;
		depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		depthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		depthBufferDesc.CPUAccessFlags = 0;
		depthBufferDesc.MipLevels = 0;

		HRESULT result = _device.GetD3DDevice()->CreateTexture2D(&depthBufferDesc, NULL, &_depthStencilBuffer);
		if(FAILED(result))
		{
			return false;
		}

		// Create and initialize a depth stencil description
		D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
		ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));		

		// Setup the stencil state
		depthStencilDesc.DepthEnable = true;
		depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;

		depthStencilDesc.StencilEnable = true;
		depthStencilDesc.StencilReadMask = 0xFF;
		depthStencilDesc.StencilWriteMask = 0xFF;

		// Stencil operations if pixel is front facing
		depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
		depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		// Stencil operations if pixel is back facing
		depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
		depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
		depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

		// Create the depth stencil state
		result = _device.GetD3DDevice()->CreateDepthStencilState(&depthStencilDesc, &_depthStencilState);
		if(FAILED(result))
		{
			return false;
		}

		// Create the depth stencil view
		D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;
		ZeroMemory(&depthStencilViewDesc, sizeof(depthStencilViewDesc));

		// Fill the description
		depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		depthStencilViewDesc.Texture2D.MipSlice = 0;

		// Create the view
		result = _device.GetD3DDevice()->CreateDepthStencilView(_depthStencilBuffer, &depthStencilViewDesc, &_depthStencilView);
		if(FAILED(result))
		{
			return false;
		}

		return true;
	}

	/**
	* Bind the render targets to the output graphics pipeline
	* @return
	*	bool True if successful
	*/
	bool RenderSystem::BindRenderTargets()
	{
		_device.GetImmediateContext()->OMSetRenderTargets(1, &_renderTargetView, _depthStencilView);
		return true;
	}

	/**
	* Create the viewport
	* @return
	*	bool True if successful
	*/
	bool RenderSystem::CreateViewport()
	{
		// Initialize the viewport description
		D3D11_VIEWPORT viewport;
		viewport.Width = 800.0f;
		viewport.Height = 600.0f;
		viewport.MinDepth = 0.0f;
		viewport.MaxDepth = 1.0f;
		viewport.TopLeftX = 0.0f;
		viewport.TopLeftY = 0.0f;

		// Create the viewport
		_device.GetImmediateContext()->RSSetViewports(1, &viewport);

		return true;
	}

	void RenderSystem::OnMove(const Event* evt)
	{
		const InputEvent* iEvt = dynamic_cast<const InputEvent*>(evt);
		if (iEvt->GetAction() == IAT_FORWARD)
		{
			_position.z += 0.001f;
		}
		else if (iEvt->GetAction() == IAT_BACKWARD)
		{
			_position.z -= 0.001f;
		}
		else if (iEvt->GetAction() == IAT_STRAFE_LEFT)
		{
			_position.x -= 0.001f;
		}
		else if (iEvt->GetAction() == IAT_STRAFE_RIGHT)
		{
			_position.x += 0.001f;
		}
		else if (iEvt->GetAction() == IAT_TURN)
		{
			_rotation.x += iEvt->GetX();
			_rotation.y += iEvt->GetY();
			_rotation.z += iEvt->GetZ();
		}
	}

}	// Namespace