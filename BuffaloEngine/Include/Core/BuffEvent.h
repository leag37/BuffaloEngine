// Filename: BuffEvent.h
// Author: Gael Huber
// TODO: Change events to PoolAlloc<Event<T>>
// TODO: Events should be templates
// TODO: Events should inherit from interface IEvent <-- non-template class
#ifndef __BUFFEVENT_H__
#define __BUFFEVENT_H__

#include "Core\BuffPrerequisites.h"

namespace BuffaloEngine
{
	/**	\addtogroup Core
	*	@{
	*/

	/**
	* A simple event interface
	*/
	class BUFFALOENGINE_API Event : public SimpleAlloc
	{
	public:
		/**
		 * Default constructor
		 */
		explicit Event();

		/**
		 * Destructor
		 */
		virtual ~Event();

		/**
		 * Get the type id for this event
		 * @return The type associated with this event
		 */
		virtual uint GetEventType() const = 0;
	};

	// Use this to register event types with the engine.
	// NOTE: This line needs to be added after every class definition like so:
	// class MyEvent : public Event
	// { };
	// REGISTER_EVENT_TYPE(MyEvent)
	static uint EventTypeCounter = 0;
	#define REGISTER_EVENT_TYPE(x) uint x::TYPE = EventTypeCounter++;

	/** @} */

}	// Namespace

#endif // __BUFFEVENT_H__