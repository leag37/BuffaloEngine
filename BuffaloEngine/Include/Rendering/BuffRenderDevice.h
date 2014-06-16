// Filename: BuffRenderDevice.h
// Author: Gael Huber
#ifndef __BUFFRENDERDEVICE_H__
#define __BUFFRENDERDEVICE_H__

#include "Core\BuffPrerequisites.h"

namespace BuffaloEngine
{
	class RenderDeviceDriver;

	/** \addtogroup Rendering
	*	@{
	*/

	/** 
	* Render device encapsulates a Direct3D device and context information
	*/
	class RenderDevice : public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		RenderDevice();

		/**
		* Destructor
		*/
		~RenderDevice();

		/**
		* Create the device given the driver information
		* @param
		*	const RenderDeviceDriver& The driver used to create this device
		*/
		bool Initialize(const RenderDeviceDriver& driver);

		/**
		* Shutdown the device
		*/
		void Shutdown();

		/**
		* Get the direct3D device
		* @return
		*	ID3D11Device* The d3d device
		*/
		ID3D11Device* GetD3DDevice() const;

		/**
		* Get the device context
		* @return
		*	ID3D11DeviceContext* The device context
		*/
		ID3D11DeviceContext* GetImmediateContext() const;

	private:
		/**
		* The D3D device
		*/
		ID3D11Device* _device;

		/**
		* The immediate context for the device
		*/
		ID3D11DeviceContext* _immediateContext;

		/**
		* The feature level being used for this device
		*/
		D3D_FEATURE_LEVEL _featureLevel;
	};

	/** @} */

}	// Namespace

#endif // __BUFFRENDERDEVICE_H__