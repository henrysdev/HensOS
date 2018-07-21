#ifndef OS_PROJECT_SIMULATOR_H
#define OS_PROJECT_SIMULATOR_H

#include "scheduler.h"

class Simulator {
private:
    Scheduler* scheduler;
public:
    bool preemptive;
    Simulator(Scheduler* scheduler, bool preemptive);
    float simulate(std::vector<Pcb*>* processes);
};

#endif //OS_PROJECT_SIMULATOR_H
