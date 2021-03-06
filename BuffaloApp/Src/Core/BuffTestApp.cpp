// Filename: BuffTestApp.cpp
// Author: Gael Huber
#include "Core\BuffTestApp.h"

#include "Rendering\BuffRenderManager.h"
#include "Rendering\BuffRenderComponent.h"

/**
* Default constructor
*/
TestApp::TestApp()
{
}

/**
* Frame update. All world updates are triggered from this function
* @param
*	bool Returns true if succeeds
*/
bool TestApp::Update()
{
	return true;
}

/**
* Initialize and build the scene
* @return
*	bool Return true if the scene is initialized successfully
*/
bool TestApp::InitializeScene()
{
	// Create a camera
	//_camera = _renderManager->CreateCamera();

	// Create a renderable component. Two things are required for any renderable component, mesh name and material name
	RenderComponent* renderComponent = _renderManager->CreateRenderComponent("tank", "tank", "Basic");
	_renderManager->SetRenderable(renderComponent);

	return true;
}