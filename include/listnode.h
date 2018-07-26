#ifndef LIST_NODE_H__
#define LIST_NODE_H__

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {  }
};

#endif /* LIST_NODE_H__ */
