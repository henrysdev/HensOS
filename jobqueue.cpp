#include "jobqueue.h"
#include <iostream>


JobQueue::JobQueue(int cap)
{
    capacity = cap;
    length = 0;
    head = 0;
    tail = 0;
}


void JobQueue::add(int pid, int pos)
{
    // if list has room in it
    if (length < capacity) 
    {
        Pcb* proc = new Pcb(pid);
        ListNode* link = new ListNode(proc);

        // if target position is outside of range of list
        if (pos > length)
        {
            std::cout << "position requested is out of range. Appending to tail" << std::endl;
            pos = -1;
        }

        // if list is empty
        if (!length)
        {
            head = tail = link;
            ++length;
            return;
        }

        // add to tail
        if (pos == -1 || pos == length)
        {
            tail->next = link;
            tail = link;
        }
        // regular insert in middle
        else
        {
            // insert as new head
            if (pos == 0)
            {
                ListNode* tmp = head;
                head = link;
                head->next = tmp;
            }
            // insert somewhere between head and tail
            else
            {
                ListNode* curr = head;
                // loop to desired position
                for (int i = 0; i < pos-1; i++)
                {
                    curr = curr->next;
                }
                // insert new link into list
                ListNode* tmp = curr->next;
                curr->next = link;
                link->next = tmp;
            }
        }
        ++length;
    }
    // list at max capacity
    else
    {
        std::cout << "maximum capacity, can't accept any more processes!" << std::endl;
    }
}


void JobQueue::del(int targ_pid)
{
    // if the list is not empty
    if (length > 0)
    {
        ListNode* curr = head;

        // delete head if no PID specified (default case) OR if head has target PID 
        if (targ_pid == -1 || curr->val->pid == targ_pid)
        {
            head = curr->next;
            --length;
            return;
        }

        // iterate through list until target PID is found
        while (curr->next)
        {
            if (curr->next->val->pid == targ_pid)
            {
                curr->next = curr->next->next;
                --length;
                return;
            }
            curr = curr->next;
        }

        // check last list node for matching PID
        if (curr->val->pid == targ_pid)
        {
            tail->next = curr;
            tail = curr;
            --length;
            return;
        }

        // no matching PID found
        else
        {
            std::cout << "pid " << targ_pid << " not found in job queue" << std::endl;
        }
    }
    // list is empty
    else
    {
        std::cout << "nothing to delete, queue is empty" << std::endl;
        return;
    }

}


void JobQueue::print()
{
    if (!head || !tail)
    {
        std::cout << "(empty)" << std::endl;
    }

    ListNode* curr = head;
    while (curr)
    {
        std::cout << curr->val->pid << std::endl;
        curr = curr->next;
    }
    std::cout << "\n" << std::endl;
}