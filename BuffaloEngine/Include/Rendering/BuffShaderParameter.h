// Filename: BuffShaderParameter.h
// Author: Gael Huber
#ifndef __BUFFSHADERPARAMETER_H__
#define __BUFFSHADERPARAMETER_H__

#include "Core\BuffPrerequisites.h"

#include <string>

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* An enumeration describing the various shader parameter types
	*/
	enum ShaderParameterType
	{
		SHADER_PARAMETER_TYPE_UNKNOWN,
		SHADER_PARAMETER_TYPE_FLOAT,
		SHADER_PARAMETER_TYPE_FLOAT2,
		SHADER_PARAMETER_TYPE_FLOAT3,
		SHADER_PARAMETER_TYPE_FLOAT4,
		SHADER_PARAMETER_TYPE_LIGHT,
		SHADER_PARAMETER_TYPE_MATRIX
	};

	/**
	* A description of a shader parameter
	*/
	class ShaderParameter
	{
	public:
		/**
		* Default constructor
		*/
		ShaderParameter();

		/**
		* Constructor
		* @param
		*	ShaderParameterType The type of shader parameter
		* @param
		*	const std::string& The parameter name
		*/
		ShaderParameter(ShaderParameterType type, const std::string& name);

		/**
		* Copy constructor
		* @param
		*	const ShaderParameter& The parameter to copy
		*/
		ShaderParameter(const ShaderParameter& other);

		/**
		* Destructor
		*/
		~ShaderParameter();

		/**
		* Assignment operator
		* @param
		*	const ShaderParameter& The parameter to copy
		* @return
		*	ShaderParameter& The resultant parameter
		*/
		ShaderParameter& operator=(const ShaderParameter& other);

		/**
		* Retrieve the DXGI_FORMAT for this shader parameter
		* @return
		*	DXGI_FORMAT The format for the parameter
		*/
		DXGI_FORMAT GetFormat() const;

		/**
		* Get the parameter type
		* @return
		*	ShaderParameterType The parameter type for this shader parameter
		*/
		ShaderParameterType GetParameterType() const;

		/**
		* Get the parameter name
		* @return
		*	const std::string& The friendly name of the parameter
		*/
		const std::string& GetName() const;

		/**
		* Set the byte offset for this parameter
		* @return
		*	uint The byte offset for this parameter
		*/
		uint GetByteOffset() const;

		/**
		* Set the byte offset for this parameter
		* @param
		*	uint The byte offset for this parameter
		*/
		void SetByteOffset(uint offset);

		/**
		* Return the size in bytes of this parameter
		* @return
		*	uint The size of the parameter in bytes
		*/
		uint GetSize() const;


	public:
		/**
		* Given the string representation of this parameter type, get the enum value
		* @param
		*	const std::string& The parameter name
		* @return
		*	ShaderParameterType The type represented by the string
		*/
		static ShaderParameterType GetParameterType(const std::string& name);

		/**
		* Given a parameter type, return the size of the parameter
		* @param
		*	ShaderParameterType The parameter of which to find the size
		* @return
		*	uint The size of the parameter
		*/
		static uint GetSizeForParameter(ShaderParameterType type);

	private:
		/**
		* The type of parameter
		*/
		ShaderParameterType _type;

		/**
		* The parameter name
		*/
		std::string _name;

		/**
		* The byte offset for this parameter
		*/
		uint _byteOffset;

		/**
		* The size of this parameter in bytes
		*/
		uint _size;
	};

	/** @} */

}	// Namespace

#endif // __BUFFSHADERPARAMETER_H__