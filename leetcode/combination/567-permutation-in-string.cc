
/*
 * Copyright (C) Jianyong Chen
 */


#include <string>


class Solution {
	public:
		bool checkInclusion(std::string s1, std::string s2) {
			int   i, l, r, count;
			int   hash[256] = { 0 };

			if (s2.size() < s1.size()) {
				return false;
			}

			for (i = 0; i < s1.size(); i++) {
				hash[s1[i]]++;
			}

			l = 0;
            count = 0;
			for (r = 0; r < s2.size(); r++) {
				hash[s2[r]]--;

				if (hash[s2[r]] >= 0) {
					count++;
					if (count == s1.size()) {
						return true;
					}

				} else {
                    while (l <= r && hash[s2[r]] < 0) {
                        hash[s2[l]]++;
                        if (hash[s2[l]] > 0) {
                            count--;
                        }
                        l++;
                    }
				}
			}

            printf("count: %d\n", count);

			return count == s1.size() ? true : false;;
		}
};


int
main(int argc, char **argv)
{
    Solution     ans;
    std::string  s1, s2;

    s1 = "ab";
    s2 = "ab";
    printf("ans: %d\n", ans.checkInclusion(s1, s2));

    s1 = "adc";
    s2 = "dcda";
    printf("ans: %d\n", ans.checkInclusion(s1, s2));

    s1 = "ab";
    s2 = "eidbaooo";
    printf("ans: %d\n", ans.checkInclusion(s1, s2));

    s1 = "ab";
    s2 = "eidboaoo";
    printf("ans: %d\n", ans.checkInclusion(s1, s2));

    return 0;
}

