
/*
 * Copyright (C) Jianyong Chen
 */

#include <string>
#include <vector>
#include <cstdio>

class Solution
{
    template<typename T>
    using Matrix = std::vector<std::vector<int>>;

    public:
        int longestPalindromeSubseq(std::string s) {
            if (s.size() <= 1) {
                return s.size();
            }

            dp = Matrix<int>(s.size(), std::vector<int>(s.size(), -1));

            aux(s, 0, s.size()-1);
            return dp.front().back();
        }

        int aux(const std::string &str, int i, int j) {
            int  left, right, middle;

            if (dp[i][j] != -1) {
                return dp[i][j];
            }

            if (i == j) {
                dp[i][j] = 1;
                return dp[i][j];
            }

            if (str[i] == str[j]) {

                if (i == j-1) {
                    middle = 0;

                } else {
                    middle = aux(str, i+1, j-1);
                }

                dp[i][j] = middle + 2;
                return dp[i][j];

            } else {

                left = aux(str, i, j-1);
                right = aux(str, i+1, j);

                dp[i][j] = std::max(left, right);
                return dp[i][j];
            }
        }

    private:
        Matrix<int>   dp;
};


int
main(int argc, char **argv)
{
    Solution     ans;
    std::string  str;

    str = "bbbab";
    printf("#palindrome(%s): %d\n", str.c_str(), ans.longestPalindromeSubseq(str));

    str = "cbbd";
    printf("#palindrome(%s): %d\n", str.c_str(), ans.longestPalindromeSubseq(str));

    str = "abc";
    printf("#palindrome(%s): %d\n", str.c_str(), ans.longestPalindromeSubseq(str));

    str = "c";
    printf("#palindrome(%s): %d\n", str.c_str(), ans.longestPalindromeSubseq(str));

    str = "cc";
    printf("#palindrome(%s): %d\n", str.c_str(), ans.longestPalindromeSubseq(str));

    return 0;
}
