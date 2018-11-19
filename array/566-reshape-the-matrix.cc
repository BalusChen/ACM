#include <vector>
#include <iostream>

class Solution {
    public:
        std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>> &nums, int r, int c) {
            std::vector<std::vector<int>> ret;
            int new_row = 0, new_col = 0, pos = 0;

            if (nums.empty()) return nums;
            if (r*c != nums.size()*nums[0].size()) return nums;

            ret.resize(r);
            for (auto &vec : ret)
                vec.resize(c);
            for (int i = 0; i < nums.size(); i++) {
                for (int j = 0; j < nums[i].size(); j++) {
                    pos = i*nums[i].size()+j;
                    new_row = pos / c;
                    new_col = pos - new_row * c;
                    std::cout << "pos " << pos << std::endl;
                    std::cout << "i: " << i << std::endl;
                    std::cout << "j: " << j << std::endl;
                    std::cout << "new row: " << new_row << std::endl;
                    std::cout << "new_col: " << new_col << std::endl;
                    ret[new_row][new_col] = nums[i][j];
                }
            }

            return ret;
        }
};

