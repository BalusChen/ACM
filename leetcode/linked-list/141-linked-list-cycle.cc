
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
            fast = head->next;
            while (fast != nullptr) {
                if (slow == fast) {
                    return true;
                }

                fast = fast->next;
                if (fast == nullptr) {
                    return false;
                }
                fast = fast->next;
                slow = slow->next;
            }

            return false;
        }
};
