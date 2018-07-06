#include "simulator.h"
#include <sstream>


Simulator::Simulator(Scheduler* _scheduler)
{
    scheduler = _scheduler;
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


const bool comp_by_arrival(Pcb* a, Pcb* b)
{
    return a->arrival < b->arrival;
}


void Simulator::simulate(std::vector<Pcb*>* processes)
{
    /* sort by order of arrival time for simulation */
    std::stable_sort(processes->begin(), processes->end(), comp_by_arrival);

    int clock = 0, i = 0, deadline = 0;
    bool busy = 0;
    int alltime = sum_burst_times(processes);

    Pcb* nextproc = NULL;
    std::vector<Pcb*>* arriving_procs = new std::vector<Pcb*>;

    while (clock < alltime)
    {
        /* increment through given processes by arrival time */
        if (i < processes->size())
        {
            while (processes->at(i)->arrival == clock)
            {
                arriving_procs->push_back(processes->at(i));
                ++i;
                if (i == processes->size())
                {
                    break;
                }
            }
        }
        if (arriving_procs->size() > 0)
        {
            for (int n = 0; n < arriving_procs->size(); n++)
            {
                scheduler->handle(arriving_procs->at(n));
            }
            arriving_procs->clear();
        }

        /* non-preemptive */
        if (clock == deadline)
        {
            busy = 0;
        }
        if (!busy && scheduler->ready_queue->size > 0)
        {
            nextproc = scheduler->ready_queue->head->val;
            scheduler->ready_queue->del(-1);
            // TODO simulate / keep track of process that is executing
            //scheduler->handle(nextproc);
            deadline = clock + nextproc->burst;
            busy = 1;
        }
        ++clock;
    }
}