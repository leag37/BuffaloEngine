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
		IAT_FORWARD		// Forward motion
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
		explicit InputEvent(InputActionType action);

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
	};

	/** @} */

}	// Namespace

#endif // __BUFFINPUTEVENT_H__