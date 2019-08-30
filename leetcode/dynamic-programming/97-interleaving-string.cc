
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

            for (i = 0; i <= s1.size(); i++) {

                for (j = 0; j <= s2.size(); j++) {

                    if (i == 0 && j == 0) {
                        dp[i][j] = true;

                    } else if (i == 0) {
                        dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);

                    } else if (j == 0) {
                        dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);

                    } else {
                        dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1]))
                                   || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
                    }
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
