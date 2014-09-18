// Filename: BuffEventManager.cpp
// Author: Gael Huber
#include "Core\BuffEventManager.h"
#include "Core\BuffIEventListener.h"
#include "Core\BuffEvent.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	EventManager::EventManager()
	{

	}

	/**
	* Destructor
	*/
	EventManager::~EventManager()
	{

	}

	/**
	* Initialize the job manager
	* @return Return true if the initialization succeeded
	*/
	bool EventManager::Initialize()
	{
		return true;
	}

	/**
	* Shut down the job manager
	*/
	void EventManager::Shutdown()
	{

	}

	/**
	* Get the singleton instance
	* @return The instance
	*/
	EventManager& EventManager::GetSingleton()
	{
		return *_instance;
	}

	/**
	* Get the pointer to the singleton instance
	* @return Pointer to the singleton instance
	*/
	EventManager* EventManager::GetSingletonPtr()
	{
		return _instance;
	}

	/**
	* Dispatch an event
	* @param evt The event to dispatch
	*/
	void EventManager::DispatchEvent(const Event* evt)
	{
		// Get the event type
		uint eventType = evt->GetEventType();

		// Get the list for event type
		std::vector<IEventListener*>& listeners = _eventListeners[eventType];

		// For each listener, enqueue the event
		for (std::vector<IEventListener*>::iterator itr = listeners.begin(); itr != listeners.end(); ++itr)
		{
			(*itr)->Enqueue(evt);
		}
	}

	/**
	* Register an event listener with the event bus for a given event type. Any time an event
	* is dispatched via the bus
	* @param eventType The event type to register
	* @param eventListener The event listener registered with this event
	*/
	void EventManager::RegisterListener(uint eventType, IEventListener* listener)
	{
		// Get the list for the target event type
		std::vector<IEventListener*>& listeners = _eventListeners[eventType];

		// Ensure this listener does not exist within the list
		for (std::vector<IEventListener*>::iterator itr = listeners.begin(); itr != listeners.end(); ++itr)
		{
			// If the listener is already registered, do not register twice
			if (*itr == listener)
			{
				return;
			}
		}

		// Register the listener
		listeners.push_back(listener);
	}

	/**
	* Remove an event listener from the event bus.
	* @param eventType The type under which this listener is registered
	* @param listener The event listener to remove
	*/
	void EventManager::RemoveListener(uint eventType, IEventListener* listener)
	{
		// Get the list for the target event type
		std::vector<IEventListener*>& listeners = _eventListeners[eventType];

		// Search for the listener
		for (std::vector<IEventListener*>::iterator itr = listeners.begin(); itr != listeners.end(); ++itr)
		{
			// The listener is found, remove it and end
			if (*itr == listener)
			{
				listeners.erase(itr);
				return;
			}
		}
	}
}