#include "priorityscheduler.h"


PriorityScheduler::PriorityScheduler(JobQueue * _ready_queue)
{
    ready_queue  = _ready_queue;
}

void PriorityScheduler::handle(Pcb * process)
{
    /* add process at head if ready queue is empty */
    if (!ready_queue->size)
    {
        ready_queue->add(process, -1);
        return;
    }

    /* place process in appropriate position in the
     * ready queue based on priority */
    ListNode* currnode = ready_queue->head;
    int pos = 0;
    while (currnode)
    {
        /* if new process has higher priority,
         * add at the correct pos */
        if (process->priority < currnode->val->priority)
        {
            ready_queue->add(process, pos);
            return;
        }
        currnode = currnode->next;
        ++pos;
    }

    /* add to end of queue by default */
    ready_queue->add(process, -1);
}

bool PriorityScheduler::preemptcomp(Pcb *curr, Pcb *next)
{
    return next->priority < curr->priority;
}