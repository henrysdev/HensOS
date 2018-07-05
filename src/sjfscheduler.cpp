#include "sjfscheduler.h"
#include <algorithm>

SjfScheduler::SjfScheduler(JobQueue * _ready_queue, JobQueue * _waiting_queue)
{
    ready_queue = _ready_queue;
    waiting_queue = _waiting_queue;
}


void SjfScheduler::handle(Pcb * process)
{
    if (!ready_queue->size)
    {
        ready_queue->add(process, -1);
        clock += process->burst;
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


const bool compByBurst(Pcb* a, Pcb* b)
{
    return a->burst < b->burst;
}


void SjfScheduler::simulate(std::vector<Pcb*>* processes)
{
    /* sort processes by arrival time before scheduling*/
    std::stable_sort(processes->begin(), processes->end(), compByArrival);
    clock = 0;
    int i = 0;
    /* holds processes arriving at a given clock time */
    std::vector<Pcb*>* arriving_procs = new std::vector<Pcb*>;

    while (i < processes->size())
    {
        while (processes->at(i)->arrival == clock)
        {
            arriving_procs->push_back(processes->at(i));
            ++i;
            if (i >= processes->size())
            {
                break;
            }
        }
        if (arriving_procs->size() > 0)
        {
            /* sort processes with the same arrival time by priority before handling*/
            std::sort(arriving_procs->begin(), arriving_procs->end(), compByBurst);
            for (int n = 0; n < arriving_procs->size(); n++)
            {
                handle(arriving_procs->at(n));
            }
            arriving_procs->clear();
        }
        ++clock;
    }
}