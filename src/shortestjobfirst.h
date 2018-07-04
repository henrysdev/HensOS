//
// Created by crackerjacks on 7/4/18.
//

#ifndef OS_PROJECT_SHORTESTJOBFIRST_H
#define OS_PROJECT_SHORTESTJOBFIRST_H

#include "scheduler.h"

class Sjf : public Scheduler
{
public:
    Sjf(JobQueue*, JobQueue*);
    void handle(Pcb*);
};

#endif //OS_PROJECT_SHORTESTJOBFIRST_H
