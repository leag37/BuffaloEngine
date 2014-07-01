// Filename: BuffIndexBuffer.h
// Author: Gael Huber
#ifndef __BUFFINDEXBUFFER_H__
#define __BUFFINDEXBUFFER_H__

#include "Rendering\BuffHardwareBuffer.h"
#include "Rendering\BuffVertexDescription.h"

#include <vector>

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	class IndexBuffer : public HardwareBuffer
	{
	public:
		/**
		* Constructor
		* @param
		*	const RenderDevice& The render device
		*/
		explicit IndexBuffer(const RenderDevice& renderDevice);

		/**
		* Destructor
		*/
		~IndexBuffer();

		/**
		* Initialize the index buffer
		* @param
		*	std::vector<int>& The array of vertex data
		* @return
		*	bool Returns true if successfully initialized, false otherwise
		*/
		bool Initialize(std::vector<int>& data);
	};

	/** @} */

}	// Namespace

#endif // __BUFFINDEXBUFFER_H__