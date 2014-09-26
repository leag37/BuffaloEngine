// Filename: BuffClassDirectory.h
// Author: Gael Huber
#ifndef __BUFFCLASSDIRECTORY_H__
#define __BUFFCLASSDIRECTORY_H__

namespace BuffaloEngine
{
	// Standard classes
	class Camera;
	class Event;
	class EventManager;
	class IEventListener;
	class InputManager;
	class Job;
	class JobManager;
	class Light;
	class RenderComponent;
	class RenderManager;
	class RenderSystem;
	class ScopedLock;

	// Template classes
	template <typename Updateable>
	class UpdaterJob;
}

#endif // __BUFFCLASSDIRECTORY_H__