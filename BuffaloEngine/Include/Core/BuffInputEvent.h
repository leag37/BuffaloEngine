// Filename: BuffInputEvent.h
// Author: Gael Huber
// TODO: Change events to PoolAlloc<Event<T>>
// TODO: Events should be templates
// TODO: Events should inherit from interface IEvent <-- non-template class
#ifndef __BUFFINPUTEVENT_H__
#define __BUFFINPUTEVENT_H__

#include "Core\BuffPrerequisites.h"
#include "Core\BuffEvent.h"

namespace BuffaloEngine
{
	/**	\addtogroup Core
	*	@{
	*/

	/**
	 * Enum describing input event actions
	 */
	enum InputActionType
	{
		IAT_FORWARD,		// Forward motion
		IAT_BACKWARD,		// Backward motion
		IAT_STRAFE_LEFT,	// Strafe to the left
		IAT_STRAFE_RIGHT,	// Strafe to the right
		IAT_TURN,			// Turn to either direction
		IAT_START_VERTICAL_STRAFE,	// Signal start of vertical strafe
		IAT_END_VERTICAL_STRAFE,	// Signal end of vertical strafe
		IAT_STRAFE_UP,		// Strafe vertically upward
		IAT_STRAFE_DOWN,	// Strafe vertically downward
	};

	/**
	* A simple event interface
	*/
	class BUFFALOENGINE_API InputEvent : public Event
	{
	public:
		/**
		* Constructor
		* @param action The input action
		*/
		explicit InputEvent(InputActionType action, float x = 0, float y = 0, float z = 0);

		/**
		* Destructor
		*/
		~InputEvent();

		/**
		* Get the type id for this event
		* @return The type associated with this event
		*/
		virtual uint GetEventType() const;

		/**
		 * Get the action type tied to this event
		 * @return The input action
		 */
		InputActionType GetAction() const;

		float GetX() const { return _x; }
		float GetY() const { return _y; }
		float GetZ() const { return _z; }

	public:
		/**
		 * The event type
		 */
		static uint TYPE;

	private:
		/**
		 * The input action type
		 */
		InputActionType _action;

		/**
		 * X
		 */
		float _x;

		/**
		 * Y input
		 */
		float _y;

		float _z;
	};

	/** @} */

}	// Namespace

#endif // __BUFFINPUTEVENT_H__