#include "jobqueue.h"
#include <iostream>


JobQueue::JobQueue(int cap) {
    capacity = cap;
    size  = 0;
    head  = 0;
    tail  = 0;
}


void JobQueue::print() {
    std::cout << std::endl;
    if (!head || !tail) {
        std::cout << "(empty)" << std::endl;
        return;
    }

    ListNode* curr = head;
    while (curr) {
        std::cout << curr->val->pid;
        curr = curr->next;
        if (curr) std::cout << " -> ";
    }
    std::cout << "\n" << std::endl;
}


void JobQueue::add(Pcb* proc, int pos) {
    /* check capacity of queue */
    if (size >= capacity) {
        std::cout << "maximum capacity, can't accept any more processes!" << std::endl;
        return;
    }

    ListNode* link = new ListNode(proc);

    // if target position is outside of range of list
    if (pos > size) {
        std::cout << "position requested is out of range. Appending to tail instead" << std::endl;
        pos = -1;
    }

    // if list is empty
    if (!size) {
        head = tail = link;
        ++size;
        //print();
        return;
    }

    // add to tail
    if (pos == -1 || pos == size) {
        tail->next = link;
        tail = link;
    } else {
        // insert as new head
        if (pos == 0) {
            ListNode* tmp = head;
            head = link;
            head->next = tmp;
        } else {
            ListNode* curr = head;
            // loop to desired position
            for (int i = 0; i < pos-1; i++) {
                curr = curr->next;
            }
            // insert new link into list
            ListNode* tmp = curr->next;
            curr->next = link;
            link->next = tmp;
        }
    }
    ++size;
}


void JobQueue::del(int targ_pid) {
    // if the list is not empty
    if (size > 0) {
        ListNode* curr = head;

        // delete head if no PID specified (default case) OR if head has target PID 
        if (targ_pid == -1 || curr->val->pid == targ_pid) {
            head = curr->next;
            --size;
            //print();
            return;
        }

        // iterate through list until target PID is found
        while (curr->next) {
            if (curr->next->val->pid == targ_pid) {
                curr->next = curr->next->next;
                --size;
                //print();
                return;
            }
            curr = curr->next;
        }

        // check last list node for matching PID
        if (curr->val->pid == targ_pid) {
            tail->next = curr;
            tail = curr;
            --size;
            //print();
            return;
        } else {
            std::cout << "pid " << targ_pid << " not found in job queue" << std::endl;
        }
    } else {
        std::cout << "nothing to delete, queue is empty" << std::endl;
        return;
    }

}