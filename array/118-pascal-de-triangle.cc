#include <vector>
#include <iostream>
#include <stdio.h>

class Solution {
    public:
        std::vector<std::vector<int>>
            generate(int numRows) {
                std::vector<std::vector<int>> ret(numRows);
                std::vector<int> level {1};
                ret[0] = level;

                for (int i = 1; i < numRows; i++) {
                    int level_num = i+1;
                    level.resize(level_num);
                    level[0] = level[level_num-1] = 1;
                    for (int j = 1; j < level_num-1; j++) {
                        level[j] = ret[i-1][j] + ret[i-1][j+1];
                    }
                    ret[i] = level;
                }

                return ret;
            }
        void Show(const std::vector<std::vector<int>> &nums) {
            for (auto &ivec : nums) {
                for (auto c : ivec) {
                    std::cout << c << '\t';
                }
                std::cout << '\n';
            }
        }
};
        std::vector<std::vector<int>>
            generate(int numRows) {
                std::vector<std::vector<int>> ret(numRows);
                std::vector<int> level {1};
                ret[0] = level;

                for (int i = 1; i < numRows; i++) {
                    int level_num = i+1;
                    level.resize(level_num);
                    level[0] = level[level_num-1] = 1;
                    for (int j = 1; j < level_num-1; j++) {
                        level[j] = ret[i-1][j-1] + ret[i-1][j];
                        printf("i=%d\tj=%d\tval=%d\n", i, j, level[j]);
                    }
                    ret[i] = level;
                }

                return ret;
            }
        void Show(const std::vector<std::vector<int>> &nums) {
            for (auto &ivec : nums) {
                for (auto c : ivec) {
                    std::cout << c << '\t';
                }
                std::cout << '\n';
            }
        }

int main(int argc, char **argv) {
    auto it = generate(5);
    Show(it);
    return 0;
}
