#include <vector>

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int> &numbers, int target) {
            std::vector<int> index(2);
            for (int i = 0, j = numbers.size()-1; i < j; ) {
                if (numbers[i]+numbers[j] > target)
                    j--;
                else if (numbers[i]+numbers[j] < target)
                    i++;
                else {
                    index[0] = i+1;
                    index[1] = j+1;
                    break;
                }
            }

            return index;
        }
};
