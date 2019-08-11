
/*
 * Copyright (C) Jianyong Chen
 */


#include "../leetcode/include/make-linkedlist.h"


class Solution {
    public:
        ListNode* ReverseList(ListNode *head) {
            ListNode  dummy_head(0), *p, *next;

            if (head == nullptr || head->next == nullptr) {
                return head;
            }

            p = &dummy_head;
            while (head != nullptr) {
                next = head->next;
                head->next = p->next;
                p->next = head;
                head = next;
            }

            return dummy_head.next;
        }
};
