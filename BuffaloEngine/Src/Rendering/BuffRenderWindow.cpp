// Filename: BuffRenderWindow.cpp
// Author: Gael Huber
#include "Rendering\BuffRenderWindow.h"

#include "Core\BuffEventManager.h"
#include "Core\BuffExitEvent.h"

namespace BuffaloEngine
{
	LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	/**
	* Default constructor
	*/
	RenderWindow::RenderWindow()
	{
	}

	/**
	* Destructor
	*/
	RenderWindow::~RenderWindow()
	{
	}

	/**
	* Initialize the window with a given width and height
	* @param
	*	uint The width of the window
	* @param
	*	uint The height of the window
	* @return
	*	bool Return true if the initialize succeed
	*/
	bool RenderWindow::Initialize(uint width, uint height)
	{
		_hInstance = GetModuleHandle(NULL);

		// Create the window class
		WNDCLASS wc;
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = _hInstance;
		wc.hIcon = LoadIcon(0, IDI_APPLICATION);
		wc.hCursor = LoadCursor(0, IDC_ARROW);
		wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(NULL_BRUSH));
		wc.lpszMenuName = 0;
		wc.lpszClassName = "BuffaloEngine";

		RegisterClass(&wc);

		// Compute inner window size
		RECT r = {0, 0, width, height};
		AdjustWindowRect(&r, WS_OVERLAPPEDWINDOW, false);
		long iWidth = r.right - r.left;
		long iHeight = r.bottom - r.top;
		
		// Create the window
		_hWnd = CreateWindow(
			wc.lpszClassName,
			"BuffaloEngine",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			iWidth,
			iHeight,
			0,
			0,
			_hInstance,
			0
			);
		if(!_hWnd)
		{
			MessageBox(0, "CreateWindow failed.", 0, 0);
			return false;
		}

		// Save variables
		_width = width;
		_height = height;
		_isFullscreen = false;

		// Display the window
		ShowWindow(_hWnd, SW_SHOW);
		UpdateWindow(_hWnd);

		return true;
	}

	/**
	* Shutdown the window
	*/
	void RenderWindow::Shutdown()
	{
	}

	/**
	* Get the window handle
	* @return
	*	HWND The window handle
	*/
	HWND RenderWindow::GetHWND() const
	{
		return _hWnd;
	}

	/**
	* Window Process
	*/
	LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		// If we are creating this window, store the pointer to the user data area for Win32Window
		/*if(msg == WM_CREATE)
		{
			SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)(((LPCREATESTRUCT)lParam)->lpCreateParams));
		}*/

		// Look up the window instance
		// Note that it's possible to get WM_SIZE before WM_CREATE
		/*RenderWindow* win = reinterpret_cast<RenderWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		if(!win)
		{
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}*/

		// Process messages	
		switch(msg)
		{

		// If Windows signals to exit the application, quit
		case WM_QUIT:
			EventManager::GetSingletonPtr()->DispatchEvent(new ExitEvent());
			return 0;

		// The window is destroyed, quit application
		case WM_DESTROY:
			// Send quit message to application
			PostQuitMessage(0);

			return 0;
		}
		
		// Default process
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}