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
	* @param action The input action
	*/
	InputEvent::InputEvent(InputActionType action)
		: Event(),
		_action(action)
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

	/**
	* Get the action type tied to this event
	* @return The input action
	*/
	InputActionType InputEvent::GetAction() const
	{
		return _action;
	}

}	// Namespace