
/*
 * Copyright (C) Jianyong Chen
 */

#include <string>
#include <iostream>


class Solution {
    public:
        std::string decodeString(std::string s) {
            int          i;
            std::string  result;

            i = 0;
            while (i < s.size()) {
                if (!isdigit(s[i])) {
                    result.push_back(s[i]);
                    i++;

                } else {
                    i = decodeFromDigit(s, i, result);
                }
            }

            return result;
        }


        int decodeFromDigit(const std::string &s, int idx, std::string &result) {
            int           i, times;
            std::string   part;

            times = 0;
            while (isdigit(s[idx])) {
                times = times * 10 + s[idx] - '0';
                idx++;
            }

            idx++;   // skip left square bracket
            while (s[idx] != ']') {
                if (isdigit(s[idx])) {
                    idx = decodeFromDigit(s, idx, part);

                } else {
                    part.push_back(s[idx]);
                    idx++;
                }
            }
            idx++;  // skip right square bracket

            for (i = 0; i < times; i++) {
                result.append(part);
            }

            return idx;
        }
};

