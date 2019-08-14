
/*
 * Copyright (C) Jianyong Chen
 */


#include <unordered_map>


struct RandomListNode {
    int              label;
    RandomListNode  *next;
    RandomListNode  *random;

    RandomListNode(int x)
        : label(x), next(nullptr), random(nullptr) {  }
};


class Solution
{
    public:
        RandomListNode *Clone(RandomListNode *head) {
            RandomListNode  *q, *node;


            q = head;
            if (q != nullptr) {
                auto it = old_to_new.find(q);

                if (it == old_to_new.end()) {
                    node = new RandomListNode(q->label);
                    old_to_new[q] = node;
                    node->next = Clone(q->next);
                    node->random = Clone(q->random);

                } else {
                    node = it->second;
                }

                return node;
            }

            return q;
        }

    private:
        std::unordered_map<RandomListNode *, RandomListNode *>  old_to_new;
};
