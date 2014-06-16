// Filename: BuffRenderDeviceDriver.h
// Author: Gael Huber
#ifndef __BUFFRENDERDEVICEDRIVER_H__
#define __BUFFRENDERDEVICEDRIVER_H__

#include "Core\BuffPrerequisites.h"

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* A render device driver owns adapter information for a particular hardware or software graphics interface.
	* The driver has information available about available memory and target feature sets.
	*/
	class RenderDeviceDriver : public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		RenderDeviceDriver();

		/**
		* Constructor
		* @param
		*	IDXGIAdapter* The adapter representing this driver
		*/
		RenderDeviceDriver(IDXGIAdapter* adapter);

		/**
		* Copy constructor
		* @param
		*	const RenderDeviceDriver& The driver to copy
		*/
		RenderDeviceDriver(const RenderDeviceDriver& other);

		/**
		* Destructor
		*/
		~RenderDeviceDriver();

		/**
		* Assignment operator
		* @param
		*	const RenderDeviceDriver& The driver to copy
		* @return
		*	RenderDeviceDriver& The resultant driver
		*/
		RenderDeviceDriver& operator=(const RenderDeviceDriver& other);

		/**
		* Get the adpater for the driver
		* @return
		*	const IDXGIAdapter* The adapter attached to this driver
		*/
		IDXGIAdapter* GetAdapter() const;

	private:
		/**
		* The adapter for the driver
		*/
		IDXGIAdapter* _adapter;

		/**
		* Adapter description
		*/
		DXGI_ADAPTER_DESC _adapterDescription;
	};

	/** @} */
}	// Namespace

#endif // __BUFFRENDERDEVICEDRIVER_H__