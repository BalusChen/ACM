
/*
 * Copyright (C) Jianyong Chen
 */


#include "../leetcode/include/make-linkedlist.h"


class Solution {
    public:
        ListNode* Merge(ListNode *head1, ListNode *head2)
        {
            ListNode  dummy_head(0), *p;

            p = &dummy_head;
            while (head1 != nullptr && head2 != nullptr) {
                if (head1->val < head2->val) {
                    p->next = head1;
                    head1 = head1->next;

                } else {
                    p->next = head2;
                    head2 = head2->next;
                }
                p = p->next;
            }

            while (head1 != nullptr) {
                p->next = head1;
                head1 = head1->next;
                p = p->next;
            }

            while (head2 != nullptr) {
                p->next = head2;
                head2 = head2->next;
                p = p->next;
            }

            return dummy_head.next;
        }
};
