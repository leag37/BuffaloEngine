/**
* Default constructor
*/
template <typename Updateable>
UpdaterJob<Updateable>::UpdaterJob()
: _pUpdateable(0)
{

}

/**
* Constructor
* @param pUpdateable The component to update
*/
template <typename Updateable>
UpdaterJob<Updateable>::UpdaterJob(Updateable* pUpdateable)
: _pUpdateable(pUpdateable)
{

}

/**
* Copy constructor
* @param other The job to copy
*/
template <typename Updateable>
UpdaterJob<Updateable>::UpdaterJob(const UpdaterJob& other)
: _pUpdateable(other._pUpdateable)
{

}

/**
* Destructor
*/
template <typename Updateable>
UpdaterJob<Updateable>::~UpdaterJob()
{

}

/**
* Implementation for performing a job
* @return
*	bool Return true if successful
*/
template <typename Updateable>
bool UpdaterJob<Updateable>::RunImpl()
{
	if (_pUpdateable != 0)
	{
		return _pUpdateable->Update();
	}

	return false;
}
