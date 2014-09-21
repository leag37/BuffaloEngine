// Filename: BuffScopedLock.cpp
// Author: Gael Huber
#include "Core\BuffScopedLock.h"

namespace BuffaloEngine
{
	/**
	* Constructor
	* @param criticalSection The critical section to own
	*/
	ScopedLock::ScopedLock(LPCRITICAL_SECTION criticalSection)
		: _criticalSection(criticalSection)
	{
		// Enter the critical section
		EnterCriticalSection(_criticalSection);
	}

	/**
	* Destructor
	*/
	ScopedLock::~ScopedLock()
	{
		// Leave the critical section
		LeaveCriticalSection(_criticalSection);
	}

}