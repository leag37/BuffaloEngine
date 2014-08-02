// Filename: BuffTechnique.h
// Author: Gael Huber
#ifndef __BUFFTECHNIQUE_H__
#define __BUFFTECHNIQUE_H__

#include "Core\BuffPrerequisites.h"
#include "Rendering\BuffPass.h"

#include <vector>

namespace BuffaloEngine
{
	class RenderDevice;

	/** \addtogroup Rendering
	*	@{
	*/

	/**
	* Techniques represent multi-pass rendering programs and describe the shaders involved in each pass.
	*/
	class Technique : public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		Technique();

		/**
		* Copy constructor
		* @param
		*	const Technique& The technique to copy
		*/
		Technique(const Technique& other);

		/**
		* Destructor
		*/
		~Technique();

		/**
		* Add a pass to the technique
		* @param
		*	const Pass& The pass to add
		*/
		void AddPass(const Pass& pass);

		/**
		* Set a pass at a given index to be active
		* @param
		*	const RenderDevice& The render device used to activate the pass
		* @param
		*	uint The pass index to set as active
		*/
		void ActivatePassAtIndex(const RenderDevice& device, uint index);

		/**
		* Get the pass at a specified index
		* @param
		*	uint The index of the desired pass
		* @return
		*	Pass& The pass at the index
		*/
		Pass& GetPassAtIndex(uint index);

		/**
		* Get the pass at a specified index
		* @param
		*	uint The index of the desired pass
		* @return
		*	const Pass& The pass at the index
		*/
		const Pass& GetPassAtIndex(uint index) const;

	private:
		/**
		* List of passes
		*/
		std::vector<Pass> _passes;
	};

	/** @} */

}	// Namespace

#endif // __BUFFTECHNIQUE_H__