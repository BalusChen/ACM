#include <vector>
#include <iostream>

class Solution {
    public:
        // one-bit: 0
        // two-bit: 10 11
        bool isOneBitCharacter(std::vector<int> &bits) {
            if (bits.back() == 1)
                return false;

            for (int i = 0; i < bits.size(); ) {
                if (bits[i] == 0) {
                    i++;
                    if (i == bits.size())
                        return true;
                } else if (bits[i] == 1) {
                    i += 2;
                    if (i >= bits.size())
                        return false;
                }
            }

            return false;
        }
};
