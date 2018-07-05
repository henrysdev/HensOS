//
// Created by crackerjacks on 7/4/18.
//

#ifndef OS_PROJECT_PRIORITYSCHEDULER_H
#define OS_PROJECT_PRIORITYSCHEDULER_H

#include "scheduler.h"

class PriorityScheduler : public Scheduler
{
public:
    PriorityScheduler(JobQueue*, JobQueue*);
    void handle(Pcb* process);
    void simulate(std::vector<Pcb*> *processes);
};

#endif //OS_PROJECT_PRIORITYSCHEDULER_H
