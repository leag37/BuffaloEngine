// Filename: BuffJobManager.cpp
// Author: Gael Huber
#include "Core\BuffJobManager.h"
#include "Core\BuffJob.h"

namespace BuffaloEngine
{
	/* Default constructor
	*/
	JobManager::JobManager()
	{
	}

	/**
	* Destructor
	*/
	JobManager::~JobManager()
	{
	}

	/**
	* Initialize the job manager
	* @return
	*	bool Return true if the initialization succeeded
	*/
	bool JobManager::Initialize()
	{
		// TODO
		return true;
	}

	/**
	* Shut down the application
	*/
	void JobManager::Shutdown()
	{
	}

	/**
	* Get the singleton instance
	* @return
	*	JobManager& The instance
	*/
	JobManager& JobManager::GetSingleton()
	{
		return *_instance;
	}

	/**
	* Get the pointer to the singleton instance
	* @return
	*	JobManager* Pointer to the singleton instance
	*/
	JobManager* JobManager::GetSingletonPtr()
	{
		return _instance;
	}

	/**
	* Add a job to the queue
	* @param
	*	Job* The job to be added to the queue
	*/
	bool JobManager::AddJob(Job* job)
	{
		job->Preprocess();
		_jobQueue.push_back(job);
		return true;
	}

	/**
	* Get a job from the manager
	* @param
	*	Job** The job to perform
	* @return
	*	bool Return true if a job was successfully acquired
	*/
	bool JobManager::GetJob(Job** job)
	{
		// If there is a job, pop it from the list
		if(_jobQueue.size() > 0)
		{
			// Pop a job from the queue
			std::vector<Job*>::iterator jobItr = _jobQueue.begin();
			*job = *jobItr;
			_jobQueue.erase(jobItr);
		}
		else
		{
			return false;
		}

		return true;
	}

}	// Namespace
