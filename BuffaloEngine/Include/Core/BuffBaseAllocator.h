#ifndef __BUFFBASEALLOCATOR_H__
#define __BUFFBASEALLOCATOR_H__

#include "BuffPrerequisites.h"

namespace BuffaloEngine
{
	/** \addtogroup Core
	*	@{
	*/

	/**
	* Base allocator for objects to use
	*/
	// TODO: Add singleton support
	class BaseAllocator
	{
	public:
		/**
		* Get the singleton instance
		* @return
		*	BaseAllocator& The singleton instance
		*/
		static BaseAllocator& GetSingleton();

		/**
		* Get the pointer to the singleton instance
		* @return
		*	BaseAllocator* The pointer to the singleton instance
		*/
		static BaseAllocator* GetSingletonPtr();

		/**
		* Allocate memory from this allocator
		* @param
		*	size_t The size of allocation
		* @return
		*	void* The address of the memory to be used
		*/
		void* Allocate(size_t size);

		/**
		* Free a chunk of memory
		* @param
		*	void* The address to free
		*/
		void Free(void* mem);

	private:
		/** 
		* Default constructor
		*/
		BaseAllocator();
	};

	/** @} */

}	// Namespace

#endif // __BUFFBASEALLOCATOR_H__