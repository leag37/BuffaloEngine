// Filename: BuffMeshSerializer.cpp
// Author: Gael Huber
#include "Rendering\BuffMeshSerializer.h"

#include "Rendering\BuffIndexBuffer.h"
#include "Rendering\BuffRenderManager.h"
#include "Rendering\BuffVertexBuffer.h"

#include <fstream>
#include <vector>

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Mesh::MeshSerializer::MeshSerializer()
	{
	}

	/**
	* Destructor
	*/
	Mesh::MeshSerializer::~MeshSerializer()
	{
	}

	/**
	* Load the mesh from a file
	* @param
	*	const std::string& The mesh filename
	* @param
	*	Mesh* The mesh to deserialize
	* @return
	*	bool Returns true if deserialization was successful
	*/
	bool Mesh::MeshSerializer::Deserialize(const std::string& meshName, Mesh* mesh)
	{
		// Build the filepath and open the file
		std::string filePath = "Resources/Mesh/" + meshName + ".mesh";
		std::fstream file;
		file.open(filePath.c_str(), std::ios::in | std::ios::binary);
		if(file.fail())
		{
			// The file could not be opened, so return false
			return false;
		}

		// Read in the mesh file header
		MeshFileHeader header;
		file.read((char*)&header, sizeof(MeshFileHeader));

		// Check for valid signature
		if(header.sig[0] != 'b' || header.sig[1] != 'e')
		{
			file.close();
			return false;
		}

		// Read in the vertex semantics
		VertexDescription vertexDescription;
		for(int i = 0; i < header.vertexElements; ++i)
		{
			VertexElementSemantic semantic;
			file.read((char*)&semantic, sizeof(VertexElementSemantic));
			vertexDescription.AddSemantic(semantic);
		}
		mesh->_vertexDescription = vertexDescription;

		// Read in vertex data
		int test = header.vertexCount * vertexDescription.GetVertexSize();
		std::vector<float> vertexData = std::vector<float>(header.vertexCount * vertexDescription.GetVertexSize());
		file.read((char*)&vertexData[0], vertexData.capacity());

		// Create a vertex buffer
		VertexBuffer* vertexBuffer = RenderManager::GetSingletonPtr()->CreateVertexBuffer();
		if(vertexBuffer->Initialize(vertexData, vertexDescription) == false)
		{
			return false;
		}
		mesh->_vertexBuffer = vertexBuffer;

		// Read in index data
		std::vector<int> indexData = std::vector<int>(header.indexCount * sizeof(int));
		file.read((char*)&indexData[0], indexData.capacity());

		// Create an index buffer
		IndexBuffer* indexBuffer = RenderManager::GetSingletonPtr()->CreateIndexBuffer();
		if(indexBuffer->Initialize(indexData) == false)
		{
			return false;
		}
		mesh->_indexBuffer = indexBuffer;

		return true;
	}

}	// Namespace