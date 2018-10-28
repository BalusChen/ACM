#include <iostream>
#include "../include/make-linkedlist.h"


struct Node {
    int val     = 0;
    Node *prev  = NULL;
    Node *next  = NULL;
    Node *child = NULL;

    Node() {  }
    Node(int v, Node *p, Node *n, Node *c) {
        val   = v;
        prev  = p;
        next  = n;
        child = c;
    }
};

class Solution {
    public:
        Node *flatten(Node *head) {
            flatten_aux2(head);
            return head;
        }

        Node *flatten_aux2(Node *head) {
            Node *p, *tail, *next;
            for (p = head; p != nullptr; ) {
                if (p->child != nullptr) {
                    next = p->next;
                    p->next = p->child;
                    p->child->prev = p;
                    p->child = nullptr;
                    tail = flatten_aux2(p->next);
                    tail->next = next;
                    if (next != nullptr) next->prev = tail;
                    p = next;
                } else {
                    tail = p;
                    p = p->next;
                }
            }

            return tail;
        }
};
