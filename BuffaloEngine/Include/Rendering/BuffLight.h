// Filename: BuffLight.h
// Author: Gael Huber
#ifndef __BUFFLIGHT_H__
#define __BUFFLIGHT_H__

#include "Core\BuffPrerequisites.h"

namespace BuffaloEngine
{
	/** \addtogroup Rendering
	 *	@{
	 */

	class Light : public SimpleAlloc
	{
	public:

	private:
		/**
		 * Ambient term
		 */
		DirectX::XMFLOAT4 _ambient;

		/**
		 * Diffuse term
		 */
		DirectX::XMFLOAT4 _diffuse;

		/**
		 * Specular term
		 */
		DirectX::XMFLOAT4 _specular;

		/**
		 * Position
		 */
		DirectX::XMFLOAT3 _position;

		/**
		 * Attenuation
		 */
		float _attenuation;
	};

	/** @} */
}

#endif // __BUFFLIGHT_H__