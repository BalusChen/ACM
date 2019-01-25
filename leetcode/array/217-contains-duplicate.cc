#include <vector>
#include <map>
#include <set>

class Solution {
    public:
        bool containsDuplicate(std::vector<int> &nums) {
            std::set<int> i_set(nums.begin(), nums.end());

            if (i_set.size() == nums.size())
                return true;
            else
                return false;
        }
};
