// Filename: Basic.hlsl
// Author: Gael Huber

cbuffer Camera
{
	matrix gWorldViewProj;
};

struct VertexInput
{
	float3 position : POSITION;
	float3 norm : NORMAL;
	float2 texCoord : TEXCOORD;
};

struct PixelInput
{
	float4 position : SV_POSITION;
};

PixelInput BasicVS(VertexInput input)
{
	PixelInput output;
	output.position = mul(float4(input.position, 1.0f), gWorldViewProj);
	return output;
}

float4 BasicPS(PixelInput input) : SV_TARGET
{
	return float4(1.0f, 1.0f, 0.0f, 1.0f);

	//input.position = normalize(input.position);
	//input.position.w = 1.0f;
	//return float4(1.0f, 0.0f, 0.0f, 1.0f);//input.position;
}