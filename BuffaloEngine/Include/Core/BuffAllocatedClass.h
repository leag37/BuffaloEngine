// Filename: BuffAllocatedClass.h
// Author: Gael Huber
#ifndef __BUFFALLOCATEDCLASS_H__
#define __BUFFALLOCATEDCLASS_H__

#include <malloc.h>

#include "BuffPrerequisites.h"

namespace BuffaloEngine
{
	/** \addtogroup Core
	* @{
	*/

	/**
	* Base class for all custom allocatored objects
	*/
	template <class Alloc>
	class AllocatedClass
	{
	public:
		/**
		* Explicit default constructor
		*/
		explicit AllocatedClass();
		
		/**
		* Destructor
		*/
		~AllocatedClass();

		/**
		* Overload for new operator
		* @param
		*	size_t The size of the object to be allocated
		* @return
		*	void* The address of the allocation
		*/
		/*void* operator new(size_t size)
		{
			return Alloc::Allocate(size);
		}*/
	};

#include "BuffAllocatedClass.inl"

	/** @} */

}	// Namespace

#endif // __BUFFALLOCATEDCLASS_H__