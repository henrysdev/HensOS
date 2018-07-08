#ifndef OS_PROJECT_SIMULATOR_H
#define OS_PROJECT_SIMULATOR_H

#include "scheduler.h"

class Simulator
{
private:
    Scheduler* scheduler;
public:
    Simulator(Scheduler* scheduler);
    void simulate(std::vector<Pcb*>* processes);
};

#endif //OS_PROJECT_SIMULATOR_H
