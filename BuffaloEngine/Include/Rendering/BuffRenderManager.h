// Filename: BuffRenderManager.h
// Author: Gael Huber
#ifndef __BUFFRENDERMANAGER_H__
#define __BUFFRENDERMANAGER_H__

#include "Core\BuffPrerequisites.h"
#include "Core\BuffSingleton.h"
#include "Rendering\BuffCamera.h"

#include <string>

namespace BuffaloEngine
{
	// Forward declarations
	class ConstantBuffer;
	class IndexBuffer;
	class PixelShader;
	class RenderComponent;
	class RenderSystem;
	class RenderWindow;
	class VertexBuffer;
	class VertexShader;

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

		/**
		* Get the window
		* @return
		*	const RenderWindow* The render window to fetch
		*/
		const RenderWindow* GetRenderWindow() const;

		/**
		* Create a camera and register it with the system
		* @return
		*	Camera* The created camera
		*/
		Camera* CreateCamera();

		/**
		* Create a render component
		* @param
		*	const std::string& Render component name
		* @param
		*	const std::string& The name of the mesh
		* @param
		*	const std::string& The name of the material to apply to the component
		* @return
		*	RenderComponent* A render component
		*/
		RenderComponent* CreateRenderComponent(const std::string& name, const std::string& meshName, const std::string& materialName);

		/**
		* Create a vertex buffer
		* @return
		*	VertexBuffer* The created vertex buffer
		*/
		VertexBuffer* CreateVertexBuffer();

		/**
		* Create an index buffer
		* @return
		*	IndexBuffer* The created index buffer
		*/
		IndexBuffer* CreateIndexBuffer();

		/**
		* Create a constant buffer
		* @return
		*	ConstantBuffer* The created constant buffer
		*/
		ConstantBuffer* CreateConstantBuffer();

		/**
		* Create a vertex shader
		* @param
		*	const std::string& The vertex shader entry point
		* @param
		*	const std::string& The vertex shader filename
		* @param
		*	VertexShader* The created vertex shader
		*/
		VertexShader* CreateVertexShader(const std::string& entryPoint, const std::string& fileName);

		/**
		* Create a pixel shader
		* @param
		*	const std::string& The pixel shader entry point
		* @param
		*	const std::string& The pixel shader filename
		* @param
		*	PixelShader* The created pixel shader
		*/
		PixelShader* CreatePixelShader(const std::string& entryPoint, const std::string& fileName);

		// TEMP
		void SetRenderable(RenderComponent* renderable);

	private:
		/**
		* Render system. This owns the low-level rendering devices
		*/
		RenderSystem* _renderSystem;

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

		
		// TEMP - Renderable
		RenderComponent* _renderable;
	};

	/** @} */

}	// Namespace

#endif // __BUFFRENDERMANAGER_H__