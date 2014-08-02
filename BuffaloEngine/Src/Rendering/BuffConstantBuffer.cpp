// Filename: BuffConstantBuffer.cpp
// Author: Gael Huber
#include "Rendering\BuffConstantBuffer.h"

namespace BuffaloEngine
{
	/**
	* Constructor
	* @param
	*	const RenderDevice& The render device
	*/
	ConstantBuffer::ConstantBuffer(const RenderDevice& renderDevice)
		:	HardwareBuffer(renderDevice)
	{
	}

	/**
	* Destructor
	*/
	ConstantBuffer::~ConstantBuffer()
	{
	}

	/**
	* Initialize the buffer
	* @return
	*	bool Returns true if successfully initialized
	*/
	bool ConstantBuffer::Initialize()
	{
		// Reset has changed
		_hasChanged = false;

		// Get the size of the buffer parameters and update the byte offset for each parameter
		uint size = 0;
		for (std::vector<ShaderParameter>::iterator itr = _parameters.begin(); itr != _parameters.end(); ++itr)
		{
			itr->SetByteOffset(size);
			size += itr->GetSize();
		}

		// Create a vector of the size specified
		_cpuBuffer = std::vector<char>(size);

		D3D11_BUFFER_DESC cbDesc;
		cbDesc.ByteWidth = size;
		cbDesc.Usage = D3D11_USAGE_DYNAMIC;
		cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		cbDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		cbDesc.MiscFlags = 0;
		cbDesc.StructureByteStride = 0;

		HRESULT result = _renderDevice.GetD3DDevice()->CreateBuffer(&cbDesc, NULL, &_buffer);

		return !FAILED(result);
	}

	/**
	* Get the buffer type
	* @return
	*	ConstantBufferType The buffer type
	*/
	ConstantBufferType ConstantBuffer::GetBufferType() const
	{
		return _type;
	}

	/**
	* Set the constant buffer type
	* @param
	*	ConstantBufferType The buffer type to set this buffer
	*/
	void ConstantBuffer::SetBufferType(ConstantBufferType type)
	{
		_type = type;
	}

	/**
	* Add a parameter to the constant buffer definition
	* @param
	*	const ShaderParameter& The parameter to add
	*/
	void ConstantBuffer::AddParameter(const ShaderParameter& parameter)
	{
		_parameters.push_back(parameter);
	}

	/**
	* Get the buffer size
	* @return
	*	uint The size of the buffer contents in bytes
	*/
	uint ConstantBuffer::GetBufferSize() const
	{
		// For each parameter, calculate the size
		uint size = 0;
		for (std::vector<ShaderParameter>::const_iterator itr = _parameters.begin(); itr != _parameters.end(); ++itr)
		{
			size += ShaderParameter::GetSizeForParameter(itr->GetParameterType());
		}

		return size;
	}

	/**
	* Render the constant buffer
	* @param
	*	const RenderDevice& The render device used to render this buffer
	*/
	void ConstantBuffer::Render(const RenderDevice& device)
	{
		// Get the device context
		ID3D11DeviceContext* context = device.GetImmediateContext();

		// If this buffer has not changed, do not proceed
		if (_hasChanged == true)
		{

			// Map the subresource data
			D3D11_MAPPED_SUBRESOURCE mappedResource;
			HRESULT result = context->Map(_buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
			if (FAILED(result))
			{
				return;
			}

			// Copy the data
			memcpy(mappedResource.pData, &_cpuBuffer[0], _cpuBuffer.size());

			// Unmap the data
			context->Unmap(_buffer, 0);

			// Reset has changed
			_hasChanged = false;
		}

		// Set the buffer to active
		uint slot = 0;
		if (_type == CONSTANT_BUFFER_TYPE_OBJECT)
		{
			slot = 1;
		}
		context->VSSetConstantBuffers(slot, 1, &_buffer);
	}
}