#include "priorityscheduler.h"

PriorityScheduler::PriorityScheduler(JobQueue * _ready_queue, JobQueue * _waiting_queue)
{
    ready_queue   = _ready_queue;
    waiting_queue = _waiting_queue;
}


void PriorityScheduler::handle(Pcb * process)
{
    if (!ready_queue->length)
    {
        ready_queue->add(process, -1);
        return;
    }

    ListNode* tmp = ready_queue->head;
    int pos = 0;

    while (tmp->next)
    {
        /* if new process has shorter burst time, add at the correct pos */
        if (process->priority < tmp->val->priority)
        {
            ready_queue->add(process, pos);
            return;
        }
        tmp = tmp->next;
        ++pos;
    }
    if (process->priority < tmp->val->priority)
    {
        ready_queue->add(process, pos);
        return;
    }

    /* add to end of queue by default */
    ready_queue->add(process, -1);
}