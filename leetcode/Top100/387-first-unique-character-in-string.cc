
/*
 * Copyright (C) Jianyong Chen
 */

#include <string>


class Solution {
    public:
        int firstUniqChar(std::string s) {
            int   i;
            int   hash[256] = { 0 };

            for (i = 0; i < s.size(); i++) {
                hash[s[i]]++;
            }

            for (i = 0; i < s.size(); i++) {

                if (hash[s[i]] == 1) {
                    return i;
                }
            }

            return -1;
        }
};
