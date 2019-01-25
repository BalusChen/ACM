#include <iostream>
#include "../include/make-linkedlist.h"

class Solution {
    public:
        ListNode *middleNode(ListNode *head) {
            ListNode *slow = head, *fast = head->next;

            while (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
                if (fast == NULL)
                    break;
                else
                    fast = fast->next;
            }

            return slow;
        }
};
