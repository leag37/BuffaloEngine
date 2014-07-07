// Filename: BuffMesh.h
// Author: Gael Huber
#ifndef __BUFFMESH_H__
#define __BUFFMESH_H__

#include "Core\BuffPrerequisites.h"

#include "Rendering\BuffVertexDescription.h"

#include <string>

namespace BuffaloEngine
{
	// Forward declarations
	class IndexBuffer;
	class RenderDevice;
	class VertexBuffer;

	/**	\addtogroup Rendering
	*	@{
	*/

	/**
	* Mesh represents the geometric data for an object
	*/
	class Mesh
	{
	public:
		/**
		* Mesh serializer class
		*/
		class MeshSerializer;

	public:
		/**
		* Default constructor
		*/
		Mesh();

		/**
		* Constructor
		* @param
		*	const std::string& The mesh name
		*/
		Mesh(const std::string& name);

		/**
		* Destructor
		*/
		~Mesh();

		/**
		* Destroy the mesh
		*/
		void Destroy();

		/**
		* Render the mesh
		* @param
		*	const RenderDevice& device
		*/
		void Render(const RenderDevice device);

	private:
		/**
		* The name of the mesh
		*/
		std::string _name;

		/**
		* Vertex buffer
		*/
		VertexBuffer* _vertexBuffer;

		/**
		* Index buffer
		*/
		IndexBuffer* _indexBuffer;

		/**
		* The vertex description for this mesh
		*/
		VertexDescription _vertexDescription;
	};

	/** @} */

}	// Namespace

#endif // __BUFFMESH_H__