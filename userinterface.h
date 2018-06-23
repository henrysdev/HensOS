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
    void addmenu();
    void delmenu();
    void invalid();
    void printqueue();
};

#endif