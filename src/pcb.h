#ifndef PCB_H
#define PCB_H

class Pcb {
public:
    Pcb(int);
    Pcb(int, int, int, int);
    int pid;
    int priority;
    int burst;
    int arrival;
};

#endif