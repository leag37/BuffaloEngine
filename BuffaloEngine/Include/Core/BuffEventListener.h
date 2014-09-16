// Filename: BuffEventListener.h
// Author: Gael Huber
#ifndef __BUFFEVENTLISTENER_H__
#define __BUFFEVENTLISTENER_H__

#include "Core\BuffPrerequisites.h"
#include "Core\BuffEvent.h"
#include "Core\BuffIEventListener.h"
#include "Core\BuffEventManager.h"

#include <unordered_map>
#include <vector>

namespace BuffaloEngine
{
	/** \addtogroup Core
	*	@{
	*/
	
	/**
	* Defines the interface for top-level interaction with event listener
	*/
	template <typename Type>
	class EventListener : public IEventListener
	{
	public:
		/**
		 * Typedef to describe the function handler for an event
		 */
		typedef void(Type::*EventHandler)(const Event*);

	public:
		/**
		* Default constructor
		*/
		EventListener();

		/**
		 * Constructor
		 * @param pType A pointer to the Type object owner for this event listener
		 */
		EventListener(Type* pType);

		/**
		* Destructor
		*/
		virtual ~EventListener();

		/**
		* Enqueue an event in this listener's queue
		* @param evt The event to enqueue
		*/
		void Enqueue(const Event* evt);

		/**
		* Dequeue an event and invoke it
		* @return Returns true if an event was dequeued, false otherwise
		*/
		bool Dequeue();

		/**
		 * Add an event listener
		 * @param eventType The unique event type under which to register the handler function
		 * @param handler The function handler for the event
		 */
		void AddEventListener(uint eventType, EventHandler handler);

		/**
		 * Remove an event listener. Note that this will only remove the FIRST matching event
		 * handler found, rather than all matching event handlers.
		 * @param eventType The unique event type under which to unregister the handler function
		 * @param handler The function handler for the event
		 */
		void RemoveEventListener(uint eventType, EventHandler handler);

	private:
		/**
		 * A pointer to the Type owner of this EventListener. This will permit invoked events
		 * to call the handlers registered to the target instance of Type
		 */
		Type* _pType;

		/**
		 * Container for all event listeners. All listeners are contained in an array keyed on the event type
		 */
		std::unordered_map<uint, std::vector<EventHandler> > _eventHandlers;
	};

	#include "Core\BuffEventListener.inl"

	/** @} */
}

#endif // __BUFFIEVENTLISTENER_H__