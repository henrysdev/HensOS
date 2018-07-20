#include "simulator.h"
#include <map>
#include <sstream>
#include <iostream>


Simulator::Simulator(Scheduler* _scheduler, bool _preemptive)
{
    scheduler = _scheduler;
    preemptive = _preemptive;
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


const bool comp_by_arrival(Pcb* a, Pcb* b)
{
    return a->arrival < b->arrival;
}


float calc_avg_wait(std::vector<int>* wait_times)
{
    float sum = 0.0f;
    for (int i = 0; i < wait_times->size(); i++)
    {
        std::cout << "wait time [" << i << "]: " << wait_times->at(i) << std::endl;
        sum += (float) wait_times->at(i);
    }
    std::cout << "avg: " << sum << "/" << wait_times->size() << std::endl;
    return sum / (float) wait_times->size();
}


float Simulator::simulate(std::vector<Pcb*>* processes)
{
    /* sort by order of arrival time for simulation */
    std::stable_sort(processes->begin(), processes->end(), comp_by_arrival);

    int clock = 0, i = 0, alltime = sum_burst_times(processes);
    bool busy = 0;

    /* keep dictionary of all original burst times by pid for timing */
    std::map<int, int> pid_bursts;
    for (int q = 0; q < processes->size(); q++)
    {
        int pid = processes->at(q)->pid;
        int burst = processes->at(q)->burst;
        pid_bursts[pid] = burst;
    }

    std::vector<int>* wait_times = new std::vector<int>;

    Pcb* currproc = NULL;
    std::vector<Pcb*>* arriving_procs = new std::vector<Pcb*>;

    /* iterate clock until all processes have terminated gracefully */
    while (clock < alltime)
    {
        /* increment through given processes by arrival time */
        if (i < processes->size())
        {
            /* handle arrival time tie edge case*/
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

        /* handle any processes that have arrived at the current clock cycle */
        if (arriving_procs->size() > 0)
        {
            for (int n = 0; n < arriving_procs->size(); n++)
            {
                scheduler->handle(arriving_procs->at(n));
            }
            arriving_procs->clear();
        }

        /* check for process switch applicability */
        if (scheduler->ready_queue->size > 0)
        {
            /* handle idling scenario */
            if (!busy || !currproc)
            {
                currproc = scheduler->ready_queue->head->val;
                scheduler->ready_queue->del(-1);
            }
            /* handle preemptive scenario */
            else if (busy && preemptive)
            {
                /* if process in ready queue has shorter remaining time, switch process */
                Pcb* contender = scheduler->ready_queue->head->val;

                if (scheduler->preemptcomp(currproc, contender)) //if (contender->burst < currproc->burst)
                {
                    /* set process burst equal to its remaining time before putting back in ready queue */
                    scheduler->handle(currproc);
                    currproc = contender;
                    scheduler->ready_queue->del(-1);
                }
            }
        }

        ++clock;
        /* decrement burst time for current process and record wait time if process has terminated */
        if (currproc != NULL)
        {
            --currproc->burst;
            busy = currproc->burst > 0;
            if (currproc->burst == 0)
            {
                int waittime = clock - currproc->arrival - pid_bursts[currproc->pid];
                wait_times->push_back(waittime);
                currproc = NULL;
            }
        }
        else
        {
            busy = 0;
        }
    }

    return calc_avg_wait(wait_times);
}