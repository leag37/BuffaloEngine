// Filename: BuffExitEvent.h
// Author: Gael Huber
#ifndef __BUFFEXITEVENT_H__
#define __BUFFEXITEVENT_H__

#include "Core\BuffPrerequisites.h"
#include "Core\BuffEvent.h"

namespace BuffaloEngine
{
	/**	\addtogroup Core
	*	@{
	*/

	/**
	* A event that triggers application exit
	*/
	class BUFFALOENGINE_API ExitEvent : public Event
	{
	public:
		/**
		* Default constructor
		*/
		explicit ExitEvent();

		/**
		* Destructor
		*/
		virtual ~ExitEvent();

		/**
		* Get the type id for this event
		* @return The type associated with this event
		*/
		uint GetEventType() const;

	public:
		/**
		 * Event type
		 */
		static uint TYPE;
	};

	/** @} */

}	// Namespace

#endif // __BUFFEXITEVENT_H__