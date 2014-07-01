// Filename: BuffEvent.h
// Author: Gael Huber
#ifndef __BUFFEVENT_H__
#define __BUFFEVENT_H__

#include "BuffPrerequisites.h"

namespace BuffaloEngine
{
	/**	\addtogroup Core
	*	@{
	*/

	/**
	* A simple event interface
	*/
	class Event : public SimpleAlloc
	{
	public:

		/**
		*/
	protected:
		/**
		* The event id
		*/
		uint _eventId;
	};

	/** @} */

}	// Namespace

#endif // __BUFFIEVENT_H__