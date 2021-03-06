// Filename: BuffVertexDescription.cpp
// Author: Gael Huber
#include "Rendering\BuffVertexDescription.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	VertexDescription::VertexDescription()
	{
	}

	/**
	* Copy constructor
	* @param
	*	const VertexDescrption& The VertexDescription to copy
	*/
	VertexDescription::VertexDescription(const VertexDescription& other)
		:	_semantics(other._semantics)
	{
	}

	/**
	* Destructor
	*/
	VertexDescription::~VertexDescription()
	{
		// Clear the semantics list
		_semantics.clear();
	}

	/**
	* Assignment operator
	* @param
	*	const VertexDescrption& The VertexDescription to copy
	* @return
	*	VertexDescription& The resultant description
	*/
	VertexDescription& VertexDescription::operator=(const VertexDescription& other)
	{
		if(this == &other)
		{
			return *this;
		}

		// Clear the semantic list
		_semantics.clear();
		_semantics = other._semantics;

		return *this;
	}

	/**
	* Add a semantic to the description
	* @param
	*	VertexElementSemantic The semantic to add to the description
	*/
	void VertexDescription::AddSemantic(VertexElementSemantic semantic)
	{
		_semantics.push_back(semantic);
	}

	/**
	* Get the total size of the vertex described
	* @return
	*	int The vertex size
	*/
	int VertexDescription::GetVertexSize() const
	{
		int size = 0;
		for(std::vector<VertexElementSemantic>::const_iterator itr = _semantics.begin(); itr != _semantics.end(); ++itr)
		{
			size += GetSizeOfSemantic(*itr);
		}
		return size;
	}

	/**
	* Get the number of vertex elements semantics
	* @return
	*	int The number of vertex elements in this description
	*/
	int VertexDescription::GetNumElements() const
	{
		return _semantics.size();
	}

	/**
	* Get the size of a semantic property
	* @param
	*	VertexElementSemantic The semantic of which to get the size
	* @return
	*	int The size of the property
	*/
	int VertexDescription::GetSizeOfSemantic(VertexElementSemantic semantic)
	{

		switch(semantic)
		{
		// Color is a Vector4 value
		case VERTEX_ELEMENT_SEMANTIC_COLOR:
			return sizeof(float) * 4;

		// Position and normal are both Vector3 values
		case VERTEX_ELEMENT_SEMANTIC_POSITION:
		case VERTEX_ELEMENT_SEMANTIC_NORMAL:
			return sizeof(float) * 3;

		// Texture coordinates are Vector2 values
		case VERTEX_ELEMENT_SEMANTIC_TEXCOORD:
			return sizeof(float) * 2;

		// Failure case
		default:
			return 0;
		}
	}

	/**
	* Given a vertex element semantic, return the string representation for the name
	* @param
	*	VertexElementSemantic The semantic to name
	* @return
	*	std::string The string representation of the semantic
	*/
	std::string VertexDescription::GetSemanticName(VertexElementSemantic semantic)
	{
		switch (semantic)
		{
		case VERTEX_ELEMENT_SEMANTIC_POSITION:
			return "POSITION";

		case VERTEX_ELEMENT_SEMANTIC_NORMAL:
			return "NORMAL";

		case VERTEX_ELEMENT_SEMANTIC_TEXCOORD:
			return "TEXCOORD";

		case VERTEX_ELEMENT_SEMANTIC_COLOR:
			return "COLOR";

		default:
			return "";
		}
	}

	/**
	* Given the string representation of this vertex type, get the enum value
	* @param
	*	const std::string& The vertex type name
	* @return
	*	VertexElementType The type represented by the string
	*/
	VertexElementSemantic VertexDescription::GetSemanticType(const std::string& name)
	{
		if (name == "POSITION")
		{
			return VERTEX_ELEMENT_SEMANTIC_POSITION;
		}
		if (name == "NORMAL")
		{
			return VERTEX_ELEMENT_SEMANTIC_NORMAL;
		}
		if (name == "TEXCOORD")
		{
			return VERTEX_ELEMENT_SEMANTIC_TEXCOORD;
		}
		if (name == "COLOR")
		{
			return VERTEX_ELEMENT_SEMANTIC_COLOR;
		}

		return VERTEX_ELEMENT_SEMANTIC_UNKNOWN;
	}

}	// Namespace