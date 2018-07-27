#ifndef MAKE_LINKEDLIST_H__
#define MAKE_LINKEDLIST_H__

#include "listnode.h"
#include <random>

#define MIN_ELEM 3
#define MAX_ELEM 17

ListNode* MakeLinkedList() {
    static std::uniform_int_distribution<int> u(MIN_ELEM, MAX_ELEM
            );
    static std::default_random_engine e;
    int sz = u(e);
    ListNode pre_head(0);

    ListNode *ptr = &pre_head;
    while (--sz >= 0) {
        ptr->next = new ListNode(u(e));
        ptr = ptr->next;
    }

    return pre_head.next;
}


#endif /* MAKE_LINKEDLIST_H__ */
