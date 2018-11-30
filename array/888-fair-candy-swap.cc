#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <unordered_set>

class Solution {
    public:
        std::vector<int> fairCandySwap(std::vector<int> &A, std::vector<int> &B) {
            int diff = (std::accumulate(A.begin(), A.end(), 0) - std::accumulate(B.begin(), B.end(), 0)) / 2;
            std::unordered_set<int> u_set(A.begin(), A.end());
            for (auto b : B)
                if (u_set.count(b+diff))
                    return {b+diff, b};
        }
};
