// Filename: BuffTestApp.cpp
// Author: Gael Huber
#include "Core\BuffTestApp.h"

#include "Core\BuffEventListener.h"
#include "Core\BuffInputEvent.h"
#include "Core\BuffEventManager.h"

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
	EventListener<TestApp> listener = EventListener<TestApp>(this);
	listener.AddEventListener(InputEvent::TYPE, &TestApp::OnInputEvent);
	InputEvent* ie = new BuffaloEngine::InputEvent();
	ie->a = 2;
	EventManager::GetSingletonPtr()->DispatchEvent(ie);
	listener.Dequeue();


	// Create a camera
	//_camera = _renderManager->CreateCamera();

	// Create a renderable component. Two things are required for any renderable component, mesh name and material name
	RenderComponent* renderComponent = _renderManager->CreateRenderComponent("tank", "tank", "Basic");
	_renderManager->SetRenderable(renderComponent);

	return true;
}

// TEMP
void TestApp::OnInputEvent(const Event* evt)
{
	const InputEvent* iEvt = dynamic_cast<const InputEvent*>(evt);
	int a = iEvt->a;
	int b = a + 1;
}