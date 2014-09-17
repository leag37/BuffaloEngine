// Filename: BuffInputManager.h
// Author: Gael Huber
#ifndef __BUFFINPUTMANAGER_H__
#define __BUFFINPUTMANAGER_H__

#include "Core\BuffPrerequisites.h"
#include "Core\BuffSingleton.h"

#include <dinput.h>

namespace BuffaloEngine
{
	/** \addtogroup Core
	 *	@{
	 */

	/**
	 * Class to controll all user input
	 */
	class BUFFALOENGINE_API InputManager : public Singleton<InputManager>, public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		InputManager();

		/**
		* Destructor
		*/
		~InputManager();

		/**
		* Initialize the input manager
		* @return Return true if the initialization succeeded
		*/
		bool Initialize();

		/**
		* Shut down the input manager
		*/
		void Shutdown();

		/**
		* Get the singleton instance
		* @return The instance
		*/
		static InputManager& GetSingleton();

		/**
		* Get the pointer to the singleton instance
		* @return Pointer to the singleton instance
		*/
		static InputManager* GetSingletonPtr();

		/**
		 * Update the input
		 * @return Returns true if the update is successful
		 */
		bool Update();

	private:
		LPDIRECTINPUT8 fDI;
		LPDIRECTINPUTDEVICE8 fDIKeyboard;
	};

	/** @} */
}

#endif // __BUFFINPUTMANAGER_H__