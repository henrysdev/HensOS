#include "sjfscheduler.h"
#include <algorithm>


#include <string>
#include <sstream>
#include <iostream>


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
        return;
    }

    ListNode *tmp = ready_queue->head;
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


const int sum_burst_times (std::vector<Pcb*>* procs)
{
    int sum = 0;
    for (int i = 0; i < procs->size(); i++)
    {
        sum += procs->at(i)->burst;
        sum += procs->at(i)->arrival;
    }
    return sum;
}


std::string numtostr(int num)
{
    std::ostringstream ss;
    ss << num;
    return ss.str();
}


void SjfScheduler::simulate(std::vector<Pcb*>* processes)
{
    /* sort by order of arrival time for simulation */
    std::stable_sort(processes->begin(), processes->end(), compByArrival);
    clock = 0;
    std::string linestr = "\n ";
    std::string timestr = "";
    int i = 0;
    std::vector<Pcb*>* arriving_procs = new std::vector<Pcb*>;
    int alltime = sum_burst_times(processes);
    bool busy = 0;
    int deadline = 0;
    Pcb* nextproc = NULL;

    while (clock < alltime)
    {
        /* increment through given processes by arrival time */
        if (i < processes->size())
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
        }
        if (arriving_procs->size() > 0)
        {
            //std::sort(arriving_procs->begin(), arriving_procs->end(), compByBurst);
            for (int n = 0; n < arriving_procs->size(); n++)
            {
                handle(arriving_procs->at(n));
            }
            arriving_procs->clear();
        }

        /* non-preemptive */
        if (clock == deadline)
        {
            timestr += numtostr(clock);
            busy = 0;
        }
        if (!busy && ready_queue->size > 0)
        {
            nextproc = ready_queue->head->val;
            ready_queue->del(-1);
            // TODO simulate / keep track of process that is executing
            //handle(nextproc);
            deadline = clock + nextproc->burst;
            busy = 1;
        }

        if (busy)
        {
            linestr += numtostr(nextproc->pid)[0];
            linestr += " ";
        }
        else
        {
            linestr += "_ ";
        }
        ++clock;
        timestr += " ";
    }

    std::cout << linestr << std::endl;
    std::cout << timestr << std::endl;
}