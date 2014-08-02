// Filename: BuffPass.cpp
// Author: Gael Huber
#include "Rendering\BuffPass.h"

#include "Rendering\BuffRenderDevice.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Pass::Pass()
	{

	}

	/**
	* Destructor
	*/
	Pass::~Pass()
	{

	}

	/**
	* Set the vertex shader
	* @param
	*	VertexShader* The vertex shader for this pass
	*/
	void Pass::SetVertexShader(VertexShader* shader)
	{
		_vertexShader = shader;
	}

	/**
	* Get the vertex shader
	* @return
	*	VertexShader* The vertex shader
	*/
	VertexShader* Pass::GetVertexShader() const
	{
		return _vertexShader;
	}

	/**
	* Set the pixel shader
	* @param
	*	PixelShader* The pixel shader for this pass
	*/
	void Pass::SetPixelShader(PixelShader* shader)
	{
		_pixelShader = shader;
	}

	/**
	* Set the pass as the active pass
	* @param
	*	const RenderDevice& The render device used to render the pass
	*/
	void Pass::SetActive(const RenderDevice& device) const
	{
		ID3D11DeviceContext* context = device.GetImmediateContext();

		context->VSSetShader(_vertexShader->GetShader(), NULL, 0);
		context->PSSetShader(_pixelShader->GetShader(), NULL, 0);
	}

}	// Namespace