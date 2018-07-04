#include "pcb.h"


Pcb::Pcb(int _pid)
{
    pid = _pid;
    arrival = 0;
    burst = 1;
    priority = 5;
}

Pcb::Pcb(int _pid, int _arrival, int _burst, int _priority)
{
    pid = _pid;
    arrival = _arrival;
    burst = _burst;
    priority = _priority;
}