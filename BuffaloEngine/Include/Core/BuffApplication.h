// Filename: BuffApplication.h
// Author: Gael Huber
#ifndef __BUFFAPPLICATION_H__
#define __BUFFAPPLICATION_H__

#include "Core\BuffPrerequisites.h"
#include "Core\BuffEventListener.h"

namespace BuffaloEngine
{
	/** \addtogroup Core
	*	@{
	*/

	/**
	* The base for building applications. This class acts as the root for engine functionality.
	*/
	class BUFFALOENGINE_API Application : public SimpleAlloc
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

		/**
		* Frame update. All world updates are triggered from this function
		* @param
		*	bool Returns true if succeeds
		*/
		virtual bool Update() = 0;

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

		/**
		 * Handle an exit event
		 * @param evt The event to process
		 */
		void OnExitEvent(const Event* evt);

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
		 * Event manager
		 */
		EventManager* _eventManager;

		/**
		 * Input manager
		 */
		InputManager* _inputManager;

	private:
		/**
		 * Event listener
		 */
		EventListener<Application> _listener;

		/**
		 * Boolean flag representing that this application can run
		 */
		bool _canRun;
	};

	/** @} */

}	// Namespace

#endif // __BUFFAPPLICATION_H__