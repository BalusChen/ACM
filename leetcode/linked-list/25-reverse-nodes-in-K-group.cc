
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include/make-linkedlist.h"


class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            int        len;
            ListNode  *p;

            if (k <= 1 || head == nullptr || head->next == nullptr) {
                return head;
            }

            len = 0;
            p = head;
            while (p != nullptr) {
                len++;
                p = p->next;
            }

            return reversePart(head, len, k);
        }

        ListNode *reversePart(ListNode *head, int n, int k) {
            int        i;
            ListNode  *prev, *curr, *next;

            if (n < k) {
                return head;
            }

            prev = nullptr;
            curr = head;
            for (i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // reverse next part recursively
            head->next = reversePart(next, n-k, k);

            return prev;
        }
};
