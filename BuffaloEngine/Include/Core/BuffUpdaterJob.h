// Filename: BuffUpdateJob.h
// Author: Gael Huber
#ifndef __BUFFUPDATERJOB_H__
#define __BUFFUPDATERJOB_H__

#include "Core\BuffPrerequisites.h"
#include "Core\BuffJob.h"

namespace BuffaloEngine
{
	/** \addtogroup Core
	 *	@{
	 */

	/**
	 * This job forms a contract to perform invoke a function Update() on the
	 * target object
	 */
	template <typename Updateable>
	class UpdaterJob : public Job
	{
	public:
		/**
		 * Default constructor
		 */
		UpdaterJob();

		/**
		 * Constructor
		 * @param pUpdateable The component to update
		 */
		UpdaterJob(Updateable* pUpdateable);

		/**
		 * Copy constructor
		 * @param other The job to copy
		 */
		UpdaterJob(const UpdaterJob& other);

		/** 
		 * Destructor
		 */
		~UpdaterJob();

	protected:
		/**
		* Implementation for performing a job
		* @return
		*	bool Return true if successful
		*/
		bool RunImpl();

	private:
		/**
		 * The target updatable object
		 */
		Updateable* _pUpdateable;
	};

	#include "Core\BuffUpdaterJob.inl"

	/** @} */
}

#endif // __BUFFUPDATERJOB_H__