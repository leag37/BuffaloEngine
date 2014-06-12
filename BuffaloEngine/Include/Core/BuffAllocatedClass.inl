// Filename: BuffAllocatedClass.inl
// Author: Gael Huber

/**
* Explicit default constructor
*/
template <class Alloc>
AllocatedClass<Alloc>::AllocatedClass()
{
}
		
/**
* Destructor
*/
template <class Alloc>
AllocatedClass<Alloc>::~AllocatedClass()
{
}

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