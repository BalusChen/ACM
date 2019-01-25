#include <vector>
#include <map>
#include <utility>

class Solution {
    public:
        int majorityElement(std::vector<int> &nums) {
            std::map<int, int> count_map;

            for (auto c : nums)
                count_map[c]++;

            for (const auto &p : count_map)
                if (2*p.second > nums.size())
                    return p.first;

            return 0; /* 避免编译器警告 */
        }
};
