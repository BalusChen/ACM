
/*
 * Copyright (C) Jianyong Chen
 */


#include <queue>

struct Node {
    int          val;

    Node        *left;
    Node        *right;
    Node        *next;

    Node() = default;
    Node(int v, Node *l, Node *r, Node *n)
        : val(v), left(l), right(r), next(n) {  }
};


class Solution {
    public:
        Node* connect(Node* root) {
            int                 level_size, i;
            Node              **prev, *front, dummy_head;
            std::queue<Node *>  que;

            if (root == nullptr) {
                return nullptr;
            }

            prev = &dummy_head.next;
            que.push(root);
            while (!que.empty()) {

                level_size = que.size();
                for (i = 0; i < level_size; i++) {
                    front = que.front();
                    que.pop();
                    *prev = front;
                    prev = &front->next;

                    if (front->left != nullptr) {
                        que.push(front->left);
                    }

                    if (front->right != nullptr) {
                        que.push(front->right);
                    }
                }

                *prev = nullptr;
                prev = &dummy_head.next;
            }

            return root;
        }
};

