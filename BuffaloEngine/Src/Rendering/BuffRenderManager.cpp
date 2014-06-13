// Filename: BuffRenderManager.cpp
// Author: Gael Huber
#include "Rendering\BuffRenderManager.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	RenderManager::RenderManager()
		:	Singleton()
	{
	}

	/**
	* Destructor
	*/
	RenderManager::~RenderManager()
	{
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
}