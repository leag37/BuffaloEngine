// Filename: BuffSharedPtr.h
// Author: Gael Huber
#ifndef __BUFFSHAREDPTR_H__
#define __BUFFSHAREDPTR_H__

#include "BuffPrerequisites.h"

namespace BuffaloEngine
{
	/**
	* Template type for a shared pointer. This acts like a reference counter for the contained object.
	*/
	template <typename Type>
	class SharedPtr
	{
	public:
		/**
		* Explicit constructor to store the type and initialize the shared pointer
		* @param
		*	Type* The pointer to maintain
		*/
		explicit SharedPtr(Type* pointer);

		/**
		* Copy constructor
		* @param
		*	const SharedPtr& The pointer to copy
		*/
		SharedPtr(const SharedPtr& other);

		/**
		* Destructor
		*/
		~SharedPtr();

		/**
		* Assignment operator
		* @param
		*	const SharedPtr& The pointer to assign
		* @return
		*	SharedPtr& The pointer after assignment
		*/
		SharedPtr& operator=(const SharedPtr& other);

		/**
		* Get the stored pointer
		* @return
		*	Type* The stored pointer
		*/
		Type* operator->() const;

		/**
		* Get a reference to the stored pointer
		* @return
		*	Type& The reference to the stored pointer
		*/
		Type& operator*() const;

		/**
		* Get the ref count for this pointer
		* @return
		*	uint The ref count number
		*/
		uint GetRefCount() const;

		/**
		* Set this pointer to null
		*/
		void SetNull();

	private:
		/**
		* Private default constructor
		*/
		SharedPtr();

		/**
		* Release the pointer
		*/
		void Release();

	private:
		/**
		* The pointer to the stored type
		*/
		Type* _pointer;

		/**
		* The reference count
		*/
		unsigned int* _refCount;
	};

#include "BuffSharedPtr.inl"

}	// Namespace

#endif // __BUFFSHAREDPTR_H__