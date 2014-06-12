// Filename: Main.cpp
// Author: Gael Huber
// Description: Entry point for BuffloEngine application

#include "Core\BuffTestApp.h"

using namespace BuffaloEngine;

int main()
{
	// Create the application
	TestApp app;

	// Run the application
	if(app.Run() == false)
	{
		return 1;
	}

	return 0;
}