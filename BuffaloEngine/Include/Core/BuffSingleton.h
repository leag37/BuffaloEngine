// Filename: BuffSingleton.h
// Author: Gael Huber
#ifndef __BUFFSINGLETON_H__
#define __BUFFSINGLETON_H__

#include "BuffPrerequisites.h"

namespace BuffaloEngine
{
	/** \addtogroup Core
	*	@{
	*/

	/**
	* Base class for singleton objects
	*/
	template <typename Type>
	class Singleton
	{
	public:
		/**
		* Default constructor
		*/
		Singleton();

		/**
		* Destructor
		*/
		virtual ~Singleton();

	private:
		/**
		* Copy constructor
		* @param
		*	const Singleton& The singleton to copy
		*/
		Singleton(const Singleton& other);

		/**
		* Assignment operator
		* @param
		*	const Singleton& The singleton to copy
		* @return
		*	Singleton& The singleton post-assignment
		*/
		Singleton& operator=(const Singleton& other);

	protected:
		/**
		* The singleton instance
		*/
		static Type* _instance;
	};

#include "BuffSingleton.inl"

	/** @} */

}	// Namespace

#endif // __BUFFSINGLETON_H__