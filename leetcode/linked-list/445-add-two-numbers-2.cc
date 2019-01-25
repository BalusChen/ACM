#include "../include/make-linkedlist.h"
#include "../include/print.h"
#include <stack>

class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            std::stack<ListNode*> s1, s2;
            ListNode pre_head(0), *p;
            int val1, val2, sum, res = 0;

            while (l1 != nullptr || l2 != nullptr) {
                if (l1 != nullptr) s1.push(l1);
                if (l2 != nullptr) s2.push(l2);
                l1 = (l1 == nullptr) ? l1 : l1->next;
                l2 = (l2 == nullptr) ? l2 : l2->next;
            }

            while (!s1.empty() || !s2.empty() || res) {
                val1 = val2 = 0;
                if (!s1.empty()) {
                    val1 = s1.top()->val;
                    s1.pop();
                }
                if (!s2.empty()) {
                    val2 = s2.top()->val;
                    s2.pop();
                }

                sum = (val1 + val2 + res) % 10;
                res = (val1 + val2 + res) / 10;
                p = new ListNode(sum);
                p->next = pre_head.next;
                pre_head.next = p;
            }

            return pre_head.next;
        }
};
