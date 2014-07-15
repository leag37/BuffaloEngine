// Filename: BuffShaderParameter.h
// Author: Gael Huber
#ifndef __BUFFSHADERPARAMETER_H__
#define __BUFFSHADERPARAMETER_H__

#include "Core\BuffPrerequisites.h"

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
		SHADER_PARAMETER_TYPE_FLOAT,
		SHADER_PARAMETER_TYPE_FLOAT2,
		SHADER_PARAMETER_TYPE_FLOAT3,
		SHADER_PARAMETER_TYPE_FLOAT4,
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
		*/
		ShaderParameter(ShaderParameterType type);

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

	private:
		/**
		* The type of parameter
		*/
		ShaderParameterType _type;
	};

	/** @} */

}	// Namespace

#endif // __BUFFSHADERPARAMETER_H__