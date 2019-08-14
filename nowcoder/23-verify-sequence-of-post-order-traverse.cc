
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


int
main(int argc, char **argv)
{
    Solution          ans;
    std::vector<int>  sequence;

    sequence = { 1, 3, 7 };
    printf("ans: %d\n", ans.VerifySquenceOfBST(sequence));

    sequence = { 17, 13, 37, 15, 11 };
    printf("ans: %d\n", ans.VerifySquenceOfBST(sequence));

    sequence = { 2, 3, 9, 17, 13, 7 };
    printf("ans: %d\n", ans.VerifySquenceOfBST(sequence));

    return 0;
}
