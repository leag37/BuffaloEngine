// Filename: BuffInputLayoutParameter.h
// Author: Gael Huber
#ifndef __BUFFINPUTLAYOUTPARAMETER_H__
#define __BUFFINPUTLAYOUTPARAMETER_H__

#include "Core\BuffPrerequisites.h"
#include "Rendering\BuffVertexDescription.h"
#include "Rendering\BuffShaderParameter.h"

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* Describes an input layout parameter
	*/
	class InputLayoutParameter
	{
	public:
		/**
		* Default constructor
		*/
		InputLayoutParameter();

		/**
		* Constructor
		* @param
		*	const ShaderParameter& The shader parameter for this input layout
		* @param
		*	VertexElementSemantic The semantic for this input layout
		*/
		InputLayoutParameter(const ShaderParameter& param, VertexElementSemantic semantic);

		/**
		* Copy constructor
		*	const InputLayoutParameter& The input layout parameter to copy
		*/
		InputLayoutParameter(const InputLayoutParameter& other);

		/**
		* Destructor
		*/
		~InputLayoutParameter();

		/**
		* Assignment operator
		* @param
		*	const InputLayoutParameter& The input layout parameter to copy
		* @param
		*	InputLayoutParameter& The copied parameter
		*/
		InputLayoutParameter& operator=(const InputLayoutParameter& other);

		/**
		* Get the Direct3D element description for this parameter
		* @param
		*	D3D11_INPUT_ELEMENT_DESC The input element description for this parameter
		*/
		D3D11_INPUT_ELEMENT_DESC GetElementDesc() const;

	private:
		/**
		* The shader parameter for this input layout parameter
		*/
		ShaderParameter _parameter;

		/**
		* The vertex semantic
		*/
		VertexElementSemanticDescription _semantic;
	};

	/** @} */

}	// Namespace

#endif // __BUFFINPUTLAYOUTPARAMETER_H__