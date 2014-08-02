// Filename: BuffConstantBuffer.h
// Author: Gael Huber
#ifndef __BUFFCONSTANTBUFFER_H__
#define __BUFFCONSTANTBUFFER_H__

#include "Core\BuffPrerequisites.h"
#include "Rendering\BuffHardwareBuffer.h"
#include "Rendering\BuffShaderParameter.h"

#include <string>
#include <vector>

namespace BuffaloEngine
{
	class RenderDevice;

	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* Enumeration specifying the type of constant buffer
	*/
	enum ConstantBufferType
	{
		CONSTANT_BUFFER_TYPE_UNKNOWN,
		CONSTANT_BUFFER_TYPE_OBJECT,
		CONSTANT_BUFFER_TYPE_FRAME,
		CONSTANT_BUFFER_TYPE_MATERIAL,
		CONSTANT_BUFFER_TYPE_IMMUTABLE
	};

	/**
	* Constant buffer class describes GPU program buffers that hold constant data for a rendering pass
	*/
	class ConstantBuffer : public HardwareBuffer
	{
	public:
		/**
		* Constructor
		* @param
		*	const RenderDevice& The render device
		*/
		explicit ConstantBuffer(const RenderDevice& renderDevice);

		/**
		* Destructor
		*/
		~ConstantBuffer();

		/**
		* Initialize the buffer
		* @return
		*	bool Returns true if successfully initialized
		*/
		bool Initialize();

		/**
		* Get the buffer type
		* @return
		*	ConstantBufferType The buffer type
		*/
		ConstantBufferType GetBufferType() const;

		/**
		* Set the constant buffer type
		* @param
		*	ConstantBufferType The buffer type to set this buffer
		*/
		void SetBufferType(ConstantBufferType type);

		/**
		* Add a parameter to the constant buffer definition
		* @param
		*	const ShaderParameter& The parameter to add
		*/
		void AddParameter(const ShaderParameter& parameter);

		/**
		* Get the buffer size
		* @return
		*	uint The size of the buffer contents in bytes
		*/
		uint GetBufferSize() const;

		/**
		* Render the constant buffer
		* @param
		*	const RenderDevice& The render device used to render this buffer
		*/
		void Render(const RenderDevice& device);

		/**
		* Update a parameter by name
		* @param
		*	const std::string& The name of the parameter being updated
		* @param
		*	const ParamType& The data used to update the parameter
		*/
		template <typename ParamType>
		void UpdateParamByName(const std::string& paramName, const ParamType& data)
		{
			// Iterate through each parameter until we find the corresponding name
			for (std::vector<ShaderParameter>::iterator itr = _parameters.begin(); itr != _parameters.end(); ++itr)
			{
				if (itr->GetName() == paramName)
				{
					// Then, get the position in the buffer
					uint offset = itr->GetByteOffset();

					// Update the CPU copy of the buffer
					ParamType* pointer = (ParamType*)&_cpuBuffer[offset];
					*pointer = data;

					// Set has changed to true
					_hasChanged = true;

					// Break from the function
					return;
				}
			}
		}

	private:
		/**
		* The type of the constant buffer
		*/
		ConstantBufferType _type;

		/**
		* List of shader parameters associated with this buffer
		*/
		std::vector<ShaderParameter> _parameters;

		/**
		* Array representing block of memory used by the constant buffer
		*/
		std::vector<char> _cpuBuffer;

		/**
		* A boolean flag to determine whether the buffer has been updated since the last frame
		*/
		bool _hasChanged;

	};

	/**
	* Shared pointer for hardware buffers
	*/
	class ConstantBufferPtr : public HardwareBufferPtr
	{
		/**
		* Constructor
		* @param
		*	ConstantBuffer* The pointer to the constant buffer
		*/
		ConstantBufferPtr(ConstantBuffer* ptr);

		/**
		* Destructor
		*/
		~ConstantBufferPtr();
	};

	/** @} */

}	// Namespace

#endif // __BUFFCONSTANTBUFFER_H__