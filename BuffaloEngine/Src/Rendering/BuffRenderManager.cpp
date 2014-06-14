// Filename: BuffRenderManager.cpp
// Author: Gael Huber
#include "Rendering\BuffRenderManager.h"
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
		return true;
	}
}