#include "ganttchart.h"
#include <sstream>
#include <vector>

GanttChart::GanttChart(JobQueue * _queue)
{
    queue = _queue;
}


/*
std::string numtostr(int num)
{
    std::ostringstream ss;
    ss << num;
    return ss.str();
}


std::string GanttChart::buildChart()
{
    std::string linestr;
    int clock = 0;
    ListNode* tmp = queue->head;

    while (tmp)
    {
        linestr += numtostr(clock);
        linestr += " [__";
        linestr += numtostr(tmp->val->pid);
        linestr += "__] ";
        clock += tmp->val->burst;
        tmp = tmp->next;
    }
    linestr += numtostr(clock);

    return linestr;
}
 */