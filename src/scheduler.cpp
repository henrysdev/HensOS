#include "scheduler.h"

const bool Scheduler::compByArrival(Pcb* a, Pcb* b)
{
    return a->arrival < b->arrival;
}