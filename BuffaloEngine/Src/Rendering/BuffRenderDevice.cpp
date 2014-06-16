// Filename: BuffRenderDevice.cpp
// Author: Gael Huber
#include "Rendering\BuffRenderDevice.h"
#include "Rendering\BuffRenderDeviceDriver.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	RenderDevice::RenderDevice()
		:	_device(0),
			_immediateContext(0)
	{

	}

	/**
	* Destructor
	*/
	RenderDevice::~RenderDevice()
	{

	}

	/**
	* Create the device given the driver information
	* @param
	*	const RenderDeviceDriver& The driver used to create this device
	*/
	bool RenderDevice::Initialize(const RenderDeviceDriver& driver)
	{
		// Target level list
		D3D_FEATURE_LEVEL targetFeatureLevels[] = 
		{
			D3D_FEATURE_LEVEL_11_0
		};
		
		// The number of feature levels
		uint numFeatureLevels = sizeof(targetFeatureLevels) / sizeof(D3D_FEATURE_LEVEL);

		HRESULT result;
		result = D3D11CreateDevice(
			driver.GetAdapter(),
			D3D_DRIVER_TYPE_UNKNOWN,
			0,
			0,
			targetFeatureLevels,
			numFeatureLevels,
			D3D11_SDK_VERSION,
			&_device,
			&_featureLevel,
			&_immediateContext);
		
		if(FAILED(result))
		{
			return false;
		}
		return true;
	}

	/**
	* Shutdown the device
	*/
	void RenderDevice::Shutdown()
	{
		// Free the device
		if(_device != 0)
		{
			_device->Release();
			_device = 0;
			_immediateContext = 0;
		}
	}

	/**
	* Get the direct3D device
	* @return
	*	ID3D11Device* The d3d device
	*/
	ID3D11Device* RenderDevice::GetD3DDevice() const
	{
		return _device;
	}

	/**
	* Get the device context
	* @return
	*	ID3D11DeviceContext* The device context
	*/
	ID3D11DeviceContext* RenderDevice::GetImmediateContext() const
	{
		return _immediateContext;
	}

}	// Namespace
