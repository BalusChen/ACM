
/*
 * Copyright (C) Jianyong Chen
 */


#include <string>
#include <vector>

class Solution {
    template<typename T>
    using Matrix = std::vector<std::vector<T>>;

    public:
        int countSubstrings(std::string s) {
            int          i;
            Matrix<int>  dp(s.size(), std::vector<int>(s.size(), -1));

            for (i = 0; i < s.size(); i++) {
                dp[i][i] = 1;
                count++;
            }

            aux(0, s.size()-1, s, dp);

            return count;
        }

    private:

        int aux(int i, int j, std::string &s, Matrix<int> &dp) {
            int  middle;

            // printf("aux(%d, %d)\n", i, j);

            if (j < i) {
                return 1;
            }

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            /*
             * 到这里都是 j > i 的了
             */

            aux(i, j-1, s, dp);
            aux(i+1, j, s, dp);
            middle = aux(i+1, j-1, s, dp);
            if (s[i] == s[j] && middle) {
                dp[i][j] = 1;
                count++;

            } else {
                dp[i][j] = 0;
            }

            return dp[i][j];
        }

        int  count = 0;
};


int
main(int argc, char **argv)
{
    Solution     ans;
    std::string  s;

    s = "abcbcadb";
    printf("count: %d\n", ans.countSubstrings(s));

    return 0;
}
