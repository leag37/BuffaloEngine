// Filename: BuffApplication.h
// Author: Gael Huber
#ifndef __BUFFAPPLICATION_H__
#define __BUFFAPPLICATION_H__

#include "Core\BuffPrerequisites.h"
#include "Core\BuffJobManager.h"
#include "Rendering\BuffRenderManager.h"

namespace BuffaloEngine
{
	/** \addtogroup Core
	*	@{
	*/

	/**
	* The base for building applications. This class acts as the root for engine functionality.
	*/
	class Application : public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		Application();

		/**
		* Copy constructor
		* @param
		*	const Application& The object to copy
		*/
		Application(const Application& other);

		/**
		* Destructor
		*/
		virtual ~Application();

		/**
		* Run the application
		* @return
		*	bool Return true if the application runs and terminates successfully
		*/
		bool Run();

	protected:
		/**
		* Initialize and build the scene
		* @return
		*	bool Return true if the scene is initialized successfully
		*/
		virtual bool InitializeScene() = 0;

	private:
		/**
		* Initialize the application
		* @return
		*	bool Return true if the initialization succeeded
		*/
		bool Initialize();

		/**
		* Shut down the application
		*/
		void Shutdown();

	protected:
		/**
		* Job manager
		*/
		JobManager* _jobManager;
		
		/**
		* Render manager
		*/
		RenderManager* _renderManager;
		
		/**
		* Scene manager
		*/



	};

	/** @} */

}	// Namespace

#endif // __BUFFAPPLICATION_H__