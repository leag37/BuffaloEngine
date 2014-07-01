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

		// Create various jobs for main render loops
		//RenderUpdateJob renderUpdateJob;

		while(canRun)
		{
			// Windows message pump
			if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				// Translate the message
				TranslateMessage(&msg);
				
				// Dispatch the message for processing
				DispatchMessage(&msg);
			}

			// If Windows signals to exit the application, quit
			if(msg.message == WM_QUIT)
			{
				canRun = false;
			}

			// Pre-frame update
			//PreFrameUpdate();

			// Frame update
			Update();

			// Update rendering
			if(_renderManager->Update() == false)
			{
				canRun = false;
			}
		}

		// Shutdown the system
		Shutdown();

		// The application ran successfully
		return true;
	}
}