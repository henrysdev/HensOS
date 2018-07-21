#include "sjfscheduler.h"


SjfScheduler::SjfScheduler(JobQueue * _ready_queue) {
    ready_queue = _ready_queue;
}

void SjfScheduler::handle(Pcb * process) {
    /* add process at head if ready queue is empty */
    if (!ready_queue->size) {
        ready_queue->add(process, -1);
        return;
    }

    /* place process in appropriate position in the
     * ready queue based on burst time */
    ListNode* currnode = ready_queue->head;
    int pos = 0;
    while (currnode) {
        /* if new process has shorter burst time,
         * add at the correct pos */
        if (process->burst < currnode->val->burst) {
            ready_queue->add(process, pos);
            return;
        }
        currnode = currnode->next;
        ++pos;
    }

    /* add to end of queue by default */
    ready_queue->add(process, -1);
}

bool SjfScheduler::preemptcomp(Pcb *curr, Pcb *next) {
    return next->burst < curr->burst;
}