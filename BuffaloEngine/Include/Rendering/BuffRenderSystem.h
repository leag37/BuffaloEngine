// Filename: BuffRenderSystem.h
// Author: Gael Huber
#ifndef __BUFFRENDERSYSTEM_H__
#define __BUFFRENDERSYSTEM_H__

#include "Core\BuffPrerequisites.h"

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* This class owns the render system devices and information descriptions
	*/
	class RenderSystem : public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		RenderSystem();

		/**
		* Destructor
		*/
		~RenderSystem();

		/**
		* Initialize the render system
		* @return
		*	bool Return true if the initialization succeeds
		*/
		bool Initialize();

		/**
		* Shutdown the render system
		*/
		void Shutdown();

	private:
		/**
		* Create the device driver
		* @return
		*	bool Return true if the driver is created successfully
		*/
		bool CreateDriver();

		/**
		* Create the device
		* @return
		*	bool Return true if the device is created successfully
		*/
		bool CreateDevice();
	private:
		/**
		* Render device
		*/
		//RenderDevice _device;

		/**
		* Driver for rendering
		*/
		//RenderDeviceDriver _deviceDriver;
	};

	/** @} */

}	// Namespace

#endif