// Filename: Camera.hlsl
// Author: Gael Huber

#include "Camera.hlsl"

// Camera buffer
cbuffer CameraBuffer
{
	matrix worldViewProj;
};