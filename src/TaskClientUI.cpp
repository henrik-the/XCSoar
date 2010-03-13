#include "TaskClientUI.hpp"


TaskAdvance::TaskAdvanceMode_t 
TaskClientUI::get_advance_mode() const
{
  ScopeLock lock(mutex);
  return task_manager.get_task_advance().get_mode();
}

void 
TaskClientUI::set_advance_mode(TaskAdvance::TaskAdvanceMode_t the_mode)
{
  ScopeLock lock(mutex);
  task_manager.get_task_advance().set_mode(the_mode);
}

void 
TaskClientUI::set_advance_armed(const bool do_armed)
{
  ScopeLock lock(mutex);
  task_manager.get_task_advance().set_armed(do_armed);
}

bool 
TaskClientUI::is_advance_armed() const
{
  ScopeLock lock(mutex);
  return task_manager.get_task_advance().is_armed();
}

bool 
TaskClientUI::toggle_advance_armed()
{
  ScopeLock lock(mutex);
  return task_manager.get_task_advance().toggle_armed();
}


GlidePolar 
TaskClientUI::get_safety_polar() const
{
  ScopeLock lock(mutex);
  return task_manager.get_safety_polar();
}


const Waypoint* 
TaskClientUI::getActiveWaypoint() const
{
  ScopeLock lock(mutex);
  TaskPoint* tp = task_manager.getActiveTaskPoint();
  if (tp) {
    return &tp->get_waypoint();
  } else {
    return NULL;
  }
}


void 
TaskClientUI::incrementActiveTaskPoint(int offset)
{
  ScopeLock lock(mutex);
  task_manager.incrementActiveTaskPoint(offset);
}


TaskManager::TaskMode_t 
TaskClientUI::get_mode() const
{
  ScopeLock lock(mutex);
  return task_manager.get_mode();
}

bool 
TaskClientUI::do_goto(const Waypoint & wp)
{
  ScopeLock lock(mutex);
  return task_manager.do_goto(wp);
}

void 
TaskClientUI::abort()
{
  ScopeLock lock(mutex);
  task_manager.abort();
}

void 
TaskClientUI::resume()
{
  ScopeLock lock(mutex);
  task_manager.resume();
}


AIRCRAFT_STATE 
TaskClientUI::get_start_state() const
{
  ScopeLock lock(mutex);
  return task_manager.get_start_state();
}

fixed 
TaskClientUI::get_finish_height() const
{
  ScopeLock lock(mutex);
  return task_manager.get_finish_height();
}


const TracePointVector 
TaskClientUI::get_trace_points()
{
  ScopeLock lock(mutex);
  return task_manager.get_trace_points();
}

const TracePointVector 
TaskClientUI::get_olc_points()
{
  ScopeLock lock(mutex);
  return task_manager.get_olc_points();
}


bool 
TaskClientUI::check_ordered_task() const
{
  ScopeLock lock(mutex);
  return task_manager.check_ordered_task();
}

bool 
TaskClientUI::check_task() const
{
  ScopeLock lock(mutex);
  return task_manager.check_task();
}


GEOPOINT 
TaskClientUI::get_task_center(const GEOPOINT& fallback_location) const
{
  ScopeLock lock(mutex);
  return task_manager.get_task_center(fallback_location);
}

fixed 
TaskClientUI::get_task_radius(const GEOPOINT& fallback_location) const
{
  ScopeLock lock(mutex);
  return task_manager.get_task_radius(fallback_location);
}


void 
TaskClientUI::Accept(BaseVisitor& visitor) const
{
  ScopeLock lock(mutex);
  task_manager.Accept(visitor);
}

void 
TaskClientUI::ordered_Accept(BaseVisitor& visitor) const
{
  ScopeLock lock(mutex);
  task_manager.ordered_Accept(visitor);
}


AbstractTaskFactory* 
TaskClientUI::get_factory()
{
  ScopeLock lock(mutex);
  return task_manager.get_factory();
}


TracePointVector 
TaskClientUI::find_trace_points(const GEOPOINT &loc, 
                                const fixed range,
                                const unsigned mintime, 
                                const fixed resolution) const
{
  ScopeLock lock(mutex);
  return task_manager.find_trace_points(loc, range, mintime, resolution);
}

