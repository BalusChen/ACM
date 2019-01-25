#include <iostream>
#include <vector>

std::vector<int> countBits(int num) {
    std::vector<int>dp(num+1, -1);
    dp[0] = 0;

    for (int i = 1; i <= num; ++i) {
        dp[i] = dp[(i & (i-1))] + 1;
    }
    return dp;
}

void printVector(const std::vector<int>& ivec) {
    for (auto c : ivec) {
        std::cout << c << "  ";
    }
    std::cout << '\n';
}

void test() {
    printVector(countBits(7));
    printVector(countBits(2));
    printVector(countBits(12));
    printVector(countBits(16));
}

int main() {
    test();

    return 0;
}
