#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <algorithm>

#include "pcb.h"
#include "csvreader.h"


CsvReader::CsvReader (JobQueue* j)
{
    jobs = j;
}


int CsvReader::execute(std::string cmd, std::string pid_str, std::string pos_str)
{
    // add command
    // TODO: come up with more elegant solution... (cast to lowercase before strcmp?)
    if (cmd == "add" || cmd == "Add" || cmd == "ADD")
    {
        if (!pid_str.empty())
        {
            int pid = atoi(pid_str.c_str());
            Pcb* process = new Pcb(pid);

            if (!pos_str.empty())
            {
                int pos = atoi(pos_str.c_str());
                jobs->add(process, pos);
            }
            else
            {
                jobs->add(process, -1);
            }
        }
        // return error (malformed input line)
        else
        {
            return -1;
        }
    }
    // delete command
    // TODO: come up with more elegant solution... (cast to lowercase before strcmp?)
    else if (cmd == "del" || cmd == "Del" || cmd == "DEL" || cmd == "delete" || cmd == "Delete" || cmd == "DELETE")
    {
        if (!pid_str.empty())
        {
            int pid = atoi(pid_str.c_str());
            jobs->del(pid);
        }
        // return error (malformed input line)
        else
        {
            jobs->del(-1);
        }
    }
    // print out queue
    // TODO: come up with more elegant solution... (cast to lowercase before strcmp?)
    else if (cmd == "print" || cmd == "Print" || cmd == "PRINT")
    {
        jobs->print();
    }
    // exit program
    // TODO: come up with more elegant solution... (cast to lowercase before strcmp?)
    else if (cmd == "exit" || cmd == "Exit" || cmd == "EXIT")
    {
        return 1;
    }

    return 0;
} 


int CsvReader::readin(const char* fpath)
{   
    std::ifstream ip(fpath);

    if (!ip.is_open()) std::cout << "ERROR: file open" << "\n";

    std::string line;

    std::string cmd;
    std::string pid;
    std::string pos;

    // iterate through csv file and execute line-by-line
    while (ip.good())
    {
        getline(ip, line, '\n');
        //std::remove_if(line.begin(), line.end(), isspace);
        std::string delimiter = ",";

        size_t s_pos = 0;
        std::string token;
        int ctr = 0;
        std::string args[4];
        while ((s_pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, s_pos);
            args[ctr] = token;
            line.erase(0, s_pos + delimiter.length());
            ++ctr;
        }
        line = line.substr(0, line.length());
        args[ctr] = line;

        cmd = args[0];
        pid = args[1];
        pos = args[2];


        // DEBUG PRINT READ IN LINE
        std::cout << "\n" << std::endl;
        for (int i = 0; i <= ctr; i++)
        {
            std::cout << args[i];
            if (i < ctr)
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;

        int res = execute(cmd, pid, pos);
        if (res == 1 || res == -1)
        {
            return res;
        }
        cmd.clear();
        pid.clear();
        pos.clear();

    }
    return 0;
}