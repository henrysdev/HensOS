#ifndef OS_PROJECT_SCHEDULER_H
#define OS_PROJECT_SCHEDULER_H

#include <vector>
#include "jobqueue.h"
#include "pcb.h"

class Scheduler
{
public:
    JobQueue* waiting_queue;
    JobQueue* ready_queue;
    virtual void handle(Pcb* process) = 0;
};

#endif //OS_PROJECT_SCHEDULER_H
