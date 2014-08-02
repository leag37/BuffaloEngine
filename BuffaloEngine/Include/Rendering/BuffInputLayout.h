// Filename: BuffInputLayout.h
// Author: Gael Huber
#ifndef __BUFFINPUTLAYOUT_H__
#define __BUFFINPUTLAYOUT_H__

#include "Core\BuffPrerequisites.h"
#include "Rendering\BuffInputLayoutParameter.h"

#include <vector>

namespace BuffaloEngine
{
	class RenderDevice;

	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* Describes the input layout for a material. Vertex data expects to be passed in according to this
	* configuration
	*/
	class InputLayout
	{
	public:
		/**
		* Default constructor
		*/
		InputLayout();

		/**
		* Copy constructor
		* @param
		*	const InputLayout& The input layout to copy
		*/
		InputLayout(const InputLayout& other);

		/**
		* Destructor
		*/
		~InputLayout();

		/**
		* Assignment operator
		* @param
		*	const InputLayout& The input layout to assign
		* @return
		*	InputLayout& The copied input layout
		*/
		InputLayout& operator=(const InputLayout& other);

		/**
		* Add a input layout parameter to this definition
		* @param
		*	const InputLayoutParameter& The parameter to add to the definition
		*/
		void AddParameter(const InputLayoutParameter& param);

		/**
		* Initialize the input layout given the current description
		* @param
		*	const RenderDevice& The render device used to create
		* @param
		*	ID3D10Blob* The target shader for this input layout
		* @return
		*	bool Returns true if successful
		*/
		bool Initialize(const RenderDevice& device, ID3D10Blob* targetShader);

		/**
		* Construct and return the input layout element description
		* @return
		*	D3D11_INPUT_ELEMENT_DESC* The input layout description
		*/
		D3D11_INPUT_ELEMENT_DESC* GetInputLayoutDesc();

		/**
		* Get the input layout for this object
		* @return
		*	ID3D11InputLayout* The D3D11 input layout
		*/
		ID3D11InputLayout* GetInputLayout() const;

	private:
		/**
		* The input layout
		*/
		ID3D11InputLayout* _inputLayout;
		
		/**
		* The list of active parameters
		*/
		std::vector<InputLayoutParameter> _parameters;

		/**
		* The input layout description
		*/
		D3D11_INPUT_ELEMENT_DESC* _inputLayoutDesc;

		
	};

	/** @} */

}	// Namespace

#endif // __BUFFINPUTLAYOUT_H__