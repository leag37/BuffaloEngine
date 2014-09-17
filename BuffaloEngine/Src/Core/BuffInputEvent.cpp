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
	InputEvent::InputEvent(InputActionType action, float x, float y, float z)
		: Event(),
		_action(action),
		_x(x),
		_y(y),
		_z(z)
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