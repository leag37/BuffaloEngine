// Filename: BuffVertexBuffer.h
// Author: Gael Huber
#ifndef __BUFFVERTEXBUFFER_H__
#define __BUFFVERTEXBUFFER_H__

#include "Rendering\BuffHardwareBuffer.h"
#include "Rendering\BuffVertexDescription.h"

#include <string>
#include <vector>

namespace BuffaloEngine
{
	/**	\addtogroup Rendering
	*	@{
	*/

	/**
	* Vertex buffers contain vertex data to be put through the rendering pipeline
	*/
	class VertexBuffer : public HardwareBuffer
	{
	public:
		/**
		* Constructor
		* @param
		*	const RenderDevice& The render device
		*/
		explicit VertexBuffer(const RenderDevice& renderDevice);

		/**
		* Destructor
		*/
		~VertexBuffer();

		/**
		* Initialize the vertex buffer
		* @param
		*	std::vector<float>& The array of vertex data
		* @param
		*	const VertexDescription& The vertex element description
		* @return
		*	bool Returns true if successfully initialized, false otherwise
		*/
		bool Initialize(std::vector<float>& data, const VertexDescription& description);
	};

	/** @} */

}	// Namespace

#endif // __BUFFVERTEXBUFFER_H__