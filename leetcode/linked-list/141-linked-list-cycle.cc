
/*
 * Copyright (C) Jianyong Chen
 */

#include "../include/make-linkedlist.h"

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode  *slow, *fast;

            if (head == nullptr) {
                return false;
            }

            slow = head;
            fast = head;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;

                if (slow == fast) {
                    return true;
                }
            }

            return false;
        }
};
