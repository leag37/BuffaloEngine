// Filename: BuffPrerequisites.h
// Author: Gael Huber
// Description: Prerequisite file for all header files. It contains a series of platform definitions 
// and engine-wide typedefs
#ifndef __BUFFPREREQUISITES_H__
#define __BUFFPREREQUISITES_H__

#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#endif
#include <xmmintrin.h>

// DirectX 11
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include <DXGI.h>
#include <D3Dcommon.h>
#include <D3DX11.h>
#include <D3DX10.h>
#include <D3Dcompiler.h>

namespace BuffaloEngine
{
	/** \addtogroup Core
	*	@{
	*/

	//**********
	// Typedefs
	//**********
	typedef unsigned int uint;
	typedef __int64 int64;
	typedef unsigned __int64 uint64;
	typedef __m128 vect;

	/** @} */

}	// Namespace

//**********************
// Platform definitions
//**********************

// BuffaloEngine includes
#include "BuffMemory.h"
#include "BuffSharedPtr.h"

#endif // __BUFFPREREQUISITES_H__