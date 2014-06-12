#include "Core/BuffApplication.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Application::Application()
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

		// Loop
		// TODO

		// Shutdown the system
		Shutdown();

		// The application ran successfully
		return true;
	}
}