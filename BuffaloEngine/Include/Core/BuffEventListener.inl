// Filename: BuffEventListener.inl
// Author: Gael Huber

/**
* Default constructor
*/
template <typename Type>
EventListener<Type>::EventListener()
: _pType(0)
{

}

/**
* Constructor
* @param pType A pointer to the Type object owner for this event listener
*/
template <typename Type>
EventListener<Type>::EventListener(Type* pType)
: _pType(pType)
{

}

/**
* Destructor
*/
template <typename Type>
EventListener<Type>::~EventListener()
{
	_pType = 0;
}

/**
* Enqueue an event in this listener's queue
* @param evt The event to enqueue
*/
template <typename Type>
void EventListener<Type>::Enqueue(const Event* evt)
{
	// Add the event to the event queue
	_eventQueue.push(evt);
}

/**
* Dequeue an event and invoke it
* @return Returns true if an event was dequeued, false otherwise
*/
template <typename Type>
bool EventListener<Type>::Dequeue()
{
	// Get the event
	const Event* evt = _eventQueue.front();
	if (evt)
	{
		// Remove this event from the queue
		_eventQueue.pop();

		// Find the list of registered listeners for this event
		std::unordered_map<uint, std::vector<EventHandler> >::const_iterator handlerListItr = _eventHandlers.find(evt->GetEventType());

		//If found, iterate through the list of handlers and invoke
		if (handlerListItr != _eventHandlers.end())
		{
			const std::vector<EventHandler>& handlerList = (*handlerListItr).second;
			for (std::vector<EventHandler>::const_iterator handlerItr = handlerList.begin(); handlerItr != handlerList.end(); ++handlerItr)
			{
				EventHandler handler = (*handlerItr);
				(_pType->*(handler))(evt);
			}
		}
	}
	return true;
}

/**
 * Add an event listener
 * @param eventType The unique event type under which to register the handler function
 * @param handler The function handler for the event
 */
template <typename Type>
void EventListener<Type>::AddEventListener(uint eventType, EventHandler handler)
{
	_eventHandlers[eventType].push_back(handler);
	EventManager::GetSingletonPtr()->RegisterListener(eventType, this);
}

/**
 * Remove an event listener. Note that this will only remove the FIRST matching event
 * handler found, rather than all matching event handlers.
 * @param eventType The unique event type under which to unregister the handler function
 * @param handler The function handler for the event
 */
template <typename Type>
void EventListener<Type>::RemoveEventListener(uint eventType, EventHandler handler)
{
	// See if there are any handlers currently available for this event type
	std::unordered_map<uint, std::vector<EventHandler> >::iterator handlerListItr = _eventHandlers.find(eventType);
	if (handlerListItr != _eventHandlers.end())
	{
		// Once we have the handler list for this event type, remove the matching handler
		std::vector<EventHandler>& handlerList = (*handlerListItr).second;
		for (std::vector<EventHandler>::iterator handlerItr = handlerList.begin(); handlerItr != handlerList.end(); ++handlerItr)
		{
			// When the handler is found, remove it
			if (handler == (*handlerItr))
			{
				handlerList.erase(handlerItr);
				EventManager::GetSingletonPtr()->RemoveListener(eventType, this);
				return;
			}
		}
	}
}