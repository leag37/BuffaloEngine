#include "Core/BuffApplication.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Application::Application()
		:	_jobManager(0),
			_renderManager(0)
	{
	}

	/**
	* Copy constructor
	* @param
	*	const Application& The object to copy
	*/
	Application::Application(const Application& other)
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

		// Initialize hte rendering subsystem
		_renderManager = new RenderManager();
		if(_renderManager->Initialize() == false)
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
		bool canRun = true;

		while(canRun)
		{
			// Windows message pump
			while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				// Translate the message
				TranslateMessage(&msg);
				
				// Dispatch the message for processing
				DispatchMessage(&msg);
			}

			// Update rendering
			_renderManager->Update();
		}

		// Shutdown the system
		Shutdown();

		// The application ran successfully
		return true;
	}
}