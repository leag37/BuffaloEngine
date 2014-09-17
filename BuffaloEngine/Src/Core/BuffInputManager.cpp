// Filename: BuffInputManager.cpp
// Author: Gael Huber
#include "Core\BuffInputManager.h"
#include "Rendering\BuffRenderManager.h"
#include "Rendering\BuffRenderWindow.h"

#include "Core\BuffInputEvent.h"
#include "Core\BuffEventManager.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	InputManager::InputManager()
	{

	}

	/**
	* Destructor
	*/
	InputManager::~InputManager()
	{

	}

	/**
	* Initialize the input manager
	* @return Return true if the initialization succeeded
	*/
	bool InputManager::Initialize()
	{
		// Try to initialize the DirectInput device
		DirectInput8Create(
			GetModuleHandle(NULL),
			DIRECTINPUT_VERSION,
			IID_IDirectInput8,
			(void**)&fDI,
			NULL
			);

		if (fDI == NULL)
		{
			MessageBox(NULL, "DirectInput Connection Creation Failed!", "Error", 0);
			return false;
		}

		// Create the connection to the keyboard device
		fDI->CreateDevice(GUID_SysKeyboard, &fDIKeyboard, NULL);
		if (fDIKeyboard)
		{
			fDIKeyboard->SetDataFormat(&c_dfDIKeyboard);
			fDIKeyboard->SetCooperativeLevel(
				RenderManager::GetSingletonPtr()->GetRenderWindow()->GetHWND(),
				DISCL_FOREGROUND | DISCL_EXCLUSIVE
				);
			fDIKeyboard->Acquire();
		}
		else
		{
			MessageBox(NULL, "DirectInput Keyboard Initialization Failed!", "Error", 0);
			return false;
		}

		return true;
	}

	/**
	* Shut down the input manager
	*/
	void InputManager::Shutdown()
	{

	}

	/**
	* Get the singleton instance
	* @return The instance
	*/
	InputManager& InputManager::GetSingleton()
	{
		return *_instance;
	}

	/**
	* Get the pointer to the singleton instance
	* @return Pointer to the singleton instance
	*/
	InputManager* InputManager::GetSingletonPtr()
	{
		return _instance;
	}

	/**
	* Update the input
	* @return Returns true if the update is successful
	*/
	bool InputManager::Update()
	{
		char keyboardState[256];
		HRESULT result = fDIKeyboard->GetDeviceState(sizeof(keyboardState), (LPVOID)&keyboardState);
		if (FAILED(result))
		{
			fDIKeyboard->Acquire();
		}

		if (keyboardState[DIK_W] & 0x80)
		{
			EventManager::GetSingletonPtr()->DispatchEvent(new InputEvent(IAT_FORWARD));
		}

		return true;
	}
}