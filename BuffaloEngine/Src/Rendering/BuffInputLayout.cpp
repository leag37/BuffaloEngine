// Filename: BuffInputLayout.cpp
// Author: Gael Huber
#include "Rendering\BuffInputLayout.h"

#include "Rendering\BuffRenderDevice.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	InputLayout::InputLayout()
		: _inputLayout(0), _inputLayoutDesc(0)
	{

	}

	/**
	* Copy constructor
	* @param
	*	const InputLayout& The input layout to copy
	*/
	InputLayout::InputLayout(const InputLayout& other)
		: _parameters(other._parameters),
		_inputLayout(other._inputLayout),
		_inputLayoutDesc(other._inputLayoutDesc)
	{
		
	}

	/**
	* Destructor
	*/
	InputLayout::~InputLayout()
	{
		// Clear the list of parameters
		_parameters.clear();

		// Delete the input layout
		if (_inputLayout)
		{
			_inputLayout->Release();
			_inputLayout = 0;
		}

		// Delete the input layout description
		if (_inputLayoutDesc)
		{
			delete[] _inputLayoutDesc;
		}
	}

	/**
	* Assignment operator
	* @param
	*	const InputLayout& The input layout to assign
	* @return
	*	InputLayout& The copied input layout
	*/
	InputLayout& InputLayout::operator=(const InputLayout& other)
	{
		// Clear the parameter list
		_parameters.clear();
		for (std::vector<InputLayoutParameter>::const_iterator itr = other._parameters.begin(); itr != other._parameters.end(); ++itr)
		{
			_parameters.push_back(*itr);
		}

		// Copy the layout description and the layout itself
		_inputLayoutDesc = other._inputLayoutDesc;
		_inputLayout = other._inputLayout;

		return *this;
	}

	/**
	* Add a input layout parameter to this definition
	* @param
	*	const InputLayoutParameter& The parameter to add to the definition
	*/
	void InputLayout::AddParameter(const InputLayoutParameter& param)
	{
		// Add the parameter to the list of parameters
		_parameters.push_back(param);
	}

	/**
	* Initialize the input layout given the current description
	* @param
	*	const RenderDevice& The render device used to create
	* @param
	*	ID3D10Blob* The target shader for this input layout
	* @return
	*	bool Returns true if successful
	*/
	bool InputLayout::Initialize(const RenderDevice& device, ID3D10Blob* targetShader)
	{
		// Get the layout description
		D3D11_INPUT_ELEMENT_DESC* layoutDescription = GetInputLayoutDesc();

		// Initialize the layout
		HRESULT result = device.GetD3DDevice()->CreateInputLayout(layoutDescription, _parameters.size(), targetShader->GetBufferPointer(), targetShader->GetBufferSize(), &_inputLayout);
		return SUCCEEDED(result);
	}

	/**
	* Construct and return the input layout element description
	* @return
	*	D3D11_INPUT_ELEMENT_DESC* The input layout description
	*/
	D3D11_INPUT_ELEMENT_DESC* InputLayout::GetInputLayoutDesc()
	{
		// If the input layout does not exist, create it first
		if (_inputLayoutDesc == 0)
		{
			uint numParams = _parameters.size();
			_inputLayoutDesc = new D3D11_INPUT_ELEMENT_DESC[numParams];

			for (uint i = 0; i < numParams; ++i)
			{
				_inputLayoutDesc[i] = _parameters[i].GetElementDesc();
			}
		}

		return _inputLayoutDesc;
	}

	/**
	* Get the input layout for this object
	* @return
	*	ID3D11InputLayout* The D3D11 input layout
	*/
	ID3D11InputLayout* InputLayout::GetInputLayout() const
	{
		return _inputLayout;
	}

}	// Namespace