
#include "Core\BuffIEventListener.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	IEventListener::IEventListener()
		: _externalEventsQueue(0)
	{}

	/**
	* Destructor
	*/
	IEventListener::~IEventListener()
	{}

	/**
	* Peek at the events queue to determine if there is an event
	*/
	bool IEventListener::Peek()
	{
		return _eventQueue[_externalEventsQueue].size() > 0;
	}
}