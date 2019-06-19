
/*
 * Copyright (C) Jianyong Chen
 */

#include <cstdio>
#include <vector>
#include <string>

class Solution
{
    template<typename T>
    using Matrix = std::vector<std::vector<T>>;

    public:
        int minDistance(std::string str1, std::string str2) {
            int  i;

            if (str1.empty() || str2.empty()) {
                return str1.size() + str2.size();
            }

            dp = Matrix<int>(str1.size()+1, std::vector<int>(str2.size()+1, -1));
            this->str1 = str1;
            this->str2 = str2;

            /*
             * dp[i][j] 表示 str1 的前 i 个字符子串到 str2 的前 j 个字符子串的编辑距离
             */
            for (i = 0; i < str1.size()+1; i++) {
                dp[i][0] = i;
            }

            for (i = 0; i < str2.size()+1; i++) {
                dp[0][i] = i;
            }

            aux(str1.size(), str2.size());
            return dp.back().back();
        }

        int aux(int i, int j) {
            int  deletion, insertion, substitution;

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            deletion = aux(i-1, j);
            insertion = aux(i, j-1);
            substitution = aux(i-1, j-1);

            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = min3(deletion+1, insertion+1, substitution);

            } else {
                dp[i][j] = min3(deletion, insertion, substitution) + 1;
            }

            return dp[i][j];
        }

        void showDP() const {
            for (auto &v : dp) {
                for (auto c : v) {
                    printf("%d  ", c);
                }

                printf("\n");
            }
        }

    private:
        Matrix<int>  dp;
        std::string  str1, str2;

    private:
        int min3(int a, int b, int c) {
            return std::min(std::min(a, b), c);
        }
};


class Solution2
{
    public:
        int minDistance(std::string str1, std::string str2) {
            if (str1.empty() || str2.empty()) {
                return str1.size() + str2.size();   // NOTE: 这种写法有点意思
            }

            int  i, j, dp[str1.size()+1][str2.size()+1];
            int  insertion, deletion, substitution, cost;

            /* 首先处理边界条件 */

            /*
             * 从 str1[0..i] 到 str2[0..0] 需要删除 i 次
             */
            for (i = 0; i < str1.size()+1; i++) {
                dp[i][0] = i;
            }

            /*
             * 从 str1[0..0] 到 str2[0..j] 需要插入 j 次
             */
            for (j = 0; j < str2.size()+1; j++) {
                dp[0][j] = j;
            }

            for (i = 1; i < str1.size()+1; i++) {
                for (j = 1; j < str2.size()+1; j++) {
                    cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
                    insertion = dp[i][j-1];
                    deletion = dp[i-1][j];
                    substitution = dp[i-1][j-1];

                    dp[i][j] = min3(insertion+1, deletion+1, substitution+cost);
                }
            }

            return dp[str1.size()][str2.size()];
        }

    private:
        int min3(int a, int b, int c) {
            return std::min(std::min(a, b), c);
        }
};


int
main(int argc, char **argv)
{
    Solution     ans;
    Solution2    ans2;
    std::string  str1, str2;

    str1 = "horse";
    str2 = "ros";
    printf("minDistance(%s, %s): %d\n", str1.c_str(), str2.c_str(),
           ans2.minDistance(str1, str2));

    str1 = "intention";
    str2 = "execution";
    printf("minDistance(%s, %s): %d\n", str1.c_str(), str2.c_str(),
           ans2.minDistance(str1, str2));

    return 0;
}
