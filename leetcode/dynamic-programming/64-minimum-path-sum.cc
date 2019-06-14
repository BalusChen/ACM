
/*
 * Copyright (C) Jianyong Chen
 */

#include <cstdio>
#include <vector>

class Solution
{
    public:
        template<typename T>
        using Matrix = std::vector<std::vector<T>>;

        int minPathSum(Matrix<int> &grid) {
            if (grid.empty()) {
                return 0;
            }

            dp.resize(grid.size());
            for (auto &v : dp) {
                v.resize(grid[0].size(), -1);
            }

            this->grid = &grid;

            aux(0, 0);
            return dp[0][0];
        }


        void showDP() const {
            for (auto & v : dp) {
                for (auto c : v) {
                    printf("%d  ", c);
                }

                printf("\n");
            }
        }

        int aux(int i, int j) {
            int  down, right, sum;

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            if (i == grid->size()-1 && j == (*grid)[i].size()-1) {
                dp[i][j] = grid->back().back();
                return dp[i][j];
            }

            down = -1;
            right = -1;
            if (i < grid->size()-1) {
                down = aux(i+1, j);
            }
            if (j < (*grid)[i].size()-1) {
                right = aux(i, j+1);
            }

            if (down == -1 || right == -1) {
                sum = (down  == -1) ? right : down;

            } else {
                sum = std::min(down, right);
            }

            dp[i][j] = sum + (*grid)[i][j];

            return dp[i][j];
        }

    private:
        Matrix<int>  dp;
        Matrix<int>  *grid;
};


template<typename T>
using Matrix = std::vector<std::vector<T>>;

int
main(int argc, char **argv)
{

    int          min_sum;
    Solution     ans;
    Matrix<int>  grid;

    grid = {

        { 1, 3, 1 },
        { 1, 5, 1 },
        { 4, 2, 1 }
    };

    min_sum = ans.minPathSum(grid);
    printf("min_sum: %d\n", min_sum);
    ans.showDP();

    return 0;
}
