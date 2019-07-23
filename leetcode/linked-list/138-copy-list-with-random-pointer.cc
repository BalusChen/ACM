
/*
 * Copyright (C) Jianyong Chen
 */

#include <unordered_map>

class Node {
    public:
        int    val;
        Node*  next;
        Node*  random;

        Node() {}

        Node(int _val, Node* _next, Node* _random) {
            val = _val;
            next = _next;
            random = _random;
        }
};

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            std::unordered_map<Node *, Node *>  old_to_new;

            return aux(head, old_to_new);
        }

        Node *aux(Node *node, std::unordered_map<Node *, Node*> &old_to_new) {
            Node  *new_node;

            if (node == nullptr) {
                return nullptr;
            }

            if (old_to_new.find(node) != old_to_new.end()) {
                return old_to_new[node];
            }

            new_node = new Node(node->val, nullptr, nullptr);
            old_to_new[node] = new_node;
            new_node->next = aux(node->next, old_to_new);
            new_node->random = aux(node->random, old_to_new);

            return new_node;
        }
};
