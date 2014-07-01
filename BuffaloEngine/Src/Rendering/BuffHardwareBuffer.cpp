// Filename: BuffHardwareBuffer.cpp
// Author: Gael Huber
#include "Rendering\BuffHardwareBuffer.h"

namespace BuffaloEngine
{
	/**
	* Constructor
	* @param
	*	const RenderDevice& The render device used to create this buffer
	*/
	HardwareBuffer::HardwareBuffer(const RenderDevice& renderDevice)
		:	_buffer(0),
			_renderDevice(renderDevice)
	{
	}

	/**
	* Destructor
	*/
	HardwareBuffer::~HardwareBuffer()
	{
		if(_buffer)
		{
			_buffer->Release();
			_buffer = 0;
		}
	}

	/**
	* Get the represented buffer
	* @return
	*	ID3D11Buffer* The buffer 
	*/
	ID3D11Buffer* HardwareBuffer::GetBuffer() const
	{
		return _buffer;
	}

}	// Namespace
