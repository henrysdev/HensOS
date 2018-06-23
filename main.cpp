#include <iostream>
#include <string>

#include "jobqueue.h"
#include "userinterface.h"
#include "csvreader.h"

#define NUM_PROCESSES 10
#define FIRST_PID 1000
#define MAX_CAPACITY 10


int demo(const char* csvpath)
{
    JobQueue* jobs = new JobQueue(MAX_CAPACITY);
    UserInterface* ui = new UserInterface(jobs);

    if (csvpath[0] == '\0')
    {
        return ui->mainmenu();
    }
    else
    {
        CsvReader* reader = new CsvReader(jobs);
        return reader->readin(csvpath);
    }
}


int main (int argc, char* argv[])
{
    // default run mode (manual input) is run when no extra args passed
    if (argc == 1)
    {
        return demo("");
    }
    // automatic run mode (csv input) run when filepath is provided
    else if (argc == 2)
    {
        const char* csvpath = argv[1];
        return demo(csvpath);
    }
}