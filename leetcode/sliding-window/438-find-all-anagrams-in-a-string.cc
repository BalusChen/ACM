
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <string>

class Solution {
	public:
		std::vector<int> findAnagrams(std::string s, std::string p) {
			int               left, right, count;
			std::vector<int>  output;
			std::vector<int>  hash(26, 0);

			if (s.size() < p.size()) {
				return output;
			}

			for (auto c : p) {
				hash[c-'a']++;
			}

            count = 0;
			left = 0;
			for (right = 0; right < s.size(); right++) {
				hash[s[right]-'a']--;
                if (hash[s[right]-'a'] >= 0) {
                    count++;
                }

                if (right >= p.size()) {
                    hash[s[left]-'a']++;
                    if (hash[s[left]-'a'] > 0) {
                        count--;
                    }

                    left++;
                }

                if (count == p.size()) {
                    output.push_back(left);
                }
			}

			return output;
		}
};
