// Filename: BuffSharedPtr.inl
// Author: Gael Huber

/**
* Explicit constructor to store the type and initialize the shared pointer
* @param
*	Type* The pointer to maintain
*/
template <typename Type>
SharedPtr<Type>::SharedPtr(Type* pointer)
	:	_pointer(pointer),
		_refCount(pointer ? new int(1) : 0)
{
}

/**
* Copy constructor
* @param
*	const SharedPtr& The pointer to copy
*/
template <typename Type>
SharedPtr<Type>::SharedPtr(const SharedPtr& other)
	:	_pointer(other._pointer),
		_refCount(other._refCount)
{
	InterlockedIncrement(_refCount);
}

/**
* Destructor
*/
template <typename Type>
SharedPtr<Type>::~SharedPtr()
{
	Release();
}

/**
* Assignment operator
* @param
*	const SharedPtr& The pointer to assign
* @return
*	SharedPtr& The pointer after assignment
*/
template <typename Type>
SharedPtr<Type>& SharedPtr<Type>::operator=(const SharedPtr& other)
{
	// Self-assignment protection
	if(this == &other)
	{
		return *this;
	}

	// Assign and return
	_pointer = other._pointer;
	_refCount = other._refCount;
}

/**
* Get the stored pointer
* @return
*	Type* The stored pointer
*/
template <typename Type>
Type* SharedPtr<Type>::operator->() const
{
	return _pointer;
}

/**
* Get a reference to the stored pointer
* @return
*	Type& The reference to the stored pointer
*/
template <typename Type>
Type& SharedPtr<Type>::operator*() const
{
	return *_pointer;
}

/**
* Get the ref count for this pointer
* @return
*	uint The ref count number
*/
template <typename Type>
uint SharedPtr<Type>::GetRefCount() const
{
	return *_refCount;
}

/**
* Set this pointer to null
*/
template <typename Type>
void SharedPtr<Type>::SetNull()
{
	Release();
}

/**
* Private default constructor
*/
template <typename Type>
SharedPtr<Type>::SharedPtr()
	:	_pointer(0),
		_refCount(0)
{
}

/**
* Release the pointer
*/
template <typename Type>
void SharedPtr<Type>::Release()
{
	// Check that the pointer and the refcount are valid
	if(_pointer != 0 && _refCount != 0)
	{
		// Decrement the ref count
		if(InterlockedDecrement(_refCount) == 0)
		{
			// Delete the pointer if the ref count is 0
			delete _pointer;
			delete _refCount;
		}

		// Set pointer and refcount to null
		_pointer = 0;
		_refCount = 0;
	}
}
