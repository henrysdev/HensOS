#ifndef LISTNODE_H
#define LISTNODE_H

#include "pcb.h"

class ListNode
{
public:
    ListNode* next;
    Pcb* val;
    ListNode(Pcb*);
};

#endif