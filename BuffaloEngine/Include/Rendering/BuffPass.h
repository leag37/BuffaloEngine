// Filename: BuffPass.h
// Author: Gael Huber
#ifndef __BUFFPASS_H__
#define __BUFFPASS_H__

#include "Core\BuffPrerequisites.h"
#include "Rendering\BuffPixelShader.h"
#include "Rendering\BuffVertexShader.h"

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* A pass describes a single rendering pass. Each pass is tied to a a series of shaders
	* that are to be executed when rendering the pass.
	*/
	class Pass
	{
	public:
		/**
		* Default constructor
		*/
		Pass();

		/**
		* Destructor
		*/
		~Pass();

		/**
		* Set the vertex shader
		* @param
		*	VertexShader* The vertex shader for this pass
		*/
		void SetVertexShader(VertexShader* shader);

		/**
		* Get the vertex shader
		* @return
		*	VertexShader* The vertex shader
		*/
		VertexShader* GetVertexShader() const;

		/**
		* Set the pixel shader
		* @param
		*	PixelShader* The pixel shader for this pass
		*/
		void SetPixelShader(PixelShader* shader);

		/**
		* Set the pass as the active pass
		* @param
		*	const RenderDevice& The render device used to render the pass
		*/
		void SetActive(const RenderDevice& device) const;

	private:
		/**
		* Vertex shader
		*/
		VertexShader* _vertexShader;

		/**
		* Pixel shader
		*/
		PixelShader* _pixelShader;
	};

	/** @} */

}	// Namespace

#endif // __BUFFPASS_H__