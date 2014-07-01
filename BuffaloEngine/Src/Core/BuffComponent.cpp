// Filename: BuffComponent.cpp
// Author: Gael Huber
#include "Core\BuffComponent.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Component::Component()
		:	_name("")
	{
	}

	/**
	* Constructor
	* @param
	*	const std::string& The component name
	*/
	Component::Component(const std::string& name)
		:	_name(name)
	{
	}

	/**
	* Destructor
	*/
	Component::~Component()
	{
	}
}