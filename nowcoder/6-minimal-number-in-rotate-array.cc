
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>


class Solution {
    public:
        int minNumberInRotateArray(std::vector<int> rotateArray) {
            int  i, j;

            if (rotateArray.empty()) {
                return 0;
            }

            i = 0;
            j = 1;
            while (j < rotateArray.size() && rotateArray[i] <= rotateArray[j]) {
                i++;
                j++;
            }

            if (j >= rotateArray.size()) {
                return rotateArray[0];

            } else {
                return rotateArray[j];
            }
        }
};
