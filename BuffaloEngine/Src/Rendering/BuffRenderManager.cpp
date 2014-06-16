// Filename: BuffRenderManager.cpp
// Author: Gael Huber
#include "Rendering\BuffRenderManager.h"
#include "Rendering\BuffRenderSystem.h"
#include "Rendering\BuffRenderWindow.h"

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
}