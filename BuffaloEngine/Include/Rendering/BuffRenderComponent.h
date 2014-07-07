// Filename: BuffRenderComponent.h
// Author: Gael Huber
#ifndef __BUFFRENDERCOMPONENT_H__
#define __BUFFRENDERCOMPONENT_H__

#include "Core\BuffComponent.h"
#include "Rendering\BuffRenderDevice.h"

namespace BuffaloEngine
{
	// Forward declarations
	class Material;
	class Mesh;

	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* Renderable components contain information about mesh and the material
	*/
	class RenderComponent : public Component
	{
	public:
		/**
		* Constructor
		* @param
		*	const RenderDevice& The render device used to create and render the component
		* @param
		*	const std::string& The name of the component
		* @param
		*	const std::string& The mesh name
		* @param
		*	const std::string& The material name
		*/
		explicit RenderComponent(const RenderDevice& device, const std::string& name, const std::string& meshName, const std::string& materialName);

		/**
		* Destructor
		*/
		//~RenderComponent();

		/**
		* Render this component
		*/
		void Render(const RenderDevice& device);

		/**
		* Get the attached material
		* @return
		*	Material* The attached material
		*/
		Material* GetMaterial() const;

	private:
		/**
		* The mesh owned by this component
		*/
		Mesh* _mesh;

		/**
		* The material used by this component
		*/
		Material* _material;

		/**
		* The render device
		*/
		const RenderDevice& _device;
	};

	/** @} */

}	// Namespace

#endif // __BUFFRENDERCOMPONENT_H__