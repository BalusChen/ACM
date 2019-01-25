#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>

class Solution {
    public:
        struct CountAndIndex {
            CountAndIndex() = default;
            CountAndIndex(int c, int b, int e) :
                count(c), beg(b), end(e) {  }
            int count = 0;
            int beg = 0;
            int end = 0;
        };

        int findShortestSubArray(std::vector<int> &nums) {
            std::map<int, int> count;
            // VCI: value, count, index
            std::unordered_map<int, CountAndIndex> VCI;
            int max = 0;
            int min = 0;

            for (auto num : nums)
                count[num]++;
            for (auto &p : count) {
                std::cout << p.first << "\t" << p.second << std::endl;
                if (max < p.second)
                    max = p.second;
            }

            for (int i = 0; i < nums.size(); i++) {
                if (VCI.find(nums[i]) == VCI.end()) {
                    VCI.insert({nums[i], CountAndIndex(1, i, nums.size())});
                } else {
                    CountAndIndex &cai = VCI[nums[i]];
                    cai.count++;
                    if (cai.count == max)
                        cai.end = i;
                }
            }

            for (auto &p : VCI) {
                std::cout << "first: " << p.first << std::endl;
                std::cout << "second: " << p.second.count << "\t"
                          << p.second.beg << "\t"
                          << p.second.beg << "\n";
                int interval = (p.second.end-p.second.beg+1);
                if (min > interval)
                    min = interval;
            }

            return min;
        }
};
        struct CountAndIndex {
            CountAndIndex() = default;
            CountAndIndex(int c, int b, int e) :
                count(c), beg(b), end(e) {  }
            int count = 0;
            int beg;
            int end;
        };
        int findShortestSubArray(std::vector<int> &nums) {
            std::map<int, int> count;
            // VCI: value, count, index
            std::unordered_map<int, CountAndIndex> VCI;
            int max = 0;
            int min = nums.size();

            for (auto num : nums)
                count[num]++;
            for (auto &p : count) {
                if (max < p.second)
                    max = p.second;
            }

            for (int i = 0; i < nums.size(); i++) {
                if (VCI.find(nums[i]) == VCI.end()) {
                    int end = (max == 1 ? i : nums.size());
                    VCI.insert({nums[i], CountAndIndex(1, i, end)});
                } else {
                    CountAndIndex &cai = VCI[nums[i]];
                    cai.count++;
                    if (cai.count == max)
                        cai.end = i;
                }
            }

            for (auto &p : VCI) {
                int interval = p.second.end == nums.size() ? nums.size() : (p.second.end-p.second.beg+1);
                if (min > interval)
                    min = interval;
            }

            return min;
        }
