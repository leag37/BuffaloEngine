
#include "Core\BuffIEventListener.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	IEventListener::IEventListener()
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
		return _eventQueue.size() > 0;
	}
}