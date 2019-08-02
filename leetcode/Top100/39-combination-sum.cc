
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>

class Solution {
    private:
        template<typename T>
        using Matrix = std::vector<std::vector<T>>;

    public:
        Matrix<int> combinationSum(std::vector<int>& candidates, int target) {
            std::vector<int>  cur;

            std::sort(candidates.begin(), candidates.end());

            aux(candidates, target, cur, 0);

            return results;
        }

        void aux(std::vector<int> &candidates, int rest, std::vector<int> &cur, int idx) {
            int  i;

            if (rest < 0) {
                return;

            } else if (rest == 0) {
                results.push_back(cur);
                return;
            }

            for (i = idx; i < candidates.size() && candidates[i] <= rest; i++) {
                cur.push_back(candidates[i]);
                aux(candidates, rest-candidates[i], cur, i);
                cur.pop_back();
            }
        }

    private:
        Matrix<int>  results;
};
