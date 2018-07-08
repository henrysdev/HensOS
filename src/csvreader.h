#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>

#include "scheduler.h"


class CsvReader
{
private:
    Scheduler* scheduler;
public:
    CsvReader(Scheduler*);
    std::vector<Pcb*>* readin(const char*);
    Pcb* parse_pcb(std::string, std::string, std::string, std::string);
};

#endif