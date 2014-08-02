// Filename: BuffVertexShader.h
// Author: Gael Huber
#ifndef __BUFFVERTEXSHADER_H__
#define __BUFFVERTEXSHADER_H__

#include "Core\BuffPrerequisites.h"
#include "Rendering\BuffShader.h"

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	class VertexShader : public Shader
	{
	public:
		/**
		* Default constructor
		*/
		VertexShader();

		/**
		* Constructor
		* @param
		*	const std::string& The file name of the shader
		* @param
		*	const std::string& The entry point of the shader
		* @param
		*	const RenderDevice& The device used to create the shader
		*/
		VertexShader(const std::string& fileName, const std::string& entryPoint,  const RenderDevice& device);

		/**
		* Get a pointer to the shader
		* @return
		*	ID3D11VertexShader* The shader
		*/
		ID3D11VertexShader* GetShader() const;

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
		* The vertex shader
		*/
		ID3D11VertexShader* _shader;
	};

	/** @} */

}	// Namespace

#endif // __BUFFVERTEXSHADER_H__