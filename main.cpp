#include <iostream>
#include <string>

#include "jobqueue.h"
#include "userinterface.h"
#include "csvreader.h"

#define NUM_PROCESSES 10
#define FIRST_PID 1000
#define MAX_CAPACITY 10

int demo(int mode)
{
    JobQueue* jobs = new JobQueue(MAX_CAPACITY);
    UserInterface* ui = new UserInterface(jobs);

    if (mode == 0)
    {
        return ui->mainmenu();
    }
    else if (mode == 1)
    {
        CsvReader* reader = new CsvReader(jobs);
        return reader->readin("example.csv");
    }
}

int main (int argc, char** argv)
{
    return demo(1);
}