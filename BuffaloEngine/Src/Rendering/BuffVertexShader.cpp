// Filename: BuffVertexShader.cpp
// Author: Gael Huber
#include "Rendering\BuffVertexShader.h"

#include "Rendering\BuffRenderDevice.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	VertexShader::VertexShader()
		:	Shader()
	{
	}

	/**
	* Constructor
	* @param
	*	const std::string& The name of the shader
	* @param
	*	const std::string& The entry point of the shader
	* @param
	*	const RenderDevice& The device used to create the shader
	*/
	VertexShader::VertexShader(const std::string& fileName, const std::string& entryPoint, const RenderDevice& device)
		:	Shader(entryPoint)
	{
		std::string filePath = "Resources/Shaders/" + fileName;
		std::string profile = "vs_5_0";
		Initialize(filePath, entryPoint, profile, device);
	}

	/**
	* Initialization implementation
	* @param
	*	const RenderDevice& The device used to create the shader
	* @return
	*	bool Return true if successful
	*/
	bool VertexShader::InitializeImpl(const RenderDevice& device)
	{
		HRESULT result = device.GetD3DDevice()->CreateVertexShader(_shaderBuffer->GetBufferPointer(), _shaderBuffer->GetBufferSize(), NULL, &_shader);
		return !FAILED(result);
	}

	/**
	* Get a pointer to the shader
	* @return
	*	ID3D11VertexShader* The shader
	*/
	ID3D11VertexShader* VertexShader::GetShader() const
	{
		return _shader;
	}

}	// Namespace