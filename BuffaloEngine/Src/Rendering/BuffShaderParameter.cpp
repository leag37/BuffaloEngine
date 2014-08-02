// Filename: BuffShaderParameter.cpp
// Author: Gael Huber
#include "Rendering\BuffShaderParameter.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	ShaderParameter::ShaderParameter()
	{

	}

	/**
	* Constructor
	* @param
	*	ShaderParameterType The type of shader parameter
	* @param
	*	const std::string& The parameter name
	*/
	ShaderParameter::ShaderParameter(ShaderParameterType type, const std::string& name)
		:	_type(type),
			_name(name),
			_byteOffset(0),
			_size(0)
	{
		_size = GetSizeForParameter(type);
	}

	/**
	* Copy constructor
	* @param
	*	const ShaderParameter& The parameter to copy
	*/
	ShaderParameter::ShaderParameter(const ShaderParameter& other)
		:	_type(other._type),
			_name(other._name),
			_byteOffset(other._byteOffset),
			_size(other._size)
	{

	}

	/**
	* Destructor
	*/
	ShaderParameter::~ShaderParameter()
	{

	}

	/**
	* Assignment operator
	* @param
	*	const ShaderParameter& The parameter to copy
	* @return
	*	ShaderParameter& The resultant parameter
	*/
	ShaderParameter& ShaderParameter::operator=(const ShaderParameter& other)
	{
		_type = other._type;
		_name = other._name;
		_byteOffset = other._byteOffset;
		_size = other._size;
		return *this;
	}

	/**
	* Retrieve the DXGI_FORMAT for this shader parameter
	* @return
	*	DXGI_FORMAT The format for the parameter
	*/
	DXGI_FORMAT ShaderParameter::GetFormat() const
	{
		switch (_type)
		{
		case SHADER_PARAMETER_TYPE_FLOAT:
			return DXGI_FORMAT_R32_FLOAT;

		case SHADER_PARAMETER_TYPE_FLOAT2:
			return DXGI_FORMAT_R32G32_FLOAT;

		case SHADER_PARAMETER_TYPE_FLOAT3:
			return DXGI_FORMAT_R32G32B32_FLOAT;

		case SHADER_PARAMETER_TYPE_FLOAT4:
			return DXGI_FORMAT_R32G32B32A32_FLOAT;

		default:
			return DXGI_FORMAT_UNKNOWN;
		}
	}

	/**
	* Get the parameter type
	* @return
	*	ShaderParameterType The parameter type for this shader parameter
	*/
	ShaderParameterType ShaderParameter::GetParameterType() const
	{
		return _type;
	}

	/**
	* Get the parameter name
	* @return
	*	const std::string& The friendly name of the parameter
	*/
	const std::string& ShaderParameter::GetName() const
	{
		return _name;
	}

	/**
	* Set the byte offset for this parameter
	* @return
	*	uint The byte offset for this parameter
	*/
	uint ShaderParameter::GetByteOffset() const
	{
		return _byteOffset;
	}

	/**
	* Set the byte offset for this parameter
	* @param
	*	uint The byte offset for this parameter
	*/
	void ShaderParameter::SetByteOffset(uint offset)
	{
		_byteOffset = offset;
	}

	/**
	* Return the size in bytes of this parameter
	* @return
	*	uint The size of the parameter in bytes
	*/
	uint ShaderParameter::GetSize() const
	{
		return _size;
	}

	/**
	* Given the string representation of this parameter type, get the enum value
	* @param
	*	const std::string& The parameter name
	* @return
	*	ShaderParameterType The type represented by the string
	*/
	ShaderParameterType ShaderParameter::GetParameterType(const std::string& name)
	{
		if (name == "Float")
		{
			return SHADER_PARAMETER_TYPE_FLOAT;
		}
		if (name == "Float2")
		{
			return SHADER_PARAMETER_TYPE_FLOAT2;
		}
		if (name == "Float3")
		{
			return SHADER_PARAMETER_TYPE_FLOAT3;
		}
		if (name == "Float4")
		{
			return SHADER_PARAMETER_TYPE_FLOAT4;
		}
		if (name == "Matrix")
		{
			return SHADER_PARAMETER_TYPE_MATRIX;
		}

		return SHADER_PARAMETER_TYPE_UNKNOWN;
	}

	/**
	* Given a parameter type, return the size of the parameter
	* @param
	*	ShaderParameterType The parameter of which to find the size
	* @return
	*	uint The size of the parameter
	*/
	uint ShaderParameter::GetSizeForParameter(ShaderParameterType type)
	{
		switch (type)
		{
		case SHADER_PARAMETER_TYPE_FLOAT:
			return sizeof(float);

		case SHADER_PARAMETER_TYPE_FLOAT2:
			return sizeof(float) * 2;

		case SHADER_PARAMETER_TYPE_FLOAT3:
			return sizeof(float) * 3;

		case SHADER_PARAMETER_TYPE_FLOAT4:
			return sizeof(float) * 4;

		case SHADER_PARAMETER_TYPE_MATRIX:
			return sizeof(float) * 16;

		default:
			return 0;
		}
	}

}	// Namespace