#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "jobqueue.h"

class UserInterface
{
public:
    UserInterface(JobQueue*);
    int mainmenu();
private:
    JobQueue* jobs;
    int addmenu();
    int delmenu();
    void print();
};

#endif