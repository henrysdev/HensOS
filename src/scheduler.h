#ifndef OS_PROJECT_SCHEDULER_H
#define OS_PROJECT_SCHEDULER_H

#include "jobqueue.h"
#include "pcb.h"

class Scheduler
{
protected:
    JobQueue* waiting_queue;
    JobQueue* ready_queue;
public:
    virtual void handle(Pcb* process) = 0;
};

#endif //OS_PROJECT_SCHEDULER_H
