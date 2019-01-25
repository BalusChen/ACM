#include "../include/make-linkedlist.h"

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode *slow, *fast;

            if (head == nullptr)
                return false;

            slow = head;
            fast = head->next;
            while (slow != fast) {
                if (slow == nullptr || fast == nullptr || fast->next == nullptr)
                    return false;
                slow = slow->next;
                fast = fast->next->next;
            }

            return true;
        }
};
