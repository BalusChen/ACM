#include "../include/print.h"
#include "../include/make-linkedlist.h"

class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            ListNode *p = head, *tail, *ret;
            int len = 0, start_idx;

            if (head == nullptr || head->next == nullptr)
                return head;

            for ( ; p->next != nullptr; p = p->next)
                len++;

            tail = p;
            tail->next = head;
            p = head;
            len++;
            start_idx = len - k % len;

            while(--start_idx != 0)
                p = p->next;
            ret = p->next;
            p->next = nullptr;
            return ret;
        }
};

        ListNode *rotateRight(ListNode *head, int k) {
            ListNode *p = head, *ret;
            int len = 0, start_idx;

            if (head == nullptr || head->next == nullptr)
                return head;

            for ( ; p->next != nullptr; p = p->next)
                len++;

            p->next = head;
            p = head;
            len++;
            start_idx = len - k % len;

            while(--start_idx != 0)
                p = p->next;
            ret = p->next;
            p->next = nullptr;
            return ret;
        }

int main() {
    ListNode *head = MakeLinkedList({1, 2, 3, 4, 5,});
    head = rotateRight(head, 2);
    PrintLinkedList(head);

    head = MakeLinkedList({0, 1, 2});
    head = rotateRight(head, 4);
    PrintLinkedList(head);
}
