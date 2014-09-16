// Filename: BuffSingleton.inl
// Author: Gael Huber


template <typename Type> Type* Singleton<Type>::_instance = 0;

/**
* Default constructor
*/
template <typename Type>
Singleton<Type>::Singleton()
{
	if(_instance == 0)
	{
		_instance = static_cast<Type*>(this);
	}
}

/**
* Destructor
*/
template <typename Type>
Singleton<Type>::~Singleton()
{
	// Delete the singleton
	if(_instance != 0)
	{
		_instance = 0;
	}
}

/**
* Copy constructor
* @param
*	const Singleton& The singleton to copy
*/
template <typename Type>
Singleton<Type>::Singleton(const Singleton& other)
{
}

/**
* Assignment operator
* @param
*	const Singleton& The singleton to copy
* @return
*	Singleton& The singleton post-assignment
*/
template <typename Type>
Singleton<Type>& Singleton<Type>::operator=(const Singleton& other)
{
	return *this;
}
