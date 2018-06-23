#include "jobqueue.h"
#include "userinterface.h"
#include <iostream>

#define NUM_PROCESSES 10
#define FIRST_PID 1000
#define MAX_CAPACITY 10

int demo()
{
    JobQueue* jobs = new JobQueue(MAX_CAPACITY);
    UserInterface* ui = new UserInterface(jobs);

    return ui->mainmenu();

    /*
        // test Add function
        for(int i = 0; i < NUM_PROCESSES; i++)
        {
            int new_pid = FIRST_PID + i;
            if (!(i % 2))
            {
                std::cout << "appending new PID " << new_pid << " to tail" << std::endl;
                jobs->add(new_pid, -1);
            }
            else
            {
                std::cout << "appending new PID " << new_pid << " to pos " << 0 << std::endl;
                jobs->add(new_pid, 0);
            }

            jobs->print();
        }

        // test Del function
        for(int i = 0; i < NUM_PROCESSES; i++)
        {
            int targ_pid = FIRST_PID + i;
            std::cout << "deleting PID " << targ_pid << std::endl;
            jobs->del(targ_pid);
            jobs->print();
        }
    */
}

int main (int argc, char** argv)
{
    return demo();
}