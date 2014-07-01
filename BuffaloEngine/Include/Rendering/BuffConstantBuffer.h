// Filename: BuffConstantBuffer.h
// Author: Gael Huber
#ifndef __BUFFCONSTANTBUFFER_H__
#define __BUFFCONSTANTBUFFER_H__

#include "Core\BuffPrerequisites.h"
#include "Rendering\BuffHardwareBuffer.h"

#include <string>

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	class ConstantBuffer : public HardwareBuffer
	{
	public:
		/**
		* Default constructor
		*/
		ConstantBuffer();

		/**
		* Constructor
		* @param
		*	const std::string& The name of the constant buffer
		*/
		ConstantBuffer(const std::string& name);

		/**
		* Destructor
		*/
		~ConstantBuffer();

	private:

	};

	/**
	* Shared pointer for hardware buffers
	*/
	class ConstantBufferPtr : public HardwareBufferPtr
	{
		/**
		* Constructor
		* @param
		*	ConstantBuffer* The pointer to the constant buffer
		*/
		ConstantBufferPtr(ConstantBuffer* ptr);

		/**
		* Destructor
		*/
		~ConstantBufferPtr();
	};

	/** @} */

}	// Namespace

#endif // __BUFFCONSTANTBUFFER_H__