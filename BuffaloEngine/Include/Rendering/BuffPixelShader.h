// Filename: BuffPixelShader.h
// Author: Gael Huber
#ifndef __BUFFPIXELSHADER_H__
#define __BUFFPIXELSHADER_H__

#include "Core\BuffPrerequisites.h"
#include "Rendering\BuffShader.h"

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	class PixelShader : public Shader
	{
	public:
		/**
		* Default constructor
		*/
		PixelShader();

		/**
		* Constructor
		* @param
		*	const std::string& The name of the shader
		* @param
		*	const RenderDevice& The device used to create the shader
		*/
		PixelShader(const std::string& name, const RenderDevice& device);

		/**
		* Get a pointer to the shader
		* @return
		*	ID3D11PixelShader* The shader
		*/
		ID3D11PixelShader* GetShader() const;

	protected:
		/**
		* Initialization implementation
		* @param
		*	const RenderDevice& The device used to create the shader
		* @return
		*	bool Return true if successful
		*/
		bool InitializeImpl(const RenderDevice& device);

	private:
		/**
		* The pixel shader
		*/
		ID3D11PixelShader* _shader;
	};

	/** @} */

}	// Namespace

#endif // __BUFFPIXELSHADER_H__