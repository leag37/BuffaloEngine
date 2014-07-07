// Filename: BuffRenderComponent.cpp
// Author: Gael Huber
#include "Rendering\BuffRenderComponent.h"

#include "Rendering\BuffMaterial.h"
#include "Rendering\BuffMesh.h"

namespace BuffaloEngine
{
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
	RenderComponent::RenderComponent(const RenderDevice& device, const std::string& name, const std::string& meshName, const std::string& materialName)
		:	Component(name),
			_device(device),
			_mesh(0)
	{
		// Create mesh
		_mesh = new Mesh(meshName);

		// Create the material
		_material = new Material(materialName);
		_material->Initialize(device);
	}

	/**
	* Render this component
	*/
	void RenderComponent::Render(const RenderDevice& device)
	{
		// Set the vertex buffer
		_mesh->Render(device);
	}

	/**
	* Get the attached material
	* @return
	*	Material* The attached material
	*/
	Material* RenderComponent::GetMaterial() const
	{
		return _material;
	}

}	// Namespace