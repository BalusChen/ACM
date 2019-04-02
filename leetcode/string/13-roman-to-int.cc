#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

int
romanToInt(std::string roman)
{
    int                            i, cur, ret;
    std::unordered_map<char, int>  sym = {
        { 'I', 1 }, { 'V', 5 }, { 'X', 10 },
        { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 }
    };

    ret = 0;
    for (i = 0; i < roman.size(); i++) {
        cur = sym[roman[i]];

        // special case?
        if (i < roman.size()-1 && cur < sym[roman[i+1]]) {
            ret += (sym[roman[i+1]] - cur);
            i++;
        } else {
            ret += cur;
        }
    }

    return ret;
}

int
main(int argc, char **argv)
{
    std::string  roman = "MCMXCIV";
    int          i;

    roman = "LVIII";
    roman = "III";
    roman = "IX";
    roman = "IV";

    i = romanToInt(roman);
    printf("Integer(%s) = %d\n", roman.data(), i);
    return 0;
}
