//
// Created by crackerjacks on 7/16/18.
//

#ifndef OS_PROJECT_SRTFSCHEDULER_H
#define OS_PROJECT_SRTFSCHEDULER_H

#include "scheduler.h"

class SrtfScheduler : public Scheduler
{
public:
    SrtfScheduler(JobQueue*, JobQueue*);
    void handle(Pcb* process);
};

#endif //OS_PROJECT_SRTFSCHEDULER_H
