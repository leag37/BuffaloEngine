// Filename: BuffCamera.cpp
// Author: Gael Huber
#include "Rendering\BuffCamera.h"
#include "Core\BuffInputEvent.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Camera::Camera()
		:	_forward(0.0f, 0.0f, 1.0f),
			_right(1.0f, 0.0f, 0.0f),
			_up(0.0f, 1.0f, 0.0f)
	{

	}

	/**
	* Constructor. Create a camera with parameters
	* @param fov The field of view of the camera
	* @param aspectRatio The camera aspect ratio
	* @param zNear The near clippin plane on the z-axis
	* @param zFar The far clipping plane on the z-axis
	*/
	Camera::Camera(float fov, float aspectRatio, float zNear, float zFar)
		:	_fov(fov),
			_aspectRatio(aspectRatio),
			_zNear(zNear),
			_zFar(zFar),
			_forward(0.0f, 0.0f, 1.0f),
			_right(1.0f, 0.0f, 0.0f),
			_up(0.0f, 1.0f, 0.0f),
			_position(0.0f, 0.0f, 0.0f),
			_orientation(0.0f, 0.0f, 0.0f)
	{
		// Create projection matrix
		DirectX::XMMATRIX projMatrix = DirectX::XMMatrixPerspectiveFovLH(_fov, _aspectRatio, _zNear, _zFar);
		DirectX::XMStoreFloat4x4(&_projMatrix, projMatrix);

		// Create view matrix
		LookAt(_forward.x, _forward.y, _forward.z);

		_eventListener = EventListener<Camera>(this);
		_eventListener.AddEventListener(InputEvent::TYPE, &Camera::OnInputEvent);

	}

	/**
	* Copy constructor
	* @param other The value to copy
	*/
	Camera::Camera(const Camera& other)
		:	_fov(other._fov),
			_aspectRatio(other._aspectRatio),
			_zNear(other._zNear),
			_zFar(other._zFar),
			_up(other._up),
			_forward(other._forward),
			_right(other._right),
			_position(other._position),
			_orientation(other._orientation),
			_projMatrix(other._projMatrix),
			_viewMatrix(other._viewMatrix)
	{
		_eventListener = EventListener<Camera>(this);
		_eventListener.AddEventListener(InputEvent::TYPE, &Camera::OnInputEvent);
	}

	/**
	* Destructor
	*/
	Camera::~Camera()
	{
		_eventListener.RemoveEventListener(InputEvent::TYPE, &Camera::OnInputEvent);
	}

	/**
	* Assignment operator
	* @param other The camera to copy
	* @return Return the copied camera object
	*/
	Camera& Camera::operator=(const Camera& other)
	{
		// Copy data
		_fov = other._fov;
		_aspectRatio = other._aspectRatio;
		_zNear = other._zNear;
		_zFar = other._zFar;
		_up = other._up;
		_forward = other._forward;
		_right = other._right;
		_position = other._position;
		_orientation = other._orientation;
		_projMatrix = other._projMatrix;
		_viewMatrix = other._viewMatrix;

		// Remove any pending listeners
		_eventListener.RemoveEventListener(InputEvent::TYPE, &Camera::OnInputEvent);

		// Re-initialize the event listeners
		_eventListener = EventListener<Camera>(this);
		_eventListener.AddEventListener(InputEvent::TYPE, &Camera::OnInputEvent);

		return *this;
	}

	/**
	* Apply a yaw to the camera
	* @param yaw The amount of yaw to apply to the camera
	*/
	void Camera::Yaw(float yaw)
	{
		// Increment yaw
		_orientation.x += yaw;

		// Get rotation axis
		DirectX::XMVECTOR up = DirectX::XMLoadFloat3(&_up);
		DirectX::XMMATRIX rotation = DirectX::XMMatrixRotationAxis(up, yaw);

		// Update forward vector
		DirectX::XMVECTOR forward = DirectX::XMLoadFloat3(&_forward);
		forward = DirectX::XMVector3TransformNormal(forward, rotation);
		DirectX::XMStoreFloat3(&_forward, forward);

		// Update right vector
		DirectX::XMVECTOR right = DirectX::XMLoadFloat3(&_right);
		right = DirectX::XMVector3TransformNormal(right, rotation);
		DirectX::XMStoreFloat3(&_right, right);
	}

	/**
	* Apply a pitch to the camera
	* @param pitch The amount of pick to apply to the camera
	*/
	void Camera::Pitch(float pitch)
	{
		// Increment pitch
		_orientation.y += pitch;

		// Get rotation axis
		DirectX::XMVECTOR right = DirectX::XMLoadFloat3(&_right);
		DirectX::XMMATRIX rotation = DirectX::XMMatrixRotationAxis(right, pitch);

		// Update forward vector
		DirectX::XMVECTOR forward = DirectX::XMLoadFloat3(&_forward);
		forward = DirectX::XMVector3TransformNormal(forward, rotation);
		DirectX::XMStoreFloat3(&_forward, forward);

		// Update up vector
		//DirectX::XMVECTOR up = DirectX::XMLoadFloat3(&_right);
		//right = DirectX::XMVector3TransformNormal(right, rotation);
		//DirectX::XMStoreFloat3(&_right, right);
	}

	/**
	* Translate along the right axis
	* @param x The amount by which to translate
	*/
	void Camera::TranslateX(float x)
	{
		// Load position and right
		DirectX::XMVECTOR position = DirectX::XMLoadFloat3(&_position);
		DirectX::XMVECTOR right = DirectX::XMLoadFloat3(&_right);

		// Scale right by translation factor
		right = DirectX::XMVectorScale(right, x);

		// Add to position
		position = DirectX::XMVectorAdd(position, right);

		// Store new position
		DirectX::XMStoreFloat3(&_position, position);
	}

	/**
	* Translate along the forward axis
	* @param z The amount by which to translate
	*/
	void Camera::TranslateZ(float z)
	{
		// Load position and foward
		DirectX::XMVECTOR position = DirectX::XMLoadFloat3(&_position);
		DirectX::XMVECTOR forward = DirectX::XMLoadFloat3(&_forward);

		// Scale forward by translation
		forward = DirectX::XMVectorScale(forward, z);

		// Add to position
		position = DirectX::XMVectorAdd(position, forward);

		// Store new position
		DirectX::XMStoreFloat3(&_position, position);
	}

	/**
	* Look at a target point
	* @param x The x position to look at
	* @param y The y position to look at
	* @param z The z position to look at
	*/
	void Camera::LookAt(float x, float y, float z)
	{
		// Setup the position and look at vector
		DirectX::XMVECTOR lookAt = DirectX::XMVectorSet(x, y, z, 0.0f);
		DirectX::XMVECTOR position = DirectX::XMLoadFloat3(&_position);

		// Get the new forward by subtracting position from lookAt
		DirectX::XMVECTOR forward = DirectX::XMVectorSubtract(lookAt, position);
		forward = DirectX::XMVector3Normalize(forward);
		DirectX::XMStoreFloat3(&_forward, forward);

		// Get the right vector by forward x up
		DirectX::XMVECTOR up = DirectX::XMLoadFloat3(&_up);
		DirectX::XMVECTOR right = DirectX::XMVector3Cross(up, forward);
		right = DirectX::XMVector3Normalize(right);
		DirectX::XMStoreFloat3(&_right, right);
	}

	/**
	* Set the position of the camera
	* @param x The x position
	* @param y The y position
	* @param z The z position
	*/
	void Camera::SetPosition(float x, float y, float z)
	{
		_position = DirectX::XMFLOAT3(x, y, z);
		LookAt(_position.x + _forward.x, _position.y + _forward.y, _position.z + _forward.z);
	}

	/**
	* Get the view matrix
	* @return The Matrix representing the camera view
	*/
	DirectX::XMMATRIX Camera::GetViewProjMatrix()
	{
		// Poll events
		while (_eventListener.Peek())
		{
			_eventListener.Dequeue();
		}

		/*// Create the rotation matrix from the yaw, pitch, and roll values.
		DirectX::XMMATRIX rotationMatrix = DirectX::XMMatrixRotationRollPitchYaw(_orientation.x, _orientation.y, _orientation.z);

		// Transform the lookAt and up vector by the rotation matrix so the view is correctly rotated at the origin.
		// Setup where the camera is looking by default.
		DirectX::XMVECTOR forward = DirectX::XMLoadFloat3(&_forward);
		forward = DirectX::XMVector3TransformCoord(forward, rotationMatrix);
		DirectX::XMVECTOR up = DirectX::XMLoadFloat3(&_up);
		up = DirectX::XMVector3TransformCoord(up, rotationMatrix);

		// Update the right vectors
		DirectX::XMVECTOR right = DirectX::XMLoadFloat3(&_right);
		right = DirectX::XMVector3TransformCoord(right, rotationMatrix);
		DirectX::XMStoreFloat3(&_right, right);

		// Translate the rotated camera position to the location of the viewer.
		DirectX::XMVECTOR position = DirectX::XMLoadFloat3(&_position);*/

		// Get position, forward, and up vectors
		DirectX::XMVECTOR position = DirectX::XMLoadFloat3(&_position);
		DirectX::XMVECTOR forward = DirectX::XMLoadFloat3(&_forward);
		DirectX::XMVECTOR up = DirectX::XMLoadFloat3(&_up);
		forward = DirectX::XMVectorAdd(position, forward);

		// Finally create the view matrix from the three updated vectors.
		DirectX::XMMATRIX viewMatrix = DirectX::XMMatrixLookAtLH(position, forward, up);
		DirectX::XMStoreFloat4x4(&_viewMatrix, viewMatrix);

		// Store proj and view into matrices and return the product
		DirectX::XMMATRIX projMatrix = DirectX::XMLoadFloat4x4(&_projMatrix);
		return DirectX::XMMatrixMultiply(viewMatrix, projMatrix);
	}

	void Camera::OnInputEvent(const Event* evt)
	{
		const InputEvent* iEvt = dynamic_cast<const InputEvent*>(evt);
		if (iEvt->GetAction() == IAT_FORWARD)
		{
			TranslateZ(0.01f);
		}
		else if (iEvt->GetAction() == IAT_BACKWARD)
		{
			TranslateZ(-0.01f);
		}
		else if (iEvt->GetAction() == IAT_STRAFE_LEFT)
		{
			TranslateX(-0.01f);
		}
		else if (iEvt->GetAction() == IAT_STRAFE_RIGHT)
		{
			TranslateX(0.01f);
		}
		else if (iEvt->GetAction() == IAT_TURN)
		{
			Yaw(iEvt->GetX());
			Pitch(iEvt->GetY());
		}
	}
}