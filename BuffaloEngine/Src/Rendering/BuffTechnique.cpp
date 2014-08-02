// Filename: BuffTechnique.cpp
// Author: Gael Huber
#include "Rendering\BuffTechnique.h"

#include "Rendering\BuffRenderDevice.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Technique::Technique()
	{

	}

	/**
	* Copy constructor
	* @param
	*	const Technique& The technique to copy
	*/
	Technique::Technique(const Technique& other)
		: _passes(other._passes)
	{

	}

	/**
	* Destructor
	*/
	Technique::~Technique()
	{

	}

	/**
	* Add a pass to the technique
	* @param
	*	const Pass& The pass to add
	*/
	void Technique::AddPass(const Pass& pass)
	{
		_passes.push_back(pass);
	}

	/**
	* Set a pass at a given index to be active
	* @param
	*	const RenderDevice& The render device used to activate the pass
	* @param
	*	uint The pass index to set as active
	*/
	void Technique::ActivatePassAtIndex(const RenderDevice& device, uint index)
	{
		// TODO
		//_passes[index].Activate(device);
	}

	/**
	* Get the pass at a specified index
	* @param
	*	uint The index of the desired pass
	* @return
	*	Pass& The pass at the index
	*/
	Pass& Technique::GetPassAtIndex(uint index)
	{
		return _passes[index];
	}

	/**
	* Get the pass at a specified index
	* @param
	*	uint The index of the desired pass
	* @return
	*	const Pass& The pass at the index
	*/
	const Pass& Technique::GetPassAtIndex(uint index) const
	{
		return _passes[index];
	}
}