// Filename: BuffVertexDescription.h
// Author: Gael Huber
#ifndef __BUFFVERTEXDESCRIPTION_H__
#define __BUFFVERTEXDESCRIPTION_H__

#include "Core\BuffPrerequisites.h"

#include <string>
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
		VERTEX_ELEMENT_SEMANTIC_UNKNOWN,
		VERTEX_ELEMENT_SEMANTIC_POSITION,
		VERTEX_ELEMENT_SEMANTIC_NORMAL,
		VERTEX_ELEMENT_SEMANTIC_TEXCOORD,
		VERTEX_ELEMENT_SEMANTIC_COLOR
	};

	/**
	* Description for a vertex element semantic. This contains some simple data about the semantic type
	* and the corresponding semantic name
	*/
	class VertexElementSemanticDescription : public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		VertexElementSemanticDescription();

		/**
		* Constructor given semantic type
		* @param
		*	VertexElementSemantic The semantic
		*/
		VertexElementSemanticDescription(VertexElementSemantic semantic);

		/**
		* Copy constructor
		* @param
		*	const VertexElementSemanticDescription& The semantic description to copy
		*/
		VertexElementSemanticDescription(const VertexElementSemanticDescription& other);

		/**
		* Destructor
		*/
		~VertexElementSemanticDescription();

		/**
		* Assignment operator
		* @param
		*	const VertexElementSemanticDescription& The semantic description to copy
		* @return
		*	VertexElementSemanticDescription& The assigned value
		*/
		VertexElementSemanticDescription& operator=(const VertexElementSemanticDescription& other);

		/**
		* Return the semantic type
		* @return
		*	VertexElementSemantic The semantic attached to this description
		*/
		VertexElementSemantic GetSemantic() const;

		/**
		* Get the friendly name for this semantic
		* @return
		*	const std::string& The friendly name for the description
		*/
		const std::string& GetName() const;

	private:
		/**
		* The semantic type
		*/
		VertexElementSemantic _semantic;

		/**
		* Friendly name for the semantic
		*/
		std::string _name;
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

		/**
		* Given a vertex element semantic, return the string representation for the name
		* @param
		*	VertexElementSemantic The semantic to name
		* @return
		*	std::string The string representation of the semantic
		*/
		static std::string GetSemanticName(VertexElementSemantic semantic);

		/**
		* Given the string representation of this vertex type, get the enum value
		* @param
		*	const std::string& The vertex type name
		* @return
		*	VertexElementType The type represented by the string
		*/
		static VertexElementSemantic GetSemanticType(const std::string& name);

	private:
		/**
		* List of vertex semantics
		*/
		std::vector<VertexElementSemantic> _semantics;
	};

	
	/** @} */

}	// Namespace

#endif // __BUFFVERTEXDESCRIPTION_H__