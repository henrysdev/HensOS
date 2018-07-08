//
// Created by crackerjacks on 7/4/18.
//

#ifndef OS_PROJECT_GANTTCHART_H
#define OS_PROJECT_GANTTCHART_H

#include <string>
#include "jobqueue.h"

class GanttChart
{
private:
    JobQueue* queue;
public:
    GanttChart(JobQueue*);
    std::string buildChart();
};

#endif //OS_PROJECT_GANTTCHART_H
