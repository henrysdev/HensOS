#include "shortestjobfirst.h"


Sjf::Sjf(JobQueue * rq, JobQueue * wq)
{
    ready_queue = rq;
    waiting_queue = wq;
}


void Sjf::handle(Pcb * process)
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