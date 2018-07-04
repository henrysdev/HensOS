#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>

#include "scheduler.h"


class CsvReader
{
private:
    Scheduler* scheduler;
public:
    CsvReader(Scheduler*);
    int readin(const char*);
    int execute(std::string, std::string, std::string, std::string);
};

#endif