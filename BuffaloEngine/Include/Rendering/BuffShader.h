// Filename: BuffShader.h
// Author: Gael Huber
#ifndef __BUFFSHADER_H__
#define __BUFFSHADER_H__

#include "Core\BuffPrerequisites.h"
#include <string>

namespace BuffaloEngine
{
	class RenderDevice;

	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* The type of shader
	*/
	enum ShaderType
	{
		SHADER_TYPE_VERTEX,
		SHADER_TYPE_PIXEL,
		SHADER_TYPE_GEOMETRY
	};

	/**
	* Encapsulates a single shader program
	*/
	class Shader : public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		Shader();

		/**
		* Constructor
		* @param
		*	const std::string& The name of the shader
		*/
		Shader(const std::string& name);

		/**
		* Destructor
		*/
		virtual ~Shader();

		/**
		* Get the pointer to the shader buffer
		* @param
		*	ID3D10Blob* The shader buffer
		*/
		ID3D10Blob* GetShaderBuffer() const;

	protected:
		/**
		* Initialize the shader
		* @param
		*	const std::string& The shader filename
		* @param
		*	const std::string& The shader entry point
		* @param
		*	const std::string& The shader profile for compilation
		* @param
		*	const RenderDevice& The device used to create the shader
		*/
		void Initialize(const std::string& fileName, const std::string& entryPoint, const std::string& profile, const RenderDevice& device);

		/**
		* Initialization implementation
		* @param
		*	const RenderDevice& The device used to create the shader
		* @return
		*	bool Return true if successful
		*/
		virtual bool InitializeImpl(const RenderDevice& device) = 0;

	protected:
		/**
		* The name of the shader
		*/
		std::string _name;
		
		/**
		* The filename of the shader
		*/
		std::string _filename;

		/**
		* The id of the shader
		*/
		uint _id;

		/**
		* The compiled shader blob
		*/
		ID3D10Blob* _shaderBuffer;

		/**
		* The shader type
		*/
		ShaderType _type;
	};

	/** @} */

}	// Namespace

#endif // __BUFFSHADER_H__