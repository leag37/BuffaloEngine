// Filename: BuffShaderManager.h
// Author: Gael Huber
#ifndef __BUFFSHADERMANAGER_H__
#define __BUFFSHADERMANAGER_H__

#include "Core\BuffPrerequisites.h"
#include "Core\BuffSingleton.h"
#include "Rendering\BuffVertexShader.h"

#include <unordered_map>
#include <string>

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* Owner for all shader resources and owner for creating and maintaining them.
	*/
	class ShaderManager : public Singleton<ShaderManager>, public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		ShaderManager();

		/**
		* Copy constructor
		* @param
		*	const ShaderManager& The manager to copy
		*/
		ShaderManager(const ShaderManager& other);
		
		/**
		* Destructor
		*/
		~ShaderManager();

		/**
		* Get a vertex shader program
		* @param
		*	const std::string& The filename containing the shader
		* @param
		*	const std::string& The name of the shader
		* @return
		*	VertexShaderPtr The shader program
		*/

	private:
		/**
		* Create the vertex shader
		*/

	private:
	};

	/** @} */

}	// Namespace

#endif // __BUFFSHADERMANAGER_H__