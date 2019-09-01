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

ListNode *
insertionSortList2(ListNode *head)
{
    ListNode  pre_head(0), *p, *prev, *next, *cur;

    if (!head || !head->next) {
        // empty list or only one element
        return head;
    }

    cur = head;
    while (cur->next != nullptr) {
        head = head->next;
        prev = cur;
        next = cur->next;

        // find proper position
        while (next && (next->val < cur->val)) {
            prev = next;
            next = next->next;
        }

        // put cur to the proper position
        if (prev != cur) {
            cur->next = next;
            prev->next = cur;
        }

        cur = head;
    }

    pre_head.next = head;
    p = &pre_head;

    return p;
}
