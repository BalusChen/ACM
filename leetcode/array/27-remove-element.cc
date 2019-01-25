#include <vector>
#include <iostream>

class Solution {
    public:
        int removeElement(std::vector<int> &nums, int val) {
            int count = 0;
            int hole  = 0;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == val) {
                    ++count;
                } else {
                    nums[hole] = nums[i];
                    hole++;
                }
            }

            return (nums.size()-count);
        }
        void Show(const std::vector<int> &nums, int count) {
            for (int i = 0; i < count; i++)
                std::cout << nums[i] << '\t';
            std::cout << '\n';
        }
};
