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
	* A simple event interface
	*/
	class BUFFALOENGINE_API InputEvent : public Event
	{
	public:
		/**
		* Constructor
		* @param eventId The event id associated with this event
		*/
		explicit InputEvent();

		/**
		* Destructor
		*/
		~InputEvent();

		/**
		* Get the type id for this event
		* @return The type associated with this event
		*/
		virtual uint GetEventType() const;

		int a;

	public:
		/**
		 * The event type
		 */
		static uint TYPE;
	};

	/** @} */

}	// Namespace

#endif // __BUFFINPUTEVENT_H__