// Filename: BuffHardwareBuffer.h
// Author: Gael Huber
#ifndef __BUFFHARDWAREBUFFER_H__
#define __BUFFHARDWAREBUFFER_H__

#include "Core\BuffPrerequisites.h"
#include "BuffRenderDevice.h"

namespace BuffaloEngine
{
	/**	\addtogroup Rendering
	*	@{
	*/

	/**
	* Hardware buffers refer to buffered data kept within GPU memory, such as vertex buffers, constant buffers, etc
	*/
	class HardwareBuffer
	{
	public:
		/**
		* Constructor
		* @param
		*	const RenderDevice& The render device used to create this buffer
		*/
		explicit HardwareBuffer(const RenderDevice& renderDevice);

		/**
		* Destructor
		*/
		virtual ~HardwareBuffer();

		/**
		* Get the represented buffer
		* @return
		*	ID3D11Buffer* The buffer 
		*/
		ID3D11Buffer* GetBuffer() const;

	protected:
		/**
		* The hardware buffer
		*/
		ID3D11Buffer* _buffer;

		/**
		* The render device used to create the buffer
		*/
		const RenderDevice& _renderDevice;
	};

	/**
	* Shared pointer for hardware buffers
	*/
	class HardwareBufferPtr : public SharedPtr<HardwareBuffer>
	{
		/**
		* Constructor
		* @param
		*	HardwareBuffer* The pointer to the hardware buffer
		*/
		HardwareBufferPtr(HardwareBuffer* ptr);

		/**
		* Destructor
		*/
		virtual ~HardwareBufferPtr();
	};

	/** @} */

}	// Namespace

#endif // __BUFFHARDWAREBUFFER_H__