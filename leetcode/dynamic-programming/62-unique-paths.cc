#include <cstdio>
#include <vector>


class Solution
{
    public:
        int uniquePaths(int m, int n) {
            this->m = m;
            this->n = n;
            this->dp = std::vector<std::vector<int>>(m, std::vector<int>(n, -1));

            return aux(0, 0);
        }

        void showDP() const {
            for (auto &v : dp) {
                for (auto c : v) {
                    printf("%3d ", c);
                }
                printf("\n");
            }
        }


    private:
        int aux(int i, int j) {
            int  down, right;

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            if (i == m-1 || j == n-1) {
                return 1;
            }

            // 求出向下走一步之后到终点的路径条数
            if (dp[i+1][j] != -1) {
                down = dp[i+1][j];

            } else {
                down = aux(i+1, j);
                dp[i+1][j] = down;
            }

            // 求出向右走一步之后到终点的路径条数
            if (dp[i][j+1] != -1) {
                right = dp[i][j+1];
            } else {
                right = aux(i, j+1);
                dp[i][j+1] = right;
            }

            return down + right;
        }

        int                            m, n;
        std::vector<std::vector<int>>  dp;
};


int
main(int argc, char **argv)
{
    int       m, n, sum;
    Solution  ans;

    if (argc != 3) {
        fprintf(stderr, "usage: %s m n\n", argv[0]);
        exit(-1);
    }

    m = atoi(argv[1]);
    n = atoi(argv[2]);
    sum = ans.uniquePaths(m, n);

    printf("sum: %d\n", sum);
    // ans.showDP();

    exit(0);
}
