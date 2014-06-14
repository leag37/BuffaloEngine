// Filename: BuffJobManager.h
// Author: Gael Huber
#ifndef __BUFFJOBMANAGER_H__
#define __BUFFJOBMANAGER_H__

#include "BuffPrerequisites.h"
#include "BuffSingleton.h"

#include <vector>

namespace BuffaloEngine
{
	// Forward declarations
	class Job;

	/** \addtogroup Core
	*	@{
	*/

	/**
	* Manager for job system. Jobs are enqueued to the system and are processed by the next available thread.
	*/
	class JobManager : public Singleton<JobManager>, public SimpleAlloc
	{
	public:
		/**
		* Default constructor
		*/
		JobManager();

		/**
		* Destructor
		*/
		~JobManager();

		/**
		* Initialize the job manager
		* @return
		*	bool Return true if the initialization succeeded
		*/
		bool Initialize();

		/**
		* Shut down the job manager
		*/
		void Shutdown();

		/**
		* Get the singleton instance
		* @return
		*	JobManager& The instance
		*/
		static JobManager& GetSingleton();

		/**
		* Get the pointer to the singleton instance
		* @return
		*	JobManager* Pointer to the singleton instance
		*/
		static JobManager* GetSingletonPtr();

		/**
		* Add a job to the queue
		* @param
		*	Job* The job to be added to the queue
		*/
		bool AddJob(Job* job);

		/**
		* Get a job from the manager
		* @param
		*	Job** The job to perform
		* @return
		*	bool Return true if a job was successfully acquired
		*/
		bool GetJob(Job** job);

	private:
		/**
		* The job queue
		*/
		std::vector<Job*> _jobQueue;
	};

	

	/** @} */

}	// Namespace

#endif // __BUFFJOBMANAGER_H__