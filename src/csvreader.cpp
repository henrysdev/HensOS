#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <algorithm>

#include "pcb.h"
#include "csvreader.h"


Pcb* CsvReader::parse_pcb(std::string pid_str, std::string arrival_str, std::string burst_str, std::string priority_str) {
    int pid = atoi(pid_str.c_str());
    int arrival = atoi(arrival_str.c_str());
    int burst = atoi(burst_str.c_str());
    int priority = atoi(priority_str.c_str());

    Pcb* process = new Pcb(pid, arrival, burst, priority);

    return process;
}

std::vector<Pcb*>* CsvReader::readin(const char* fpath) {
    std::ifstream ip(fpath);

    if (!ip.is_open()) std::cout << "ERROR: file open" << "\n";

    std::vector<Pcb*>* processes = new std::vector<Pcb*>;

    std::string pid, arrival, burst, priority;

    // iterate through csv file and execute line-by-line
    std::string line;
    while (ip.good()) {
        getline(ip, line, '\n');
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

        pid      = args[0];
        arrival  = args[1];
        burst    = args[2];
        priority = args[3];


        // DEBUG PRINT READ IN LINE
        std::cout << "\n" << std::endl;
        for (int i = 0; i <= ctr; i++) {
            std::cout << args[i];
            if (i < ctr) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;

        /* parse line into PCB object and add it to list of PCBs for pre-processing */
        Pcb* proc = parse_pcb(pid, arrival, burst, priority);
        processes->push_back(proc);

        pid.clear();
        arrival.clear();
        burst.clear();
        priority.clear();
    }
    return processes;
}
