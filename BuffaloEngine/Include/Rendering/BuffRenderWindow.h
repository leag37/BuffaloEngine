// Filename: BuffRenderWindow.h
// Author: Gael Huber
#ifndef __BUFFRENDERWINDOW_H__
#define __BUFFRENDERWINDOW_H__

#include "Core\BuffPrerequisites.h"

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* Defines a visible render window
	*/
	class RenderWindow : public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		RenderWindow();

		/**
		* Destructor
		*/
		~RenderWindow();

		/**
		* Initialize the window with a given width and height
		* @param
		*	uint The width of the window
		* @param
		*	uint The height of the window
		* @return
		*	bool Return true if the initialize succeed
		*/
		bool Initialize(uint width, uint height);

		/**
		* Shutdown the window
		*/
		void Shutdown();

	private:
		/**
		* The window width
		*/
		uint _width;

		/**
		* The window height
		*/
		uint _height;

		/**
		* True if the window is fullscreen
		*/
		bool _isFullscreen;

		/**
		* Process instance
		*/
		HINSTANCE _hInstance;

		/**
		* Window handle
		*/
		HWND _hWnd;
	};

	/** @} */

}	// Namespace

#endif // __BUFFRENDERWINDOW_H__