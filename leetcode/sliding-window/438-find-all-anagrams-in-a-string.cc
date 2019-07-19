
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <string>

class Solution {
	public:
		std::vector<int> findAnagrams(std::string s, std::string p) {
			int               left, right;
			std::vector<int>  output;
			std::vector<int>  hash1(26, 0), hash2(26, 0);

			if (s.size() < p.size()) {
				return output;
			}

			for (auto c : p) {
				hash1[c-'a']++;
			}

			left = 0;
			for (right = 0; right < s.size(); right++) {
				hash2[s[right]-'a']++;

				if (hash1 == hash2) {
					output.push_back(left);
				}

				if (right-left+1 >= p.size()) {
					hash2[s[left]-'a']--;
					left++;
				}
			}

			return output;
		}
};
