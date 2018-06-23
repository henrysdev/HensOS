#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "jobqueue.h"

class UserInterface
{
private:
    JobQueue* jobs;
    void addmenu();
    void delmenu();
    void invalid();
    void printqueue();
public:
    UserInterface(JobQueue*);
    int mainmenu();
};

#endif