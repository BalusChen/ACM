#include "../include/make-linkedlist.h"
#include "../include/print.h"
#include <vector>

class Solution {
    public:
        std::vector<ListNode*> splitListToParts(ListNode *root, int k) {
            int total_len = 0, part_len, num_of_longer;
            int len; 
            ListNode *head = root, *next;
            std::vector<ListNode*> ret;
            
            while (head != nullptr) {
                ++total_len;
                head = head->next;
            }
            part_len = total_len / k;
            num_of_longer = total_len % k;
            head = root;

            for (int i = 0; i < k; ++i) {
                len = part_len;
                if (--num_of_longer >= 0) len++;
                if (len == 0) ret.push_back(nullptr);
                else {
                    ret.push_back(head);
                    while (--len > 0)
                        head = head->next;
                    next = head->next;
                    head->next = nullptr;
                    head = next;

                }
            }

            return ret;
        }
};
