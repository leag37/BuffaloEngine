// Filename: BuffCamera.h
// Author: Gael Huber
#ifndef __BUFFCAMERA_H__
#define __BUFFCAMERA_H__

#include "Core\BuffPrerequisites.h"
#include "Core\BuffEventListener.h"

namespace BuffaloEngine
{
	/**
	* A camera can be used to target a viewport and navigate a scene
	*/
	class Camera : public SimpleAlloc
	{
	public:
		/**
		 * Default constructor
		 */
		Camera();

		/**
		 * Constructor. Create a camera with parameters
		 * @param fov The field of view of the camera
		 * @param aspectRatio The camera aspect ratio
		 * @param zNear The near clippin plane on the z-axis
		 * @param zFar The far clipping plane on the z-axis
		 */
		Camera(float fov, float aspectRatio, float zNear, float zFar);

		/**
		 * Copy constructor
		 * @param other The value to copy
		 */
		Camera(const Camera& other);

		/**
		 * Destructor
		 */
		~Camera();

		/**
		 * Assignment operator
		 * @param other The camera to copy
		 * @return Return the copied camera object
		 */
		Camera& operator=(const Camera& other);

		/**
		 * Apply a yaw to the camera
		 * @param yaw The amount of yaw to apply to the camera
		 */
		void Yaw(float yaw);

		/**
		 * Apply a pitch to the camera
		 * @param pitch The amount of pick to apply to the camera
		 */
		void Pitch(float pitch);

		/**
		 * Translate along the right axis
		 * @param x The amount by which to translate
		 */
		void TranslateX(float x);

		/**
		 * Translate along the forward axis
		 * @param z The amount by which to translate
		 */
		void TranslateZ(float z);

		/**
		 * Look at a target point
		 * @param x The x position to look at
		 * @param y The y position to look at
		 * @param z The z position to look at
		 */
		void LookAt(float x, float y, float z);

		/**
		 * Set the position of the camera
		 * @param x The x position
		 * @param y The y position
		 * @param z The z position
		 */
		void SetPosition(float x, float y, float z);

		/**
		 * Get the view matrix
		 * @return The Matrix representing the camera view
		 */
		DirectX::XMMATRIX GetViewProjMatrix();

	private:
		void OnInputEvent(const Event* evt);

	private:
		/**
		 * Field of view
		 */
		float _fov;

		/** 
		 * The camera aspect ratio
		 */
		float _aspectRatio;

		/**
		 * Near clipping plane
		 */
		float _zNear;

		/**
		 * Far clipping plane
		 */
		float _zFar;

		/**
		 * Up direction vector
		 */
		DirectX::XMFLOAT3 _up;

		/**
		 * Forward direction vector
		 */
		DirectX::XMFLOAT3 _forward;

		/**
		 * Right direction vector
		 */
		DirectX::XMFLOAT3 _right;

		/**
		 * Position vector
		 */
		DirectX::XMFLOAT3 _position;

		/**
		 * Orientation
		 */
		DirectX::XMFLOAT3 _orientation;

		/**
		 * The projection matrix
		 */
		DirectX::XMFLOAT4X4 _projMatrix;

		/**
		 * The view matrix
		 */
		DirectX::XMFLOAT4X4 _viewMatrix;

		/**
		* Event listener
		*/
		EventListener<Camera> _eventListener;

	};

}	// Namespace

#endif // __BUFFCAMERA_H__