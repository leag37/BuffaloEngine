// Filename: BuffInputLayoutParameter.cpp
// Author: Gael Huber
#include "Rendering\BuffInputLayoutParameter.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	InputLayoutParameter::InputLayoutParameter()
	{

	}

	/**
	* Constructor
	* @param
	*	const ShaderParameter& The shader parameter for this input layout
	* @param
	*	VertexElementSemantic The semantic for this input layout
	*/
	InputLayoutParameter::InputLayoutParameter(const ShaderParameter& param, VertexElementSemantic semantic)
		:	_parameter(param),
			_semantic(semantic)
	{

	}

	/**
	* Copy constructor
	*	const InputLayoutParameter& The input layout parameter to copy
	*/
	InputLayoutParameter::InputLayoutParameter(const InputLayoutParameter& other)
		:	_parameter(other._parameter),
			_semantic(other._semantic)
	{

	}

	/**
	* Destructor
	*/
	InputLayoutParameter::~InputLayoutParameter()
	{

	}

	/**
	* Assignment operator
	* @param
	*	const InputLayoutParameter& The input layout parameter to copy
	* @param
	*	InputLayoutParameter& The copied parameter
	*/
	InputLayoutParameter& InputLayoutParameter::operator=(const InputLayoutParameter& other)
	{
		_parameter = other._parameter;
		_semantic = other._semantic;
		return *this;
	}

}	// Namespace