// Filename: BuffJob.h
// Author: Gael Huber
#ifndef __BUFFJOB_H__
#define __BUFFJOB_H__

#include "BuffPrerequisites.h"

namespace BuffaloEngine
{
	/** \addtogroup Core
	*	@{
	*/

	/**
	* An enumerator to represent the state of a task
	*/
	enum JobStatus
	{
		JOB_STATUS_UNSTARTED = 0,
		JOB_STATUS_PENDING,
		JOB_STATUS_PROCESSING,
		JOB_STATUS_DONE,
		JOB_STATUS_FAILED
	};

	/**
	* A job encapsulates a task to be performed by the engine. 
	*/
	class Job : public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		Job();

		/**
		* Destructor
		*/
		virtual ~Job();

		/**
		 * Preprocess a job, this typically involves setting the status from UNSTARTED to PENDING
		 */
		void Preprocess();

		/**
		* Perform the specified job
		* @return
		*	bool Returns true if successful
		*/
		bool Run();

		/**
		* Wait for the job to finish
		*/
		void Wait();

		/**
		* Get the job status
		* @param
		*	JobStatus The current status of the job
		*/
		JobStatus GetJobStatus() const;

	protected:
		/**
		* Implementation for performing a job
		* @return
		*	bool Return true if successful
		*/
		virtual bool RunImpl() = 0;

	private:
		/**
		* The job status
		*/
		JobStatus _jobStatus;
	};

	/** @} */

}	// Namespace

#endif // __BUFFJOBMANAGER_H__