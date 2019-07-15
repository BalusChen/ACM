
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include/make-linkedlist.h"

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            int         i;
            ListNode  **p, *cur;

            if (head == nullptr || n < 1) {
                return nullptr;
            }

            cur = head;
            for (i = 1; i < n; ++i) {
                cur = cur->next;
            }

            p = &head;
            while (cur->next != nullptr) {
                cur = cur->next;
                p = &((*p)->next);
            }

            *p = (*p)->next;

            return head;
        }
};
