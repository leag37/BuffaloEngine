// Filename: BuffMaterial.h
// Author: Gael Huber
#ifndef __BUFFMATERIAL_H__
#define __BUFFMATERIAL_H__

#include "Core\BuffPrerequisites.h"

#include <string>

namespace BuffaloEngine
{
	class ConstantBuffer;
	class RenderDevice;
	class PixelShader;
	class VertexShader;

	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* Materials own the description for how to rendern an object.
	*/
	class Material : public SimpleAlloc
	{
	private:
		/**
		* Loader for materials
		*/
		class MaterialReader;

	public:
		/**
		* Default constructor
		*/
		Material();

		/**
		* Constructor
		* @param
		*	const std::string& The name of the material
		*/
		Material(const std::string& name);

		/**
		* Initialize the material
		* @param
		*	const RenderDevice& The render device
		*/
		void Initialize(const RenderDevice& device);

		/**
		* Set this material to be the active rendering material
		* @param
		*	const RenderDevice& The device used to set the render material
		*/
		void SetActive(const RenderDevice& device);

		/**
		* Get the constant buffer
		* @return
		*	ConstantBuffer* The constant buffer
		*/
		ConstantBuffer* GetConstantBuffer() const;

	private:
		/**
		* The material name
		*/
		std::string _name;

		/**
		* Vertex shader
		*/
		VertexShader* _vertexShader;

		/**
		* Pixel shader
		*/
		PixelShader* _pixelShader;

		/**
		* Constant buffer
		*/
		ConstantBuffer* _constantBuffer;

		/**
		* Input layout
		*/
		ID3D11InputLayout* _inputLayout;

		/**
		* Sampler state
		*/
		ID3D11SamplerState* _samplerState;
	};

	/** @} */

}	// Namespace

#endif // __BUFFMATERIAL_H__