#include <vector>

class Solution {
    public:
        std::vector<int> findDisappearedNumbers(std::vector<int> &numbers) {
            std::vector<int> index(numbers.size());
            std::vector<int> ret;

            for (int i = 0; i < numbers.size(); i++) {
                index[numbers[i]-1]++;
            }

            for (int i = 0; i < index.size(); i++) {
                if (index[i] == 0)
                    ret.push_back(i+1);
            }
            return ret;
        }
};
