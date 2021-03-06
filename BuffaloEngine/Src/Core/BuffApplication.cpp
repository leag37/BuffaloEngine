// Filename: BuffApplication.cpp
// Author: Gael Huber
#include "Core\BuffApplication.h"

#include "Core\BuffEventManager.h"
#include "Core\BuffExitEvent.h"
#include "Core\BuffInputManager.h"
#include "Core\BuffJobManager.h"
#include "Core\BuffUpdaterJob.h"
#include "Rendering\BuffRenderManager.h"

#include <iostream>

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Application::Application()
		:	_canRun(false),
			_jobManager(0),
			_renderManager(0),
			_eventManager(0),
			_inputManager(0)
	{
	}

	/**
	* Copy constructor
	* @param
	*	const Application& The object to copy
	*/
	Application::Application(const Application& other)
		:	_canRun(other._canRun),
			_jobManager(other._jobManager),
			_renderManager(other._renderManager),
			_eventManager(other._eventManager),
			_inputManager(other._inputManager)
	{
	}

	/**
	* Destructor
	*/
	Application::~Application()
	{
	}

	/**
	* Initialize the application
	* @return
	*	bool Return true if the initialization succeeded
	*/
	bool Application::Initialize()
	{
		// Initialize the job system
		_jobManager = new JobManager();
		if(_jobManager->Initialize() == false)
		{
			return false;
		}

		// Initialize the event manager
		_eventManager = new EventManager();
		if (_eventManager->Initialize() == false)
		{
			return false;
		}

		// Initialize hte rendering subsystem
		_renderManager = new RenderManager();
		if(_renderManager->Initialize() == false)
		{
			return false;
		}

		// Input manager
		_inputManager = new InputManager();
		if (_inputManager->Initialize() == false)
		{
			return false;
		}

		/**
		 * Hook in the event listener to listen for exit events
		 */
		_listener = EventListener<Application>(this);
		_listener.AddEventListener(ExitEvent::TYPE, &Application::OnExitEvent);

		// All systems are initialized, so create our scene
		if(InitializeScene() == false)
		{
			return false;
		}

		return true;
	}

	/**
	* Shut down the application
	*/
	void Application::Shutdown()
	{
		// Shutdown the various subsystems
		SafeShutdown(_inputManager);
		SafeShutdown(_renderManager);
		SafeShutdown(_eventManager);
		SafeShutdown(_jobManager);
	}

	/**
	* Handle an exit event
	* @param evt The event to process
	*/
	void Application::OnExitEvent(const Event* evt)
	{
		// Make sure the event type is valid
		if (evt->GetEventType() == ExitEvent::TYPE)
		{
			// Set the application status to exit
			_canRun = false;
		}
	}

	/**
	* Run the application
	* @return
	*	bool Return true if the application runs and terminates successfully
	*/
	bool Application::Run()
	{
		// Initialize the application
		if(Initialize() == false)
		{
			return false;
		}
		
		// Main loop
		MSG msg;
		_canRun = true;
		
		// Create various jobs for main render loops
		UpdaterJob<RenderManager> renderUpdateJob(_renderManager);
		UpdaterJob<InputManager> inputUpdateJob(_inputManager);

		DWORD lastTime = timeGetTime();
		DWORD frames = 0;

		while(_canRun)
		{
			// Process any events
			_listener.ProcessEvents();

			const DWORD currentTime = timeGetTime();
			const DWORD timeSinceLast = currentTime - lastTime;
			++frames;
			if (timeSinceLast > 1000)
			{
				lastTime = currentTime - (timeSinceLast - 1000);
				std::cout << "Frames: " << frames << std::endl;
				frames = 0;
			}

			// Windows message pump
			if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				// Translate the message
				TranslateMessage(&msg);
				
				// Dispatch the message for processing
				DispatchMessage(&msg);
			}

			// Pre-frame update
			//PreFrameUpdate();

			// Frame update
			Update();

			// Update rendering
			renderUpdateJob.Wait();
			_jobManager->AddJob(&renderUpdateJob);

			inputUpdateJob.Wait();
			_jobManager->AddJob(&inputUpdateJob);
		}

		// Shutdown the system
		Shutdown();

		// The application ran successfully
		return true;
	}
}