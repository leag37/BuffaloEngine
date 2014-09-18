// Filename: BuffRenderSystem.h
// Author: Gael Huber
#ifndef __BUFFRENDERSYSTEM_H__
#define __BUFFRENDERSYSTEM_H__

#include "Core\BuffPrerequisites.h"
#include "BuffRenderDevice.h"
#include "BuffRenderDeviceDriver.h"
#include "Core\BuffEventListener.h"
#include "Core\BuffInputEvent.h"
#include "Rendering\BuffCamera.h"

#include <vector>

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	/**
	 * Forward declare event listener type
	 */
	template class EventListener<RenderSystem>;

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
		void Render(RenderComponent* renderable);
		
		/**
		* Present the scene
		*/
		void EndScene();

		/**
		* Get the render device owned by the system
		* @return
		*	const RenderDevice& The render device
		*/
		const RenderDevice& GetRenderDevice() const;

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

		/**
		* Bind the render targets to the output graphics pipeline
		* @return
		*	bool True if successful
		*/
		bool BindRenderTargets();

		/**
		* Create the viewport
		* @return
		*	bool True if successful
		*/
		bool CreateViewport();

		void OnMove(const Event* evt);

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
		* Depth stencil buffer
		*/
		ID3D11Texture2D* _depthStencilBuffer;

		/**
		* Depth stencil state
		*/
		ID3D11DepthStencilState* _depthStencilState;

		/**
		* Depth stencil view
		*/
		ID3D11DepthStencilView* _depthStencilView;

		/**
		* List of available device drivers
		*/
		std::vector<RenderDeviceDriver> _availableDrivers;

		/**
		 * Event listener
		 */
		EventListener<RenderSystem> _eventListener;

		DirectX::XMFLOAT3 _position;
		DirectX::XMFLOAT3 _rotation;

		/**
		* Camera
		*/
		Camera _camera;
	};

	/** @} */

}	// Namespace

#endif