// Filename: BuffMaterial.h
// Author: Gael Huber
#ifndef __BUFFMATERIAL_H__
#define __BUFFMATERIAL_H__

#include "Core\BuffPrerequisites.h"
#include "Rendering\BuffInputLayout.h"
#include "Rendering\BuffTechnique.h"

#include <string>
#include <vector>

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
		* Get a material technique by index
		* @param
		*	uint The technique slot
		* @return
		*	const Technique& The technique to set
		*/
		const Technique& GetTechniqueByIndex(uint index) const;

		/**
		* Get the constant buffer
		* @return
		*	ConstantBuffer* The constant buffer
		*/
		ConstantBuffer* GetConstantBuffer() const;

		/**
		* Render the frame-targeted portions of this material
		* @param
		*	const RenderDevice& The device used to render
		*/
		void RenderFrame(const RenderDevice& device);

		/**
		* Render object-targeted portions of this material
		* @param
		*	const RenderDevice& The device used to render
		*/
		void RenderObject(const RenderDevice& device);

		// TEMP
		// Quick and dirty function to update constant buffer parameters
		template <typename ParamType>
		void UpdateCBufferParam(const std::string& paramName, ParamType param)
		{
			for (uint i = 0; i < _constantBuffers.size(); ++i)
			{
				_constantBuffers[i]->UpdateParamByName(paramName, param);
			}
		}

	private:
		/**
		* Add a constant buffer to the material
		* @param
		*	ConstantBuffer* The constant buffer to register with this material
		*/
		void AddConstantBuffer(ConstantBuffer* buffer);

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
		* The technique associated with this material
		*/
		Technique _technique;

		/**
		* Constant buffer list
		*/
		std::vector<ConstantBuffer*> _constantBuffers;

		/**
		* Input layout
		*/
		InputLayout _inputLayout;

		/**
		* Sampler state
		*/
		ID3D11SamplerState* _samplerState;
	};

	/** @} */

}	// Namespace

#endif // __BUFFMATERIAL_H__