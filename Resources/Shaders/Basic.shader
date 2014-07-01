# Filename: Basic.shader
# Author: Gael Huber

# The constant buffer for the camera
cbuffer CameraBuffer
{
	float4x4 gWorldViewProj
}

technique
{
	pass
	{
		vertex_shader BasicVS
		pixel_shader BasicPS
	}
}