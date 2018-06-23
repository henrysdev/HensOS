#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>

#include "jobqueue.h"


class CsvReader
{
private:
    JobQueue* jobs;
public:
    CsvReader(JobQueue*);
    int readin(const char*);
    int execute(std::string, std::string, std::string);
};

#endif