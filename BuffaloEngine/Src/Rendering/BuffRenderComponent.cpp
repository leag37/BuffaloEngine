// Filename: BuffRenderComponent.cpp
// Author: Gael Huber
#include "Rendering\BuffRenderComponent.h"

#include "Rendering\BuffMesh.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	RenderComponent::RenderComponent()
		:	Component(0),
			_mesh(0)
	{
	}

	/**
	* Constructor
	* @param
	*	const std::string& The name of the component
	* @param
	*	const std::string& The mesh name
	* @param
	*	const std::string& The material name
	*/
	RenderComponent::RenderComponent(const std::string& name, const std::string& meshName, const std::string& materialName)
		:	Component(name),
			_mesh(0)
	{
		// Create mesh
		_mesh = new Mesh(meshName);
	}

}	// Namespace