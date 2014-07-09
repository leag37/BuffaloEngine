// Filename: Basic.hlsl
// Author: Gael Huber

cbuffer Camera
{
	matrix gWorldViewProj;
};

// Texture sampling
Texture2D shaderTexture;
SamplerState shaderSampler;

struct VertexInput
{
	float3 position : POSITION;
	float3 norm : NORMAL;
	float2 texCoord : TEXCOORD;
};

struct PixelInput
{
	float4 position : SV_POSITION;
	float2 texCoord : TEXCOORD;
};

PixelInput BasicVS(VertexInput input)
{
	PixelInput output;
	output.position = mul(float4(input.position, 1.0f), gWorldViewProj);
	output.texCoord = input.texCoord;
	return output;
}

float4 BasicPS(PixelInput input) : SV_TARGET
{
	// Sample the texture
	float4 textureColor = shaderTexture.Sample(shaderSampler, input.texCoord);
	return textureColor;

	//return float4(1.0f, 1.0f, 0.0f, 1.0f);

	//input.position = normalize(input.position);
	//input.position.w = 1.0f;
	//return float4(1.0f, 0.0f, 0.0f, 1.0f);//input.position;
}