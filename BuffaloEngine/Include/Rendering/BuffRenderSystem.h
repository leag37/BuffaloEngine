// Filename: BuffRenderSystem.h
// Author: Gael Huber
#ifndef __BUFFRENDERSYSTEM_H__
#define __BUFFRENDERSYSTEM_H__

#include "Core\BuffPrerequisites.h"
#include "BuffRenderDevice.h"
#include "BuffRenderDeviceDriver.h"

#include <vector>

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

		/**
		* Prepare the scene for rendering
		*/
		void BeginScene();

		/**
		* Render a render queue
		* @param
		*	const RenderQueue& The render queue to process
		*/
		//void Render(const RenderQueue& renderQueue);

		/**
		* Present the scene
		*/
		void EndScene();

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

		/**
		* Create the swap chain
		* @return 
		*	bool Return true if successful
		*/
		bool CreateSwapChain();

		/**
		* Create the render target view
		* @return 
		*	bool Return true if successful
		*/
		bool CreateRenderTargetView();

		/**
		* Create the depth stencil view
		* @return 
		*	bool Return true if successful
		*/
		bool CreateDepthStencilView();

	private:
		/**
		* Render device
		*/
		RenderDevice _device;

		/**
		* Driver for rendering
		*/
		RenderDeviceDriver _activeDriver;
	
		/**
		* Active swap chain
		*/
		IDXGISwapChain* _swapChain;

		/**
		* Render target view
		*/
		ID3D11RenderTargetView* _renderTargetView;

		/**
		* Depth stencil view
		*/
		ID3D11DepthStencilView* _depthStencilView;

		/**
		* List of available device drivers
		*/
		std::vector<RenderDeviceDriver> _availableDrivers;
	};

	/** @} */

}	// Namespace

#endif