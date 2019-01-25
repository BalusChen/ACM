#include <iostream>
#include <vector>
#include <stdio.h>

class Solution {
    public:
        std::vector<int> plusOne(std::vector<int> &digits) {
            int addition = 0;

            for (int i = digits.size()-1; i >= 0; i--) {
                int sum = (digits[i]+1);
                digits[i] = sum % 10;
                addition = sum / 10;
                printf("digits[%d] = %d\n", i, digits[i]);
                printf("addition = %d\n", addition);
                if (addition == 0)
                    break;
            }

            if (addition == 1)
                digits.insert(digits.begin(), 1);

            return digits;
        }
};
        std::vector<int> plusOne(std::vector<int> &digits) {
            int addition = 0;

            for (int i = digits.size()-1; i >= 0; i--) {
                int sum = (digits[i]+1);
                digits[i] = sum % 10;
                addition = sum / 10;
                printf("digits[%d] = %d\n", i, digits[i]);
                printf("addition = %d\n", addition);
                if (addition == 0)
                    break;
            }

            if (addition == 1)
                digits.insert(digits.begin(), 1);

            return digits;
        }

int main(int argc, char **argv) {
    std::vector<int> ivec {9};
    ivec = plusOne(ivec);

    for (auto c : ivec) {
        std::cout << c << '\t';
    }
    std::cout << '\n';
    return 0;
}
