
/*
 * Copyright (C) Jianyong chen
 */

#include <iostream>
#include <vector>


/*
 * 已知递推数列：
 *      a(1) = 1, a(2i) = a(i) + 1, a(2i+1) = a(i) + a(i+1)
 *
 * 试求该数列的第 n 项，以及前 n 项中的所有最大项，并给出最大项的值
 */


static void WiggleSequence(int n);


int
main(int argc, char **argv)
{
    int  n;

    std::cout << "Please input n: ";
    std::cin >> n;

    WiggleSequence(n);

    return 0;
}


static void
WiggleSequence(int n)
{
    std::vector<int>  results;
    int               i, max;

    if (n <= 0) {
        return;
    }

    // results[0] 不用
    results.resize(n + 1);
    results[1] = 1;
    max = 1;

    for (i = 2; i <= n; i++) {

        if (i % 2 == 1) {   // odd
            results[i] = results[(i + 1) / 2] + results[(i - 1) / 2];

        } else {    // even
            results[i] = results[i / 2] + 1;
        }

        if (max < results[i]) {
            max = results[i];
        }
    }

    std::cout << "result[n] = " << results[n] << std::endl;
    std::cout << "max: " << max << std::endl;
    std::cout << "max item:  ";

    for (int i = 1; i <= n; i++) {
        if (results[i] == max) {
            std::cout << i << '\t';
        }
    }

    std::cout << std::endl;
}
