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
			_semantic(VertexElementSemanticDescription(semantic))
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

	/**
	* Get the Direct3D element description for this parameter
	* @param
	*	D3D11_INPUT_ELEMENT_DESC The input element description for this parameter
	*/
	D3D11_INPUT_ELEMENT_DESC InputLayoutParameter::GetElementDesc() const
	{
		// Fill in the description and return it
		D3D11_INPUT_ELEMENT_DESC desc;
		desc.AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
		desc.Format = _parameter.GetFormat();
		desc.InputSlot = 0;
		desc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		desc.InstanceDataStepRate = 0;
		desc.SemanticIndex = 0;
		desc.SemanticName = (LPCSTR)(_semantic.GetName().c_str());
		return desc;
	}

}	// Namespace