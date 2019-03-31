#include <string>
#include <vector>
#include <iostream>

std::string
intToRoman(int num) {
    int                i, dis, NoX;
    std::string        roman;
    std::vector<int>   val {  1,   5,  10,   50, 100, 500, 1000 };
    std::vector<char>  sym { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };


    i = sym.size() - 1;
    do {
        NoX = num / val[i]; // Number of X('I', 'V', ...)
        num = num % val[i]; // remains
        roman.append(std::string(NoX, sym[i])); // NoX == 0 is also fine

        // distance between current symbol and next symbol to fom a sepcial case
        // for example: CD(dis = 1), CM(dis = 2), XL, XC, IV, IX
        dis = (i % 2) ? 1 : 2;
        // special case: 900, 400, 90, 9, 4
        if (i >= dis && num >= (val[i] - val[i-dis])) {
            num -= (val[i] - val[i-dis]);
            roman.push_back(sym[i-dis]);
            roman.push_back(sym[i]);
            // if remains 999(for example), then 999-900 < 100,
            // so we can just skip 500(but we cannot skip 100 since 999-900 > 90)
            i -= (dis-1);
        }
        i--;
    } while (num != 0 && i >= 0);

    return roman;
}


int
main(int argc, char **argv)
{
    std::string roman;
    int num;

    while (std::cin >> num) {
        roman = intToRoman(num);
        std::cout << "roman(" << num << ") " << "= " << roman << std::endl;
    }

}
