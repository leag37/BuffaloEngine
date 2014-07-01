// Filename: BuffComponent.h
// Author: Gael Huber
#ifndef __BUFFCOMPONENT_H__
#define __BUFFCOMPONENT_H__

#include "Core\BuffPrerequisites.h"

#include <string>

namespace BuffaloEngine
{
	/**
	* A base engine component. Most simple objects will be components that are owned by Entities
	*/
	class Component : public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		Component();

		/**
		* Constructor
		* @param
		*	const std::string& The component name
		*/
		Component(const std::string& name);

		/**
		* Destructor
		*/
		virtual ~Component();

	protected:
		/**
		* The component name
		*/
		std::string _name;
	};

}	// Namespace

#endif // __BUFFCOMPONENT_H__