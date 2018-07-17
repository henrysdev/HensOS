#include "srtfscheduler.h"


SrtfScheduler::SrtfScheduler(JobQueue * _ready_queue, JobQueue * _waiting_queue)
{
    ready_queue = _ready_queue;
    waiting_queue = _waiting_queue;
}


void SrtfScheduler::handle(Pcb * process)
{
    if (!ready_queue->size)
    {
        ready_queue->add(process, -1);
        return;
    }

    ListNode* tmp = ready_queue->head;
    int pos = 0;

    /* place process in appropriate position in the
     * ready queue based on burst time */
    while (tmp->next)
    {
        /* if new process has shorter burst time,
         * add at the correct pos */
        if (process->burst < tmp->val->burst)
        {
            ready_queue->add(process, pos);
            return;
        }
        tmp = tmp->next;
        ++pos;
    }
    if (process->burst < tmp->val->burst)
    {
        ready_queue->add(process, pos);
        return;
    }

    /* add to end of queue by default */
    ready_queue->add(process, -1);
}