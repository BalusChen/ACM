
/*
 * Copyright (C) Jianyong Chen
 */

#include <cstdio>
#include <vector>

template<typename T>
using Matrix = std::vector<std::vector<T>>;

class Solution
{

    public:
        int optimal_path_in_triangle(Matrix<int> &dot_value_triangle) {
            int  i;

            this->triangle = &dot_value_triangle;
            this->dp = Matrix<int>(triangle->size(), std::vector<int>(triangle->size(), -1));
            this->direction = Matrix<char>(triangle->size(), std::vector<char>(triangle->size()));

            for (i = 0; i < dp.size(); i++) {
                dp.back()[i] = dot_value_triangle.back()[i];
            }

            aux(0, 0);
            return dp[0][0];
        }

        int aux(int i, int j) {
            int  left, right;

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            left = aux(i+1, j);
            right = aux(i+1, j+1);

            printf("i = %d\tj = %d\n", i, j);
            dp[i][j] = std::min(left, right) + (*triangle)[i][j];
            direction[i][j] = left < right ? 'L' : 'R';

            return dp[i][j];
        }

        void showDP() const {
            int  i, j;

            for (i = 0; i < dp.size(); i++) {
                for (j = 0; j <= i; j++) {
                    printf("%3d  ", dp[i][j]);
                }

                printf("\n");
            }
        }

        void print_path() const {
            int  i, j;

            for (auto &v: direction) {
                for (auto dir : v) {
                    printf("%c  ", dir);
                }
                printf("\n");
            }

            printf("path: ");
            for (i = 0, j = 0; i < triangle->size()-1; i++) {
                printf("%d->", (*triangle)[i][j]);

                if (direction[i][j] == 'R') {
                    j++;
                }
            }

            printf("%d\n", (*triangle)[i][j]);
        }

    private:
        Matrix<int>    dp;
        Matrix<int>   *triangle;
        Matrix<char>   direction;

};


int
main(int argc, char **argv)
{
    int          sum;
    Solution     ans;
    Matrix<int>  triangle;


    triangle = {

        { 22 },
        { 14, 19 },
        { 30, 25, 10 },
        { 8, 20, 12, 27 },
        { 6, 25, 32, 6, 4 },
        { 6, 10, 10, 6, 2, 32 },
        { 32, 29, 2, 13, 15, 3, 24 }

    };

    sum = ans.optimal_path_in_triangle(triangle);
    printf("sum: %d\n", sum);
    ans.showDP();
    ans.print_path();

    return 0;
}
