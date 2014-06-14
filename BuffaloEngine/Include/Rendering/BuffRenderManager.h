// Filename: BuffRenderManager.h
// Author: Gael Huber
#ifndef __BUFFRENDERMANAGER_H__
#define __BUFFRENDERMANAGER_H__

#include "Core\BuffPrerequisites.h"
#include "Core\BuffSingleton.h"

namespace BuffaloEngine
{
	// Forward declarations
	class RenderWindow;

	/**	\addtogroup Rendering
	*	@{
	*/

	/**
	* Render manager controls all aspects of rendering owns all aspects of rendering, both 2D and 3D pipelines.
	*/
	class RenderManager : public Singleton<RenderManager>, public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		RenderManager();

		/**
		* Destructor
		*/
		~RenderManager();

		/**
		* Initialize the rendering manager
		* @return
		*	bool Return true if the initialization succeeded
		*/
		bool Initialize();

		/**
		* Shut down the rendering manager
		*/
		void Shutdown();

		/**
		* Get the singleton instance
		* @return
		*	RenderManager& The instance
		*/
		static RenderManager& GetSingleton();

		/**
		* Get the pointer to the singleton instance
		* @return
		*	RenderManager* Pointer to the singleton instance
		*/
		static RenderManager* GetSingletonPtr();

		/**
		* Update the manager
		* @return
		*	bool Return true if the update is successful
		*/
		bool Update();

	private:
		/**
		* Render system. This owns the low-level rendering devices
		*/
		//RenderSystem* _renderSystem;

		/**
		* The rendering window
		*/
		RenderWindow* _renderWindow;

		/**
		* The target render viewport
		*/
		//RenderViewport* _renderViewport;

		/**
		* Scene manager
		*/
		//SceneManager* _sceneManager;

		/**
		* Texture manager
		*/
		//TextureManager* _textureManager;

		/**
		* Hardware buffer manager
		*/
		//HardwareBufferManager* _hardwareBufferManager;

		/**
		* Mesh manager
		*/
		//MeshManager* _meshManager;

		/**
		* Shader manager
		*/
		//ShaderManager* _shaderManager;
	};

	/** @} */

}	// Namespace

#endif // __BUFFRENDERMANAGER_H__