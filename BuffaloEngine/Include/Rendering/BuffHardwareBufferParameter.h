// Filename: BuffHardwareBufferParameter.h
// Author: Gael Huber
#ifndef __BUFFHARDWAREBUFFERPARAMETER_H__
#define __BUFFHARDWAREBUFFERPARAMETER_H__

#include "Core\BuffPrerequisites.h"

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* An enumeration detailing all the different hardware buffer parameters
	*/
	enum HardwareBufferParameterType
	{
		FLOAT,
		FLOAT2,
		FLOAT3,
		FLOAT4,
		FLOAT3x3,
		FLOAT4x4,
		TEXTURE,
		SAMPLERSTATE
	};

	/**
	* Contains the description for a shader parameter
	*/
	class HardwareBufferParameter
	{
	public:

	private:

	};

	/** @} */

}	// Namespace

#endif // __BUFFHARDWAREBUFFERPARAMETER_H__