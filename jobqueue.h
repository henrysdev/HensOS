#ifndef JOBQUEUE_H
#define JOBQUEUE_H

#include "listnode.h"


class JobQueue
{
private:
    int capacity;
    int length;
    ListNode* head;
    ListNode* tail;
public:
    JobQueue(int cap);
    void add(int pos, int pid);
    void del(int targ_pid);
    void print();
};

#endif