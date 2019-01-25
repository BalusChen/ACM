#include "../include/make-linkedlist.h"
#include "../include/print.h"

/*
 * 1  ->  2  ->  3  ->  4  -> 5  -> NULL; m = 2, n = 4 (->: next is)
 * start -> 1, tail -> 2 (->: pointer to)
 *
 * 2rd for loop:
 * 0. 1 -> NULL (start->1, tail->2, p->2)
 * 1. 1 -> 2 -> NULL (start->1, tail->2, p->3)
 * 2. 1 -> 3 -> 2 -> NULL (start->1, tail->2, p->4)
 * 3. 1 -> 4 -> 3 -> 2 -> NULL (start->1, tail->2, p->5)
 *
 * after 2rd for loop:
 * 1 -> 4 -> 3 -> 2 -> 5 (tail->next = p)
 */
class Solution {
    public:
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            ListNode pre_head(0);
            pre_head.next = head;
            int idx = 1;
            ListNode *p = &pre_head, *start, *tail, *next;
            for ( ; idx < m; idx++)
                p = p->next;

            start = p;
            tail  = p->next;
            p     = p->next;
            start->next = nullptr;
            for ( ; idx <= n; idx++) {
                next = p->next;
                p->next = start->next;
                start->next = p;
                p = next;
            }
            tail->next = p;

            return pre_head.next;
        }
};
