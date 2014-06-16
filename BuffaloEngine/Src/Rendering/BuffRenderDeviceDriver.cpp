// Filename: BuffRenderDeviceDriver.cpp
// Author: Gael Huber
#include "Rendering\BuffRenderDeviceDriver.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	RenderDeviceDriver::RenderDeviceDriver()
		:	_adapter(0)
	{

	}

	/**
	* Constructor
	* @param
	*	IDXGIAdapter* The adapter representing this driver
	*/
	RenderDeviceDriver::RenderDeviceDriver(IDXGIAdapter* adapter)
		:	_adapter(adapter)
	{
		_adapter->GetDesc(&_adapterDescription);
	}

	/**
	* Copy constructor
	* @param
	*	const RenderDeviceDriver& The driver to copy
	*/
	RenderDeviceDriver::RenderDeviceDriver(const RenderDeviceDriver& other)
		:	_adapter(other._adapter),
			_adapterDescription(other._adapterDescription)
	{

	}

	/**
	* Destructor
	*/
	RenderDeviceDriver::~RenderDeviceDriver()
	{
	}

	/**
	* Assignment operator
	* @param
	*	const RenderDeviceDriver& The driver to copy
	* @return
	*	RenderDeviceDriver& The resultant driver
	*/
	RenderDeviceDriver& RenderDeviceDriver::operator=(const RenderDeviceDriver& other)
	{
		_adapter = other._adapter;
		_adapterDescription = other._adapterDescription;
		return *this;
	}

	/**
	* Get the adpater for the driver
	* @return
	*	const IDXGIAdapter* The adapter attached to this driver
	*/
	IDXGIAdapter* RenderDeviceDriver::GetAdapter() const
	{
		return _adapter;
	}

}	// Namespace