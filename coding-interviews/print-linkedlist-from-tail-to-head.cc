#include <vector>
#include "../leetcode/include/make-linkedlist.h"

class Solution {
public:
    std::vector<int> printListFromTailToHead(ListNode* head) {
        aux(head);

        return sequence;
    }

    void aux(ListNode *head) {
        if (head == nullptr) {
            return;
        }

        if (head->next == nullptr) {
            sequence.push_back(head->val);
        } else {
            aux(head->next);
            sequence.push_back(head->val);
        }
    }

    std::vector<int>  sequence;
};
