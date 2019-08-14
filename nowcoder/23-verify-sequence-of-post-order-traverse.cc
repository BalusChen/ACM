
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>

class Solution {
    public:
        bool VerifySquenceOfBST(std::vector<int> sequence) {

            /*
             * QUESTION: why empty sequence is illegal?
             */

            if (sequence.empty()) {
                return false;
            }

            return verify_subtree(sequence, 0, sequence.size()-1);
        }

        bool verify_subtree(const std::vector<int> &sequence, int left, int right) {
            int  i, middle, pivot;

            if (right <= left) {
                return true;
            }

            pivot = sequence[right];
            for (middle = left; middle < right && sequence[middle] < pivot;
                 middle++)
            {
                /* do nothing */
            }

            for (i = middle; i < right; i++) {
                if (sequence[i] < pivot) {
                    return false;
                }
            }

            return verify_subtree(sequence, left, middle-1)
                && verify_subtree(sequence, middle, right-1);
        }
};

