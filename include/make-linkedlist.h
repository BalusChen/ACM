#ifndef MAKE_LINKEDLIST_H__
#define MAKE_LINKEDLIST_H__

#include <random>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {  }
};

ListNode* MakeLinkedList() {
    ListNode pre_head(0);
    return pre_head.next;
}


#endif /* MAKE_LINKEDLIST_H__ */
