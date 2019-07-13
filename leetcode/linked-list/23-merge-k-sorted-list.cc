
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include/make-linkedlist.h"
#include <queue>

class Solution {
    public:

        class Cmp {
            public:
                bool operator() (ListNode *n1, ListNode *n2) {
                    return n1->val > n2->val;
                }

        };

        ListNode* mergeKLists(std::vector<ListNode*>& lists) {

            ListNode dummy_head(0), *p, *top;

            std::priority_queue<ListNode *, std::vector<ListNode*>, Cmp> pq;

            for (auto &n : lists) {
                if (n != nullptr) {
                    pq.push(n);
                }
            }

            p = &dummy_head;
            while (!pq.empty()) {
                top = pq.top();
                pq.pop();

                if (top->next != nullptr) {
                    pq.push(top->next);
                }

                p->next = top;
                p = p->next;
            }

            return dummy_head.next;
        }
};
