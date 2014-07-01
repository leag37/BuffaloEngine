// Filename: BuffVertexDescription.h
// Author: Gael Huber
#ifndef __BUFFVERTEXDESCRIPTION_H__
#define __BUFFVERTEXDESCRIPTION_H__

#include "Core\BuffPrerequisites.h"

#include <vector>

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* Vertex element semantics
	*/
	enum VertexElementSemantic
	{
		VERTEX_ELEMENT_SEMANTIC_POSITION,
		VERTEX_ELEMENT_SEMANTIC_NORMAL,
		VERTEX_ELEMENT_SEMANTIC_TEXCOORD
	};

	/**
	* Describes a vertex and it's various properties
	*/
	class VertexDescription : public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		VertexDescription();

		/**
		* Copy constructor
		* @param
		*	const VertexDescrption& The VertexDescription to copy
		*/
		VertexDescription(const VertexDescription& other);

		/**
		* Destructor
		*/
		~VertexDescription();

		/**
		* Assignment operator
		* @param
		*	const VertexDescrption& The VertexDescription to copy
		* @return
		*	VertexDescription& The resultant description
		*/
		VertexDescription& operator=(const VertexDescription& other);

		/**
		* Add a semantic to the description
		* @param
		*	VertexElementSemantic The semantic to add to the description
		*/
		void AddSemantic(VertexElementSemantic semantic);

		/**
		* Get the total size of the vertex described
		* @return
		*	int The vertex size
		*/
		int GetVertexSize() const;

		/**
		* Get the number of vertex elements semantics
		* @return
		*	int The number of vertex elements in this description
		*/
		int GetNumElements() const;

		/**
		* Get the size of a semantic property
		* @param
		*	VertexElementSemantic The semantic of which to get the size
		* @return
		*	int The size of the property
		*/
		static int GetSizeOfSemantic(VertexElementSemantic semantic);

	private:
		/**
		* List of vertex semantics
		*/
		std::vector<VertexElementSemantic> _semantics;
	};

	/** @} */

}	// Namespace

#endif // __BUFFVERTEXDESCRIPTION_H__