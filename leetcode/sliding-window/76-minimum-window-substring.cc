
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <string>

class Solution {
    public:
        std::string minWindow(std::string s, std::string t) {
            int               left, right, count, min;
            std::string       ret;
            std::vector<int>  hash(256, 0);

            if (s.size() < t.size()) {
                return ret;
            }

            for (auto c : t) {
                hash[c]++;
            }

            count = 0;
            left = 0;
            min = s.size() + 1;
            for (right = 0; right < s.size(); right++) {
                hash[s[right]]--;
                if (hash[s[right]] >= 0) {
                    /*
                     * 说明该字符也在字符串 t 中
                     */
                    count++;
                }

                while (left <= right && hash[s[left]] < 0) {
                    hash[s[left]]++;
                    left++;
                }

#if 0
                printf("left: %d\tright: %d\tcount: %d\n", left, right, count);
#endif
                if (count == t.size() && min > (right-left+1)) {
                    min = right - left + 1;
                    ret = s.substr(left, min);
#if 0
                    printf("min: %d\tret: %s\n", min, ret.c_str());
#endif
                }
            }

            return ret;
        }
};
