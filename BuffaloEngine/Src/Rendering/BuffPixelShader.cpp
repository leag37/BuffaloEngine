// Filename: BuffPixelShader.cpp
// Author: Gael Huber
#include "Rendering\BuffPixelShader.h"

#include "Rendering\BuffRenderDevice.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	PixelShader::PixelShader()
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
	PixelShader::PixelShader(const std::string& fileName, const std::string& entryPoint, const RenderDevice& device)
		:	Shader(entryPoint)
	{
		std::string filePath = "Resources/Shaders/" + fileName;
		std::string profile = "ps_5_0";
		Initialize(filePath, entryPoint, profile, device);
	}

	/**
	* Initialization implementation
	* @param
	*	const RenderDevice& The device used to create the shader
	* @return
	*	bool Return true if successful
	*/
	bool PixelShader::InitializeImpl(const RenderDevice& device)
	{
		HRESULT result = device.GetD3DDevice()->CreatePixelShader(_shaderBuffer->GetBufferPointer(), _shaderBuffer->GetBufferSize(), NULL, &_shader);
		return !FAILED(result);
	}

	/**
	* Get a pointer to the shader
	* @return
	*	ID3D11PixelShader* The shader
	*/
	ID3D11PixelShader* PixelShader::GetShader() const
	{
		return _shader;
	}

}	// Namespace