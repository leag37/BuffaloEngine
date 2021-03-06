// Filename: BuffMaterial.cpp
// Author: Gael Huber
#include "Rendering\BuffMaterial.h"

#include "Rendering\BuffConstantBuffer.h"
#include "Rendering\BuffMaterialReader.h"
#include "Rendering\BuffPixelShader.h"
#include "Rendering\BuffRenderDevice.h"
#include "Rendering\BuffRenderManager.h"
#include "Rendering\BuffVertexShader.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Material::Material()
	{
	}

	/**
	* Constructor
	* @param
	*	const std::string& The name of the material
	*/
	Material::Material(const std::string& name)
		:	_name(name)
	{
	}

	/**
	* Initialize the material
	* @param
	*	const RenderDevice& The render device
	*/
	void Material::Initialize(const RenderDevice& device)
	{
		// Deserialize the material
		MaterialReader reader;
		reader.Read(this);

		// Initialize the technique
		//_technique.Initialize(device);

		// Initialize the input layout
		_inputLayout.Initialize(device, _technique.GetPassAtIndex(0).GetVertexShader()->GetShaderBuffer());

		// Initialize each constant buffer
		for (std::vector<ConstantBuffer*>::iterator itr = _constantBuffers.begin(); itr != _constantBuffers.end(); ++itr)
		{
			(*itr)->Initialize();
		}

		// If the material was read correctly, initialize each parameter
		//_vertexShader->Initialize(device);
		//_pixelShader->Initialize(device);
		//_inputLayout->Initialize(device, _vertexShader->GetShaderBuffer());
		//_constantBuffer->Initialize(device); <-- for each buffer in the list

		// Create shaders
		//_vertexShader = new VertexShader(_name, device);
		//_pixelShader = new PixelShader(_name, device);

		// Create constant buffer
		//_constantBuffer = RenderManager::GetSingletonPtr()->CreateConstantBuffer();
		//_constantBuffer->Initialize();

		// Create the input layout
		/*D3D11_INPUT_ELEMENT_DESC layout[] =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, 
				  D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, 
				  D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, 
				D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};
		HRESULT result = device.GetD3DDevice()->CreateInputLayout(layout, 3, _vertexShader->GetShaderBuffer()->GetBufferPointer(), _vertexShader->GetShaderBuffer()->GetBufferSize(), &_inputLayout);
		*/

		// Create the sampler state
		D3D11_SAMPLER_DESC samplerDesc;
		samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		samplerDesc.MipLODBias = 0.0f;
		samplerDesc.MaxAnisotropy = 1;
		samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
		samplerDesc.BorderColor[0] = 0;
		samplerDesc.BorderColor[1] = 0;
		samplerDesc.BorderColor[2] = 0;
		samplerDesc.BorderColor[3] = 0;
		samplerDesc.MinLOD = 0;
		samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;
		HRESULT result = device.GetD3DDevice()->CreateSamplerState(&samplerDesc, &_samplerState);
	}

	/**
	* Set this material to be the active rendering material
	* @param
	*	const RenderDevice& The device used to set the render material
	*/
	void Material::SetActive(const RenderDevice& device)
	{
		// Get the device context
		//ID3D11DeviceContext* context = device.GetImmediateContext();

		// Set the input layout
		//context->IASetInputLayout(_inputLayout.GetInputLayout());

		// Set the shader objects
		//context->VSSetShader(_vertexShader->GetShader(), NULL, 0);
		//context->PSSetShader(_pixelShader->GetShader(), NULL, 0);

		// Set the active sampler
		//context->PSSetSamplers(0, 1, &_samplerState);
	}

	/**
	* Get a material technique by index
	* @param
	*	uint The technique slot
	* @return
	*	const Technique& The technique to set
	*/
	const Technique& Material::GetTechniqueByIndex(uint index) const
	{
		return _technique;
	}

	/**
	* Get the constant buffer
	* @return
	*	ConstantBuffer* The constant buffer
	*/
	ConstantBuffer* Material::GetConstantBuffer() const
	{
		return _constantBuffers[0];
	}

	/**
	* Add a constant buffer to the material
	* @param
	*	ConstantBuffer* The constant buffer to register with this material
	*/
	void Material::AddConstantBuffer(ConstantBuffer* buffer)
	{
		_constantBuffers.push_back(buffer);
	}

	/**
	* Render the frame-targeted portions of this material
	* @param
	*	const RenderDevice& The device used to render
	*/
	void Material::RenderFrame(const RenderDevice& device)
	{
		// Set the input layout for the frame
		device.GetImmediateContext()->IASetInputLayout(_inputLayout.GetInputLayout());

		// Get the constant buffer for the frame
		for (uint i = 0; i < _constantBuffers.size(); ++i)
		{
			if (_constantBuffers[i]->GetBufferType() == CONSTANT_BUFFER_TYPE_FRAME)
			{
				_constantBuffers[i]->Render(device);
			}
		}
	}

	/**
	* Render object-targeted portions of this material
	* @param
	*	const RenderDevice& The device used to render
	*/
	void Material::RenderObject(const RenderDevice& device)
	{
		// Get the constant buffer for the frame
		for (uint i = 0; i < _constantBuffers.size(); ++i)
		{
			if (_constantBuffers[i]->GetBufferType() == CONSTANT_BUFFER_TYPE_OBJECT)
			{
				_constantBuffers[i]->Render(device);
			}
		}
	}

}	// Namespace