// Filename: BuffMeshSerializer.h
// Author: Gael Huber
#ifndef __BUFFMESHSERIALIZER_H__
#define __BUFFMESHSERIALIZER_H__

#include "Core\BuffPrerequisites.h"
#include "Rendering\BuffMesh.h"

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* File header for .MESH file extension
	*/
	struct MeshFileHeader
	{
		char sig[2];
		int vertexCount;
		int vertexElements;
		int indexCount;
	};

	/**
	* Mesh serializer class
	*/
	class Mesh::MeshSerializer
	{
	public:
		/**
		* Default constructor
		*/
		MeshSerializer();

		/**
		* Destructor
		*/
		~MeshSerializer();

		/**
		* Load the mesh from a file
		* @param
		*	const std::string& The mesh filename
		* @param
		*	Mesh* The mesh to deserialize
		* @return
		*	bool Returns true if deserialization was successful
		*/
		bool Deserialize(const std::string& meshName, Mesh* mesh);
	};

	/** @} */

}	// Namespace

#endif // __BUFFMESHSERIALIZER_H__