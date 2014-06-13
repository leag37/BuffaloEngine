// Filename: BuffRenderManager.h
// Author: Gael Huber
#ifndef __BUFFRENDERMANAGER_H__
#define __BUFFRENDERMANAGER_H__

#include "Core\BuffPrerequisites.h"
#include "Core\BuffSingleton.h"

namespace BuffaloEngine
{
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

	private:

	};

	/** @} */

}	// Namespace

#endif // __BUFFRENDERMANAGER_H__