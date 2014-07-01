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

	/**
	* Frame update. All world updates are triggered from this function
	* @param
	*	bool Returns true if succeeds
	*/
	bool Update();

protected:
	/**
	* Initialize and build the scene
	* @return
	*	bool Return true if the scene is initialized successfully
	*/
	bool InitializeScene();

private:
	/**
	* Camera!
	*/
	//Camera* _camera;
};

#endif // __BUFFTESTAPP_H__