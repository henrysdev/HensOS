#include "simulator.h"
#include <algorithm>
#include <sstream>
#include <iostream>


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


float calc_avg_wait(std::vector<int>* wait_times)
{
    float avg = 0.0f;
    for (int i = 0; i < wait_times->size(); i++)
    {
        std::cout << wait_times->at(i) << std::endl;
        avg += (float) wait_times->at(i);
    }
    return avg / (float) wait_times->size();
}


void Simulator::simulate(std::vector<Pcb*>* processes)
{
    /* sort by order of arrival time for simulation */
    std::stable_sort(processes->begin(), processes->end(), comp_by_arrival);

    int clock = 0, i = 0, deadline = 0;
    bool busy = 0;
    int alltime = sum_burst_times(processes);
    std::vector<int>* wait_times = new std::vector<int>;

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
            /* calculate wait time */
            if (nextproc != NULL)
            {
                int waittime = clock - nextproc->arrival - nextproc->burst;
                wait_times->push_back(waittime);
            }
        }
        if (!busy && scheduler->ready_queue->size > 0)
        {
            nextproc = scheduler->ready_queue->head->val;
            scheduler->ready_queue->del(-1);
            deadline = clock + nextproc->burst;
            busy = 1;
        }
        ++clock;
    }

    std::cout << calc_avg_wait(wait_times) << std::endl;
}