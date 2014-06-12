// Filename: BuffMemory.h
// Author: Gael Huber
#ifndef __BUFFMEMORY_H__
#define __BUFFMEMORY_H__

#include "BuffPrerequisites.h"
#include "BuffAllocatedClass.h"
#include "BuffBaseAllocator.h"

namespace BuffaloEngine
{
	// Typedefs for standard allocation patterns
	typedef AllocatedClass<BaseAllocator> SimpleAlloc;

}	// Namespace

#endif // __BUFFMEMORY_H__