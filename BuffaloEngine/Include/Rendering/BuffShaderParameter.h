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

	/** @} */

}	// Namespace

#endif // __BUFFSHADERPARAMETER_H__