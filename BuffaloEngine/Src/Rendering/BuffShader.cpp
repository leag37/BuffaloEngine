// Filename: BuffShader.cpp
// Author: Gael Huber
#include "Rendering\BuffShader.h"

#include "Rendering\BuffRenderDevice.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Shader::Shader()
		:	_name("")
	{
	}

	/**
	* Constructor
	* @param
	*	const std::string& The name of the shader
	*/
	Shader::Shader(const std::string& name)
		:	_name(name)
	{
	}

	/**
	* Destructor
	*/
	Shader::~Shader()
	{
		// Delete the shader
		if(_shaderBuffer)
		{
			_shaderBuffer->Release();
			_shaderBuffer = 0;
		}
	}

	/**
	* Get the pointer to the shader buffer
	* @param
	*	ID3D10Blob* The shader buffer
	*/
	ID3D10Blob* Shader::GetShaderBuffer() const
	{
		return _shaderBuffer;
	}

	/**
	* Initialize the shader
	* @param
	*	const std::string& The shader filename
	* @param
	*	const std::string& The shader entry point
	* @param
	*	const std::string& The shader profile for compilation
	* @param
	*	const RenderDevice& The device used to create the shader
	*/
	void Shader::Initialize(const std::string& fileName, const std::string& entryPoint, const std::string& profile, const RenderDevice& device)
	{
		ID3D10Blob* error;
		//(LPCWSTR)fileName.c_str()
		HRESULT result = D3DCompileFromFile(L"Resources/Shaders/Basic.hlsl", NULL, NULL, entryPoint.c_str(), profile.c_str(), D3DCOMPILE_ENABLE_STRICTNESS, NULL, &_shaderBuffer, &error);

		if(FAILED(result))
		{
			if(error)
			{
				OutputDebugString((char*)error->GetBufferPointer());
				error->Release();
			}

			if(_shaderBuffer)
			{
				_shaderBuffer->Release();
			}

			return;
		}

		// Create the actual shader item
		InitializeImpl(device);
	}

}	// Namespace