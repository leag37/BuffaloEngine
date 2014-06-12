// Filename: BuffTestApp.h
// Author: Gael Huber
#ifndef __BUFFTESTAPP_H__
#define __BUFFTESTAPP_H__

#include "Core\BuffApplication.h"

using namespace BuffaloEngine;

/**
* A test application
*/
class TestApp : public Application
{
public:
	/**
	* Default constructor
	*/
	TestApp();

protected:
	/**
	* Initialize and build the scene
	* @return
	*	bool Return true if the scene is initialized successfully
	*/
	bool InitializeScene();
};

#endif // __BUFFTESTAPP_H__