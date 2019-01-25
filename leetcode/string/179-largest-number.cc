#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

std::string IntToString(int val) {
    if (val == 0) {
        return "0";
    }
    std::string part = "";

    while (val != 0) {
        char digit = val % 10 + '0';
        val /= 10;
        part = digit + part;
    }

    return part;
}

class Greater {
    public:
    bool operator()(const std::string &str1, const std::string &str2) {
        std::string order1 = str1 + str2;
        std::string order2 = str2 + str1;
        return order1 > order2;
    }
};

std::string largestNumber(std::vector<int> &nums) {
    std::vector<std::string> digits (nums.size());
    Greater gt;

    for (int i = 0; i < nums.size(); ++i) {
        digits[i] = IntToString(nums[i]);
    }
    std::sort(digits.begin(), 
            digits.end(),
            [&] (auto &s1, auto &s2) ->bool {return gt(s1, s2); });

    std::string ret = "";
    for (auto it = digits.begin(); it != digits.end(); ++it) {
        ret += *it;
    } 
    if (ret[0] == '0')
        ret = '0';

    return ret;
}


int main(int argc, char *argv[]) {
    int d1 = 3579;
    std::cout << "d1 = " << IntToString(d1) << std::endl;
    std::cout << "d1 = " << IntToString(0) << std::endl;
    std::cout << "d1 = " << IntToString(2) << std::endl;

    std::vector<int> ivec1 {3, 30, 34, 5, 9};
    std::cout << "max = " << largestNumber(ivec1) << std::endl;

    std::vector<int> ivec2 {0, 0, 0, 0};
    std::cout << "max = " << largestNumber(ivec2) << std::endl;
}
