
/*
 * Copyright (C) Jianyong Chen
 */


#include <string>


class Solution {
    public:
        bool isInterleave(std::string s1, std::string s2, std::string s3) {

            if (s1.size() + s2.size() != s3.size()) {
                return false;
            }

            int   i, j;
            bool  dp[s1.size()+1][s2.size()+1];

            dp[0][0] = true;

            for (i = 1; i <= s1.size(); i++) {
                dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
            }

            for (j = 1; j <= s2.size(); j++) {
                dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
            }

            for (i = 1; i <= s1.size(); i++) {

                for (j = 1; j <= s2.size(); j++) {
                    dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1]))
                               || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
                }
            }

            return dp[s1.size()][s2.size()];
        }
};


int
main(int argc, char **argv)
{
    Solution     ans;
    std::string  s1, s2, s3;

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbcbcac";
    printf("%d\n", ans.isInterleave(s1, s2, s3));

    s1 = "aabcc";
    s2 = "dbbca";
    s3 = "aadbbbaccc";
    printf("%d\n", ans.isInterleave(s1, s2, s3));

    return 0;
}
