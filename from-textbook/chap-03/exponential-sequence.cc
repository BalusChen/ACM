
/*
 * Copyright (C) Jianyong Chen
 */

#include <iostream>
#include <cmath>


/*
 * 设 x、y 为非负整数，试计算集合
 *      M = {2^x, 3^y | x >= 0, y >= 0}
 * 的元素从小到大的双幂序列的第 n 项与前 n 项之和
 */


static void DualExponentialSequence(int n);

int
main(int argc, char **argv)
{
    int  n;

    std::cout << "Please input n: ";
    std::cin >> n;

    DualExponentialSequence(n);

    return 0;
}

static void
DualExponentialSequence(int n)
{
    int   i;
    long  p2, p3, k, sum;

    p2 = 1;
    p3 = 1;
    sum = 0;

    for (i = 1; i <= n; i++) {

        k = std::min(p2, p3);
        sum += k;

        if (p2 <= p3) {
            p2 *= 2;

        } else {
            p3 *= 3;
        }
    }


    std::cout << "the " << n << "th element is: " << k << std::endl;
    std::cout << "sum: " << sum << std::endl;
}
