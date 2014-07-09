// Filename: BuffConstantBuffer.cpp
// Author: Gael Huber
#include "Rendering\BuffConstantBuffer.h"

namespace BuffaloEngine
{
	/**
	* Constructor
	* @param
	*	const RenderDevice& The render device
	*/
	ConstantBuffer::ConstantBuffer(const RenderDevice& renderDevice)
		:	HardwareBuffer(renderDevice)
	{
	}

	/**
	* Destructor
	*/
	ConstantBuffer::~ConstantBuffer()
	{
	}

	/**
	* Initialize the buffer
	* @return
	*	bool Returns true if successfully initialized
	*/
	bool ConstantBuffer::Initialize()
	{
		D3D11_BUFFER_DESC cbDesc;
		cbDesc.ByteWidth = sizeof(DirectX::XMFLOAT4X4);
		cbDesc.Usage = D3D11_USAGE_DYNAMIC;
		cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		cbDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		cbDesc.MiscFlags = 0;
		cbDesc.StructureByteStride = 0;

		HRESULT result = _renderDevice.GetD3DDevice()->CreateBuffer(&cbDesc, NULL, &_buffer);

		return !FAILED(result);
	}

}