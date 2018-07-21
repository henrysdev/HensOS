#include <iostream>
#include <string>

#include "jobqueue.h"
#include "userinterface.h"
#include "csvreader.h"
#include "sjfscheduler.h"
#include "simulator.h"
#include "priorityscheduler.h"

#define MAX_CAPACITY 10


int demo(const char* csvpath) {
    JobQueue* ready = new JobQueue(MAX_CAPACITY);

    SjfScheduler* scheduler = new SjfScheduler(ready);
    //PriorityScheduler *scheduler = new PriorityScheduler(ready);

    Simulator* simulator = new Simulator(scheduler, false);
    CsvReader* reader = new CsvReader(scheduler);
    std::vector<Pcb*>* procs = reader->readin(csvpath);
    float avg_wait = simulator->simulate(procs);
    std::cout << "avg wait time: " << avg_wait << std::endl;
    return 0;
}


int main (int argc, char* argv[]) {
    // default run mode (manual input) is run when no extra args passed
    if (argc == 1) {
        return demo("");
    }
    // automatic run mode (csv input) run when filepath is provided
    else if (argc == 2) {
        const char* csvpath = argv[1];
        return demo(csvpath);
    }
}