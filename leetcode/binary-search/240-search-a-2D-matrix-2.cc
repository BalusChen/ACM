
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>

class Solution {
    public:
        bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
            int  row, col;
            int  x, y;

            if (matrix.empty()) {
                return false;
            }

            /*
             * 从最大行的最小元素开始搜索
             *      1. 如果 target 比它大，那么搜索下一列
             *      2. 如果 target 比它小，那么搜索上一行
             */

            row = matrix.size() - 1;
            col = 0;
            while (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size()) {
                if (matrix[row][col] < target) {
                    col++;

                } else if(target < matrix[row][col]) {
                    row--;

                } else {
                    return true;
                }
            }

            return false;
        }
};
