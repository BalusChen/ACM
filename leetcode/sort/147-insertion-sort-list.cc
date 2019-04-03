#include "../include/make-linkedlist.h"

ListNode* insertionSortList(ListNode *head) {
    ListNode  *prev, *next, *p;

    if (!head || !head->next) {
        // empty list or only one element
        return head;
    }

    head->next = insertionSortList(head->next);

    p = head;
    prev = head;
    next = head->next;

    // find the proper position that `head` should be in
    while (next && (head->val > next->val)) {
        prev = next;
        next = next->next;
    }

    // put `head` in the proper position
    if (prev != head) {
        p = head->next;
        prev->next = head;
        head->next = next;
    }

    // return the head of the sorted part
    return p;
}

