#ifndef JOBQUEUE_H
#define JOBQUEUE_H

#include "listnode.h"


class JobQueue {
private:
    int capacity;
public:
    int size;
    ListNode* head;
    ListNode* tail;
    JobQueue(int cap);
    void add(Pcb* pcb, int pos);
    void del(int targ_pid);
    //void print();
};

#endif