
/*
 * Copyright (C) Jianyong Chen
 */


#include <string>


class Solution {
    public:
        std::string getPermutation(int n, int k) {
            int          i;
            std::string  str;

            for (i = 1; i <= n; i++) {
                str.push_back(i + '0');
            }

            for (i = 1; i < k; i++) {
                nextPermutation(str);
            }

            return str;
        }

        void nextPermutation(std::string &str) {
            int  i, j;

            for (i = str.size() - 1; i > 0; i--) {
                if (str[i] > str[i-1]) {
                    break;
                }
            }

            if (i > 0) {
                i--;
                for (j = str.size() - 1; j >= 0; j--) {
                    if (str[j] > str[i]) {
                        break;
                    }
                }

                std::swap(str[i], str[j]);
                i++;
            }

            std::reverse(str.begin() + i, str.end());
        }
};
