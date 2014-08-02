// Filename: BuffMesh.cpp
// Author: Gael Huber
#include "Rendering\BuffMesh.h"

#include "Rendering\BuffIndexBuffer.h"
#include "Rendering\BuffMeshSerializer.h"
#include "Rendering\BuffVertexBuffer.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Mesh::Mesh()
		:	_name(""),
			_vertexBuffer(0),
			_indexBuffer(0)
	{
	}

	/**
	* Constructor
	* @param
	*	const std::string& The mesh name
	*/
	Mesh::Mesh(const std::string& name)
		:	_name(name),
			_vertexBuffer(0),
			_indexBuffer(0)
	{
		MeshSerializer serializer;
		if(serializer.Deserialize(name, this) == false)
		{
			Destroy();
		}
	}

	/**
	* Destructor
	*/
	Mesh::~Mesh()
	{
		// Destroy the mesh
		Destroy();
	}

	/**
	* Destroy the mesh
	*/
	void Mesh::Destroy()
	{
		// Clear the vertex buffer
		if(_vertexBuffer != 0)
		{
			delete _vertexBuffer;
			_vertexBuffer = 0;
		}

		// Clear the index buffer
		if(_indexBuffer != 0)
		{
			delete _indexBuffer;
			_indexBuffer = 0;
		}
	}

	/**
	* Render the mesh
	* @param
	*	const RenderDevice& device
	*/
	void Mesh::Render(const RenderDevice device)
	{
		// Get the context
		ID3D11DeviceContext* context = device.GetImmediateContext();

		// Set and render the buffers
		ID3D11Buffer *vertexBuffer, *indexBuffer;
		uint stride, offset;
		
		vertexBuffer = _vertexBuffer->GetBuffer();
		indexBuffer = _indexBuffer->GetBuffer();
		stride = _vertexDescription.GetVertexSize();
		offset = 0;
		context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		context->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
		context->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
		context->DrawIndexed(_vertexBuffer->GetNumVertices(), 0, 0);
	}

}	// Namespace