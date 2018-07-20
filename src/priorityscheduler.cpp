#include "priorityscheduler.h"


PriorityScheduler::PriorityScheduler(JobQueue * _ready_queue)
{
    ready_queue   = _ready_queue;
}


bool PriorityScheduler::preemptcomp(Pcb *defending, Pcb *contending)
{
    return contending->priority < defending->priority;
}


void PriorityScheduler::handle(Pcb * process)
{
    if (!ready_queue->size)
    {
        ready_queue->add(process, -1);
        return;
    }

    ListNode* tmp = ready_queue->head;
    int pos = 0;

    /* place process in appropriate position in the
     * ready queue based on priority */
    while (tmp->next)
    {
        /* if new process has higher priority,
         * add at the correct pos */
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