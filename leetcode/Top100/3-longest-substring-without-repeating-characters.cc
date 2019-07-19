
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <string>

class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
            int               left, right, length;
            std::vector<int>  hash(256, 0);

            if (s.size() < 2) {
                return s.size();
            }

            left = 0;
            length = 1;
            for (right = 0; right < s.size(); right++) {
                hash[s[right]]++;

                while (hash[s[right]] != 1) {
                    hash[s[left]]--;
                    left++;
                }

                length = std::max(length, right-left+1);
            }

            return length;
        }
};
