
/*
 *
 */

#include <vector>
#include <string>
#include <cstdio>


class Solution
{
        struct pos {
            pos()
                : beg(-1), end(-1) {  }

            pos(int i, int j)
                : beg(i), end(j) {  }

            int  beg;
            int  end;
        };

    public:
        std::string longestPalindrome(std::string s) {
            if (s.empty()) {
                return s;
            }

            pos  palindrome_pos;

            dp = Matrix<pos>(s.size(), std::vector<pos>(s.size(), pos()));
            str = &s;

            aux(0, s.size()-1);
            palindrome_pos = dp.front().back();

            return s.substr(palindrome_pos.beg, palindrome_pos.end - palindrome_pos.beg + 1);
        }

        void showDP() const {
            for (auto & v : dp) {
                for (auto c : v) {
                    printf("<%d>  ", c.end - c.beg+ 1);
                }

                printf("\n");
            }
        }

    private:

        int aux(int i, int j) {
            int  left, right, middle;

            if (dp[i][j].beg != -1 && dp[i][j].end != -1) {
                return dp[i][j].end - dp[i][j].beg + 1;
            }

            if (i == j) {
                dp[i][j] = pos(i, j);
                return 1;
            }

            if ((*str)[i] == (*str)[j]) {

                if (i + 1 == j) {

                    /*
                     * 字符串的长度为偶数时需要注意
                     */

                    dp[i][j] = pos(i, j);
                    return 2;

                } else {
                    middle = aux(i+1, j-1);

                    if (middle == j-i-1) {
                        dp[i][j] = pos(i, j);
                        return dp[i][j].end - dp[i][j].beg + 1;
                    }
                    /* else: fall through */
                }
            }

            left = aux(i, j-1);
            right = aux(i+1, j);

            if (left > right) {
                dp[i][j] = dp[i][j-1];

            } else {
                dp[i][j] = dp[i+1][j];
            }

            return dp[i][j].end - dp[i][j].beg + 1;
        }

        template<typename T>
        using Matrix = std::vector<std::vector<T>>;


        Matrix<pos>  dp;
        std::string  *str;
};


int
main(int argc, char **argv)
{
    Solution     ans;
    std::string  str, palindrome;


    str = "babad";
    palindrome = ans.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());
    ans.showDP();

    str = "cbbd";
    palindrome = ans.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());
    ans.showDP();

    str = "aacbbcddddddd";
    palindrome = ans.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());
    ans.showDP();

    str = "aba";
    palindrome = ans.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());
    ans.showDP();

    str = "c";
    palindrome = ans.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());
    ans.showDP();

    str = "abcda";
    palindrome = ans.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());
    ans.showDP();

    str = "babadada";
    palindrome = ans.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());
    ans.showDP();

    str = "cbbd";
    palindrome = ans.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());
    ans.showDP();

    return 0;
}
