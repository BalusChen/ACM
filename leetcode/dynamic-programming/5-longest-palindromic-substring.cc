
/*
 * Copyright (C) Jianyong Chen
 */

#include <vector>
#include <string>
#include <cstdio>

class Solution3
{
    public:

        std::string longestPalindrome(std::string s) {
            int  i, len1, len2, cur_len, max_len, start;

            if (s.size() <= 1) {
                return s;
            }

            max_len = 1;
            start = 0;
            for (i = 0; i < s.size(); i++) {
                len1 = expandFromCenter(s, i, i);
                len2 = expandFromCenter(s, i, i+1);

                cur_len = std::max(len1, len2);
                if (cur_len > max_len) {
                    max_len = cur_len;
                    start = i - (cur_len - 1) / 2;
                }
            }

            return s.substr(start, max_len);
        }

    private:
        int expandFromCenter(const std::string &str, int left, int right) const {

            while (left >= 0 && right < str.size() && str[left] == str[right]) {
                left--;
                right++;
            }

            return right - left - 1;
        }
};


class Solution2
{
    private:
        template<typename T>
        using Matrix = std::vector<std::vector<int>>;

    public:

        std::string longestPalindrome(std::string s) {
            if (s.size() <= 1) {
                return s;
            }

            dp_ = Matrix<int> (s.size(), std::vector<int>(s.size(), -1));

            str_ = &s;
            beg_ = 0;
            max_len_ = 1;

            aux(0, s.size()-1);

            return s.substr(beg_, max_len_);
        }

        void showDP() {
            for (auto & v : dp_) {
                for (auto c : v) {
                    printf("%d  ", c);
                }

                printf("\n");
            }
        }

        int aux(int i, int j) {
            int  left, right, middle;

            if (dp_[i][j] != -1) {
                return dp_[i][j];
            }

            if (i == j) {
                dp_[i][j] = 1;
                return 1;
            }

            if ((*str_)[i] == (*str_)[j]) {

                if (j - i == 1) {
                    dp_[i][j] = 2;
                    if (max_len_ < 2) {
                        max_len_ = 2;
                        beg_ = i;
                    }

                    return 2;
                }

                middle = aux(i+1, j-1);

                if (middle == j-i-1) {

                    dp_[i][j] = middle + 2;

                    if (max_len_ < dp_[i][j]) {
                        max_len_ = dp_[i][j];
                        beg_ = i;
                    }

                    return middle+2;
                } /* else: fall through */

            }

            left = aux(i, j-1);
            right = aux(i+1, j);

            if (left > right) {
                dp_[i][j] = left;

            } else {
                dp_[i][j] = right;
            }

            return dp_[i][j];
        }


    private:

        int           beg_, max_len_;
        Matrix<int>   dp_;
        std::string  *str_;
};


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
    Solution2    ans2;
    Solution3    ans3;
    std::string  str, palindrome;


    str = "babad";
    palindrome = ans3.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());

    str = "cbbd";
    palindrome = ans3.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());

    str = "aacbbcddddddd";
    palindrome = ans3.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());

    str = "aba";
    palindrome = ans3.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());

    str = "c";
    palindrome = ans3.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());

    str = "abcda";
    palindrome = ans3.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());

    str = "babadada";
    palindrome = ans3.longestPalindrome(str);
    printf("palindrome(%s) = %s\n", str.c_str(), palindrome.c_str());

    return 0;
}
