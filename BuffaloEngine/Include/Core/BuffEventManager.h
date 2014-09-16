// Filename: BuffEventManager.h
// Author: Gael Huber
#ifndef __BUFFEVENTMANAGER_H__
#define __BUFFEVENTMANAGER_H__

#include "Core/BuffPrerequisites.h"
#include "Core/BuffSingleton.h"

#include <unordered_map>
#include <vector>

namespace BuffaloEngine
{
	class Event;
	class IEventListener;

	/** \addtogroup Core
	 *	@{
	 */

	/**
	 * Event bus and throughput for handling and triggering of events.
	 */
	class BUFFALOENGINE_API EventManager : public Singleton<EventManager>, public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		EventManager();

		/**
		* Destructor
		*/
		~EventManager();

		/**
		* Initialize the job manager
		* @return Return true if the initialization succeeded
		*/
		bool Initialize();

		/**
		* Shut down the job manager
		*/
		void Shutdown();

		/**
		* Get the singleton instance
		* @return The instance
		*/
		static EventManager& GetSingleton();

		/**
		* Get the pointer to the singleton instance
		* @return Pointer to the singleton instance
		*/
		static EventManager* GetSingletonPtr();

		/**
		 * Dispatch an event
		 * @param evt The event to dispatch
		 */
		void DispatchEvent(const Event* evt);

		/**
		 * Register an event listener with the event bus for a given event type. Any time an event
		 * is dispatched via the bus
		 * @param eventType The event type to register
		 * @param eventListener The event listener registered with this event
		 */
		void RegisterListener(uint eventType, IEventListener* listener);

		/**
		 * Remove an event listener from the event bus.
		 * @param eventType The type under which this listener is registered
		 * @param listener The event listener to remove
		 */
		void RemoveListener(uint eventType, IEventListener* listener);

	private:
		/**
		 * Container for all event listeners. All listeners are contained in an array keyed on the event type
		 */
		std::unordered_map<uint, std::vector<IEventListener*> > _eventListeners;
	};

	/** @} */
}

#endif __BUFFEVENTMANAGER_H__