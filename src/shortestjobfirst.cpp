#include "shortestjobfirst.h"


Sjf::Sjf(JobQueue * rq, JobQueue * wq)
{
    ready_queue = rq;
    waiting_queue = wq;
}


void Sjf::handle(Pcb * process)
{
    ListNode* tmp = ready_queue->head;
    int pos = 0;

    while (tmp->next)
    {
        if (process->burst < tmp->val->burst)
        {
            ready_queue->add(process, pos);
        }
        tmp = tmp->next;
        ++pos;
    }
    // fit process into waiting queue
}