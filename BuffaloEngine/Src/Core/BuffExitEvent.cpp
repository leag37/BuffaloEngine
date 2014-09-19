// Filename: BuffExitEvent.cpp
// Author: Gael Huber
#include "Core\BuffExitEvent.h"

namespace BuffaloEngine
{
	/**
	* Register the event type
	*/
	REGISTER_EVENT_TYPE(ExitEvent)

	/**
	* Default constructor
	*/
	ExitEvent::ExitEvent()
	: Event()
	{

	}

	/**
	* Destructor
	*/
	ExitEvent::~ExitEvent()
	{

	}

	/**
	* Get the type id for this event
	* @return The type associated with this event
	*/
	uint ExitEvent::GetEventType() const
	{
		return TYPE;
	}


}	// Namespace
