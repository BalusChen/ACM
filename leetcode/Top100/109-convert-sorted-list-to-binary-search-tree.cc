
/*
 * Copyright (C) Jianyong Chen
 */


#include "../include/make-linkedlist.h"
#include "../include/make-tree.h"


class Solution {
    public:
        TreeNode* sortedListToBST(ListNode* head) {
            TreeNode  *root;
            ListNode  *prev, *slow, *fast;

            if (head == nullptr) {
                return nullptr;
            }

            if (head->next == nullptr) {
                return new TreeNode(head->val);
            }

            slow = head;
            fast = head;
            while (fast && fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }

            prev->next = nullptr;
            root = new TreeNode(slow->val);
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(slow->next);

            return root;
        }
};
