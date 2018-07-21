//
// Created by crackerjacks on 7/4/18.
//

#ifndef OS_PROJECT_SHORTESTJOBFIRST_H
#define OS_PROJECT_SHORTESTJOBFIRST_H

#include "scheduler.h"

class SjfScheduler : public Scheduler {
public:
    SjfScheduler(JobQueue*);
    void handle(Pcb* process);
    bool preemptcomp(Pcb* defending, Pcb* contending);
};

#endif //OS_PROJECT_SHORTESTJOBFIRST_H
