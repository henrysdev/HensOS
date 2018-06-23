#include <iostream>
#include <string>
#include "userinterface.h"


UserInterface::UserInterface(JobQueue* j)
{
    jobs = j;
}


void UserInterface::print()
{
    jobs->print();
}


int UserInterface::addmenu ()
{
    const char* menutxt = "ADD PCB\n";
    std::cout << menutxt << std::endl;

    for (;;)
    {    
        const char* pidtxt = "Enter PID for Process to Add\n"
                             "> ";
        std::cout << pidtxt;
        
        int pid;
        std::cin >> pid;
    
        const char* addtxt = "Choose Insertion Method\n"
                             "(1) Append to end of queue (default)\n"
                             "(2) Insert at specific position in queue\n"
                             "> ";
        std::cout << addtxt;
        
        int method;
        std::cin >> method;
    
        switch (method)
        {
            // append to tail of queue
            case 1:
            {
                jobs->add(pid, -1);
                break;
            }
            // add by position
            case 2:
            {
                const char* postxt = "Enter Position\n"
                                     "> ";
                std::cout << postxt;
                int pos;
                std::cin >> pos;
                jobs->add(pid, pos);
                break;
            }
            // invalid
            default:
            {
                std::cout << "invalid input" << std::endl;
                break;
            }
        }
        return 0;
    }
}


int UserInterface::delmenu ()
{
    const char* menutxt = "DELETE PCB\n";
    std::cout << menutxt << std::endl;

    for (;;)
    {    
        const char* addtxt = "Choose Deletion Method\n"
                             "(1) Delete head PCB (default)\n"
                             "(2) Delete by PID\n"
                             "> ";
        std::cout << addtxt;
        
        int method;
        std::cin >> method;
    
        switch (method)
        {
            // delete head of queue
            case 1:
            {
                jobs->del(-1);
                break;
            }
            // delete by PID
            case 2:
            {
                const char* pidtxt = "Enter PID for Process to Delete\n"
                             "> ";
                std::cout << pidtxt;
                
                int pid;
                std::cin >> pid;
                jobs->del(pid);
                break;
            }
            // invalid
            default:
            {
                std::cout << "invalid input" << std::endl;
                break;
            }
        }
        return 0;
    }
}


int UserInterface::mainmenu ()
{
    const char* menutxt = "ACTION MENU\n"
                          "(1) Add PCB\n"
                          "(2) Delete PCB\n"
                          "(3) Print Job Queue\n"
                          "(0) Quit\n"
                          "> ";
    for(;;)
    {
        std::cout << menutxt;
        int choice;
        std::cin >> choice;

        switch (choice)
        {
            // add to queue
            case 1:
            {
                int excode = addmenu();
                break;
            }
            // del from queue
            case 2:
            {
                int excode = delmenu();
                break;
            } 
            // print queue
            case 3:
            {
                print();
                break;
            }
            // exit
            case 0:
            {
                // flesh out
                std::cout << "*exit program*" << std::endl;
                return 0;
            }
            // invalid
            default:
            {
                // flesh out
                std::cout << "*invalid entry*" << std::endl;
                break;
            }
        }
    }

    return 0;
}