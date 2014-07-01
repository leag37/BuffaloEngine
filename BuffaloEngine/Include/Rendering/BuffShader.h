// Filename: BuffShader.h
// Author: Gael Huber
#ifndef __BUFFSHADER_H__
#define __BUFFSHADER_H__

#include "Core\BuffPrerequisites.h"
#include <string>

namespace BuffaloEngine
{
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

	private:
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
		ID3D10Blob* _shader;

		/**
		* The shader type
		*/
		ShaderType _type;
	};

	/** @} */

}	// Namespace

#endif // __BUFFSHADER_H__