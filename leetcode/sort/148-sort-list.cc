#include "../include/make-linkedlist.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode  *mid;

        if (!head || !head->next) {
            // empty list or only on node
            return head;
        }

        // divide
        mid = SplitList(head);

        // conquer
        head = sortList(head);
        mid = sortList(mid);

        // merge
        return Merge(head, mid);
    }


    // REQUIRE: head is not nullptr
    ListNode *SplitList(ListNode *head) {
        ListNode *slow, *fast, *mid;

        slow = head;
        fast = head->next;

        while (fast) {
            fast = fast->next;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        mid = slow->next;
        slow->next = nullptr;   // important!!!

        return mid;
    }


    ListNode *Merge(ListNode *head1, ListNode *head2) {
        ListNode pre_head(0), *p;

        if (!head1 || !head2) {
            return head1 ? head1 : head2;
        }

        p = &pre_head;
        while (true) {
            if (!head1) {
                p->next = head2;
                break;
            } else if (!head2) {
                p->next = head1;
                break;
            } else if (head1->val < head2->val) {
                p->next = head1;
                head1 = head1->next;
            } else {
                p->next = head2;
                head2 = head2->next;
            }

            p = p->next;
        }

        return pre_head.next;
    }
};
