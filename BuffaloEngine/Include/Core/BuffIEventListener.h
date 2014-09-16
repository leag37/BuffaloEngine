// Filename: BuffIEventListener.h
// Author: Gael Huber
#ifndef __BUFFIEVENTLISTENER_H__
#define __BUFFIEVENTLISTENER_H__

#include "Core\BuffPrerequisites.h"

#include <queue>

namespace BuffaloEngine
{
	/** \addtogroup Core
	*	@{
	*/

	class Event;

	/**
	* Defines the interface for top-level interaction with event listener
	*/
	class IEventListener : public SimpleAlloc
	{
	public:
		/**
		 * Default constructor
		 */
		IEventListener();

		/**
		 * Destructor
		 */
		virtual ~IEventListener();

		/**
		 * Enqueue an event in this listener's queue
		 * @param event The event to enqueue
		 */
		virtual void Enqueue(const Event* event) = 0;

		/**
		 * Dequeue an event and invoke it
		 * @return Returns true if an event was dequeued, false otherwise
		 */
		virtual bool Dequeue() = 0;

	protected:
		/**
		 * The event queue
		 */
		std::queue<const Event*> _eventQueue;
	};
	
	/**
	* Default constructor
	*/
	IEventListener::IEventListener()
	{

	}

	/**
	* Destructor
	*/
	IEventListener::~IEventListener()
	{

	}

	/** @} */
}

#endif // __BUFFIEVENTLISTENER_H__