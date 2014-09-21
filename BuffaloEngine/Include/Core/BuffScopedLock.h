// Filename: BuffScopedLock.h
// Author: Gael Huber
#ifndef __BUFFSCOPEDLOCK_H__
#define __BUFFSCOPEDLOCK_H__

#include "Core\BuffPrerequisites.h"

namespace BuffaloEngine
{
	/** \addtogroup Core
	 *	@{
	 */

	/**
	 * Scoped lock takes a critical section and will take ownership of a critical section until it goes out of scope
	 * and is destructed.
	 */
	class ScopedLock : public SimpleAlloc
	{
	public:
		/**
		 * Constructor
		 * @param criticalSection The critical section to own
		 */
		explicit ScopedLock(LPCRITICAL_SECTION criticalSection);
		
		/**
		 * Destructor
		 */
		~ScopedLock();

	private:
		/**
		 * The critical section
		 */
		LPCRITICAL_SECTION _criticalSection;
	};

	/** @} */
}

#endif // __BUFFSCOPEDLOCK_H__