// Filename: BuffRenderManager.cpp
// Author: Gael Huber
#include "Rendering\BuffRenderManager.h"

#include "Rendering\BuffConstantBuffer.h"
#include "Rendering\BuffIndexBuffer.h"
#include "Rendering\BuffRenderComponent.h"
#include "Rendering\BuffRenderSystem.h"
#include "Rendering\BuffRenderWindow.h"
#include "Rendering\BuffVertexBuffer.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	RenderManager::RenderManager()
		:	Singleton(),
			_renderWindow(0)
	{
	}

	/**
	* Destructor
	*/
	RenderManager::~RenderManager()
	{
	}

	/**
	* Initialize the rendering manager
	* @return
	*	bool Return true if the initialization succeeded
	*/
	bool RenderManager::Initialize()
	{
		// Initialize the render window
		_renderWindow = new RenderWindow();
		_renderWindow->Initialize(800, 600);

		// Create the render system
		_renderSystem = new RenderSystem();
		_renderSystem->Initialize();

		return true;
	}

	/**
	* Shut down the rendering manager
	*/
	void RenderManager::Shutdown()
	{
		if(_renderWindow != 0)
		{
			_renderWindow->Shutdown();
			delete _renderWindow;
		}
	}

	/**
	* Get the singleton instance
	* @return
	*	RenderManager& The instance
	*/
	RenderManager& RenderManager::GetSingleton()
	{
		return *_instance;
	}

	/**
	* Get the pointer to the singleton instance
	* @return
	*	RenderManager* Pointer to the singleton instance
	*/
	RenderManager* RenderManager::GetSingletonPtr()
	{
		return _instance;
	}

	/**
	* Update the manager
	* @return
	*	bool Return true if the update is successful
	*/
	bool RenderManager::Update()
	{
		// Wait for previous job queue to finish
		//WaitForJobs();

		// Prepare the render system for rendering the scene
		_renderSystem->BeginScene();


		// Render a component
		_renderSystem->Render(_renderable);

		// Query the scene manager for the render queue
		//RenderQueueGroup renderQueueGroup = _sceneManager->QueryVisibleObjects();

		// Enumerate through each render queue group to get a batch
		/*
		for(RenderQueueGroup::Enumerator itr = renderQueueGroup.begin(); itr != renderQueueGroup.end(); ++itr)
		{
			// For this iterator, get the render queue associated with it
			RenderQueue queue = *itr;

			// Pass this queue through the render system
			_renderSystem->Render(queue);
		}
		*/
		// All render queues have been through the rendering cycle, so we can present the scene
		_renderSystem->EndScene();
		
		return true;
	}

	/**
	* Get the window
	* @return
	*	const RenderWindow* The render window to fetch
	*/
	const RenderWindow* RenderManager::GetRenderWindow() const
	{
		return _renderWindow;
	}

	/**
	* Create a camera and register it with the system
	* @return
	*	Camera* The created camera
	*/
	Camera* RenderManager::CreateCamera()
	{
		return 0;
	}

	/**
	* Create a render component
	* @param
	*	const std::string& Render component name
	* @param
	*	const std::string& The name of the mesh
	* @param
	*	const std::string& The name of the material to apply to the component
	* @return
	*	RenderComponent* A render component
	*/
	RenderComponent* RenderManager::CreateRenderComponent(const std::string& name, const std::string& meshName, const std::string& materialName)
	{
		// Quick and dirty, create the render component and return it
		RenderComponent* renderable = new RenderComponent(_renderSystem->GetRenderDevice(), name, meshName, materialName);
		return renderable;
	}

	/**
	* Create a vertex buffer
	* @return
	*	VertexBuffer* The created vertex buffer
	*/
	VertexBuffer* RenderManager::CreateVertexBuffer()
	{
		return new VertexBuffer(_renderSystem->GetRenderDevice());
	}

	/**
	* Create an index buffer
	* @return
	*	IndexBuffer* The created index buffer
	*/
	IndexBuffer* RenderManager::CreateIndexBuffer()
	{
		return new IndexBuffer(_renderSystem->GetRenderDevice());
	}

	/**
	* Create a constant buffer
	* @return
	*	ConstantBuffer* The created constant buffer
	*/
	ConstantBuffer* RenderManager::CreateConstantBuffer()
	{
		return new ConstantBuffer(_renderSystem->GetRenderDevice());
	}

	// TEMP
	void RenderManager::SetRenderable(RenderComponent* renderable)
	{
		_renderable = renderable;
	}
}