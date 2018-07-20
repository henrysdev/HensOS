//
// Created by crackerjacks on 7/4/18.
//

#ifndef OS_PROJECT_PRIORITYSCHEDULER_H
#define OS_PROJECT_PRIORITYSCHEDULER_H

#include "scheduler.h"

class PriorityScheduler : public Scheduler
{
public:
    PriorityScheduler(JobQueue*);
    void handle(Pcb* process);
    bool preemptcomp(Pcb* defending, Pcb* contending);
};

#endif //OS_PROJECT_PRIORITYSCHEDULER_H
