
/*
 * Copyright (C) Jianyong Chen
 */


#include "../leetcode/include/make-linkedlist.h"


class Solution {
    public:
        ListNode* FindKthToTail(ListNode* head, unsigned int k) {
            int        len;
            ListNode  *p;

            len = 0;
            p = head;
            while (p != nullptr) {
                p = p->next;
                len++;
            }

            if (k > len) {
                return nullptr;
            }

            p = head;
            len -= k;
            while (len != 0) {
                p = p->next;
                len--;
            }

            return p;
        }
};
