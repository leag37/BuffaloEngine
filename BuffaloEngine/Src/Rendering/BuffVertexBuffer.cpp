// Filename: BuffVertexBuffer.cpp
// Author: Gael Huber
#include "Rendering\BuffVertexBuffer.h"

namespace BuffaloEngine
{
	/**
	* Constructor
	* @param
	*	const RenderDevice& The render device
	*/
	VertexBuffer::VertexBuffer(const RenderDevice& renderDevice)
		:	HardwareBuffer(renderDevice)
	{
	}

	/**
	* Destructor
	*/
	VertexBuffer::~VertexBuffer()
	{
	}

	/**
	* Initialize the vertex buffer
	* @param
	*	std::vector<float>& The array of vertex data
	* @param
	*	const VertexDescription& The vertex element description
	* @return
	*	bool Returns true if successfully initialized, false otherwise
	*/
	bool VertexBuffer::Initialize(std::vector<float>& data, const VertexDescription& description)
	{
		// Create the buffer description
		D3D11_BUFFER_DESC bufferDesc;
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = data.size() * sizeof(float);
		bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;
		bufferDesc.StructureByteStride = 0;

		// Initialize the buffer container for the vertex data
		D3D11_SUBRESOURCE_DATA subresource;
		subresource.pSysMem = &data[0];
		subresource.SysMemPitch = 0;
		subresource.SysMemSlicePitch = 0;

		// Create the buffer
		HRESULT result = _renderDevice.GetD3DDevice()->CreateBuffer(&bufferDesc, &subresource, &_buffer);
		return !FAILED(result);
	}

}	// Namespace