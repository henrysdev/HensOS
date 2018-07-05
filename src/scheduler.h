#ifndef OS_PROJECT_SCHEDULER_H
#define OS_PROJECT_SCHEDULER_H

#include <vector>
#include "jobqueue.h"
#include "pcb.h"

class Scheduler
{
protected:
    JobQueue* waiting_queue;
    JobQueue* ready_queue;
    int clock;
    const static bool compByArrival(Pcb* a, Pcb* b);
public:
    virtual void handle(Pcb* process) = 0;
    virtual void simulate(std::vector<Pcb*>* processes) = 0;
};

#endif //OS_PROJECT_SCHEDULER_H
