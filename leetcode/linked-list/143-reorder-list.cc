#include "../include/make-linkedlist.h"
#include "../include/print.h"
#include <iostream>
#include <deque>

class Solution {
    public:
        void reorderList(ListNode *head) {
            ListNode *p;
            std::deque<ListNode*> dq;

            if (head == nullptr || head->next == nullptr)
                return;

            for (p = head->next; p != nullptr; p = p->next)
                dq.push_back(p);
            p = head;
            while (!dq.empty()) {
                p->next = dq.back();
                dq.pop_back();
                p = p->next;
                if (!dq.empty()) {
                    p->next = dq.front();
                    dq.pop_front();
                    p = p->next;
                }
            }
            p->next = nullptr; // make sure that there is no cycle in the list
        }
};
