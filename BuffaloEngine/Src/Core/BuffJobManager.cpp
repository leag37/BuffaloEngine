// Filename: BuffJobManager.cpp
// Author: Gael Huber
#include "Core\BuffJobManager.h"
#include "Core\BuffJob.h"
#include "Core\BuffScopedLock.h"

namespace BuffaloEngine
{
	/**
	 * Declaration for ThreadWorker method
	 */
	DWORD WINAPI WorkerThread(LPVOID lpParam);

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
		// Create the critical section
		InitializeCriticalSection(&_criticalSection);

		// Set the manager to running
		_isRunning = true;

		// Create a list of threads (4 for now)
		for (int i = 0; i < 1; ++i)
		{
			_threads.push_back(
				CreateThread(
				NULL,			// default security attributes
				0,				// default stack size
				WorkerThread,	// thread function
				NULL,			// arguments to pass to thread
				0,				// default creation flags
				0				// returns thread identifier
				));
		}
		return true;
	}

	/**
	* Shut down the application
	*/
	void JobManager::Shutdown()
	{
		// Set the job manager to ended
		_isRunning = false;

		// Wait for each thread to exit
		for (uint i = 0; i < _threads.size(); ++i)
		{
			WaitForSingleObject(_threads[i], INFINITE);
		}

		// Delete the critical section
		DeleteCriticalSection(&_criticalSection);
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

		// Lock the critical section
		ScopedLock scopedLock(&_criticalSection);

		// Add the job to the queue
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
			// Lock the critical section
			ScopedLock scopedLock(&_criticalSection);

			if (_jobQueue.size() > 0)
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
		}
		else
		{
			return false;
		}

		return true;
	}

	/**
	* @return Returns the current state of the job manager
	*/
	bool JobManager::IsRunning() const
	{
		return _isRunning;
	}

	/**
	* Declaration for ThreadWorker method
	*/
	DWORD WINAPI WorkerThread(LPVOID lpParam)
	{
		// Get a pointer to the job manager
		JobManager* jobManager = JobManager::GetSingletonPtr();
		Job* job = 0;

		while (jobManager->IsRunning())
		{
			// Get a job from the queue
			if (jobManager->GetJob(&job))
			{
				job->Run();
			}
			else
			{
				Sleep(10);
			}
		}

		return 0;
	}


}	// Namespace
