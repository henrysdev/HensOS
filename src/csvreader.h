#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>

#include "scheduler.h"


class CsvReader
{
private:
    Scheduler* scheduler;
    void execute(std::vector<Pcb*>*);
public:
    CsvReader(Scheduler*);
    int readin(const char*);
    Pcb* parse_pcb(std::string, std::string, std::string, std::string);
};

#endif