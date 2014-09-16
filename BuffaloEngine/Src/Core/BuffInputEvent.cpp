// Filename: BuffInputEvent.cpp
// Author: Gael Huber
#include "Core\BuffInputEvent.h"

namespace BuffaloEngine
{
	/**
	 * Register the event type
	 */
	REGISTER_EVENT_TYPE(InputEvent)

	/**
	* Constructor
	* @param eventId The event id associated with this event
	*/
	InputEvent::InputEvent()
		: Event()
	{

	}

	/**
	* Destructor
	*/
	InputEvent::~InputEvent()
	{

	}

	/**
	* Get the type id for this event
	* @return The type associated with this event
	*/
	uint InputEvent::GetEventType() const
	{
		return InputEvent::TYPE;
	}

}	// Namespace