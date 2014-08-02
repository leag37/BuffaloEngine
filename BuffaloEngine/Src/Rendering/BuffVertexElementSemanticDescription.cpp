// Filename: BuffVertexElementSemanticDescription.cpp
// Author: Gael Huber
#include "Rendering\BuffVertexDescription.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	VertexElementSemanticDescription::VertexElementSemanticDescription()
		: _semantic(VERTEX_ELEMENT_SEMANTIC_UNKNOWN), _name("")
	{

	}

	/**
	* Constructor given semantic type
	* @param
	*	VertexElementSemantic The semantic
	*/
	VertexElementSemanticDescription::VertexElementSemanticDescription(VertexElementSemantic semantic)
		: _semantic(semantic), _name(VertexDescription::GetSemanticName(semantic))
	{

	}

	/**
	* Copy constructor
	* @param
	*	const VertexElementSemanticDescription& The semantic description to copy
	*/
	VertexElementSemanticDescription::VertexElementSemanticDescription(const VertexElementSemanticDescription& other)
		: _semantic(other._semantic), _name(other._name)
	{

	}

	/**
	* Destructor
	*/
	VertexElementSemanticDescription::~VertexElementSemanticDescription()
	{

	}

	/**
	* Assignment operator
	* @param
	*	const VertexElementSemanticDescription& The semantic description to copy
	* @return
	*	VertexElementSemanticDescription& The assigned value
	*/
	VertexElementSemanticDescription& VertexElementSemanticDescription::operator=(const VertexElementSemanticDescription& other)
	{
		_semantic = other._semantic;
		_name = other._name;
		return *this;
	}

	/**
	* Return the semantic type
	* @return
	*	VertexElementSemantic The semantic attached to this description
	*/
	VertexElementSemantic VertexElementSemanticDescription::GetSemantic() const
	{
		return _semantic;
	}

	/**
	* Get the friendly name for this semantic
	* @return
	*	const std::string& The friendly name for the description
	*/
	const std::string& VertexElementSemanticDescription::GetName() const
	{
		return _name;
	}

}	// Namespace