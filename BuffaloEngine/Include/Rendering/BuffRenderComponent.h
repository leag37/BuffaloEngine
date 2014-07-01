// Filename: BuffRenderComponent.h
// Author: Gael Huber
#ifndef __BUFFRENDERCOMPONENT_H__
#define __BUFFRENDERCOMPONENT_H__

#include "Core\BuffComponent.h"

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
		* Default constructor
		*/
		RenderComponent();

		/**
		* Constructor
		* @param
		*	const std::string& The name of the component
		* @param
		*	const std::string& The mesh name
		* @param
		*	const std::string& The material name
		*/
		RenderComponent(const std::string& name, const std::string& meshName, const std::string& materialName);

		/**
		* Destructor
		*/
		//~RenderComponent();
	private:
		/**
		* The mesh owned by this component
		*/
		Mesh* _mesh;

		/**
		* The material used by this component
		*/
		//Material* _material;
	};

	/** @} */

}	// Namespace

#endif // __BUFFRENDERCOMPONENT_H__