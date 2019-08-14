
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>


class Solution {
    template<typename T>
    using Matrix = std::vector<std::vector<T>>;

    public:
    Matrix<int> permute(std::vector<int>& nums) {
        int               i, size;
        Matrix<int>       permutations;

        if (nums.empty()) {
            return permutations;
        }

        size = 1;
        for (i = 2; i <= nums.size(); i++) {
            size *= i;
        }

        permutations.resize(size);
        for (i = 0; i < permutations.size(); i++) {
            permutations[i] = nums;
            nextPermutation(nums);
        }

        return permutations;
    }

    void nextPermutation(std::vector<int> &nums) {
        int  i, j;

        if (nums.size() < 2) {
            return;
        }

        for (i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i-1]) {
                break;
            }
        }

        if (i > 0) {
            i--;
            for (j = nums.size() - 1; j >= 0; j--) {
                if (nums[j] > nums[i]) {
                    break;
                }
            }

            std::swap(nums[i], nums[j]);
            i++;
        }

        std::reverse(nums.begin() + i, nums.end());
    }
};
