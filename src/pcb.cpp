#include "pcb.h"


Pcb::Pcb(int _pid)
{
    pid = _pid;
    priority = 5;
    burst = 1;
    arrival = 0;
}

Pcb::Pcb(int _pid, int _priority, int _burst, int _arrival)
{
    pid = _pid;
    priority = _priority;
    burst = _burst;
    arrival = _arrival;
}