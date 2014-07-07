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
		* Constructor
		* @param
		*	const RenderDevice& The render device
		*/
		explicit ConstantBuffer(const RenderDevice& renderDevice);

		/**
		* Destructor
		*/
		~ConstantBuffer();

		/**
		* Initialize the buffer
		* @return
		*	bool Returns true if successfully initialized
		*/
		bool Initialize();

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