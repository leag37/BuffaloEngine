// Filename: ColorShader.hlsl
// Author: Gael Huber

struct VertexInput
{
	float4 position : POSITION;	
};

struct PixelInput
{
	float4 position : SV_POSITION;	
};

PixelInput ColorVertexShader(VertexInput input)
{
	PixelInput output;
	output.position = input.position;
	return output;
}

float4 ColorPixelShader(PixelInput input) : COLOR
{
	return saturate(float4(1, 1, 1, 1) / position);
}