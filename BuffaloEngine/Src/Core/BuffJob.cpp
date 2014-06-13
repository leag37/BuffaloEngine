// Filename: BuffJob.cpp
// Author: Gael Huber
#include "Core\BuffJob.h"
#include "Core\BuffJobManager.h"

namespace BuffaloEngine
{
	/**
	* Default constructor
	*/
	Job::Job()
		:	_jobStatus(JOB_STATUS_PENDING)
	{
	}

	/**
	* Destructor
	*/
	Job::~Job()
	{
	}

	/**
	* Perform the specified job
	* @return
	*	bool Returns true if successful
	*/
	bool Job::Run()
	{
		// Set the status to PROCESSING
		_jobStatus = JOB_STATUS_PROCESSING;

		// Perform the job, if it fails set the status to failed
		bool success = RunImpl();
		if(success == false)
		{
			_jobStatus = JOB_STATUS_FAILED;
		}
		else
		{
			_jobStatus = JOB_STATUS_DONE;
		}

		return success;
	}

	/**
	* Wait for the job to finish
	*/
	void Job::Wait()
	{
		// Try to get a job from the queue
		JobManager* jobManager = JobManager::GetSingletonPtr();
		
		// While the job is not finished or failed, perform another job from the queue
		while(_jobStatus != JOB_STATUS_DONE && _jobStatus != JOB_STATUS_FAILED)
		{
			Job* job = 0;
			if(jobManager->GetJob(&job) == true)
			{
				job->Run();
			}
			else
			{
				// No jobs to perform, sleep for 10 milliseconds
				Sleep(10);
			}
		}
	}

	/**
	* Get the job status
	* @param
	*	JobStatus The current status of the job
	*/
	JobStatus Job::GetJobStatus() const
	{
		return _jobStatus;
	}

}	// Namespace