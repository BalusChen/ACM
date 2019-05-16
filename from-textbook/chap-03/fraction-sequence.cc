
/*
 * Copyright (C) Jianyong chen
 */

#include <iostream>
#include <vector>


/*
 * 递推分数数列：
 *      1/2, 3/5, 4/7, 6/10, 8/13 9/15
 *
 * 第 i 项的分母 d 与分子 c 存在关系 d = c + i
 * 而分子 c 为与前 i - 1 项中所有分子分母都不同的最小正整数
 *
 * 对于指定的正整数，求出该数列的第 n 项，以及前 n 项中的最大项
 */

static void FractionSequence(int n);

int
main(int argc, char **argv)
{
    int  n;

    std::cout << "Please input n: ";
    std::cin >> n;

    FractionSequence(n);

    return 0;
}

static void
FractionSequence(int n)
{
    int               i, j, next_c, last_i, max_i;
    std::vector<int>  c, d;

    c.resize(n + 1);
    d.resize(n + 1);
    c[1] = 1;
    d[1] = 2;
    c[2] = 3;
    d[2] = 5;
    last_i = 2;
    max_i = 2;

    for (i = 3; i <= n; i++) {

        /*
         * 问题在于如何确定 c[i]
         *
         * 由于 c[i] 是与前面所有的 c[j], d[j] (j < i) 都不同的最小整数
         * 那么说明 c[i] > c[i-1]
         *
         * 而且当 i > 2 时，c[i] < d[i-1]，这一点很重要。
         *
         * 知道了👆这两点之后，就可以确定c[i-1] < c[i] < d[i-1]
         */

        // 从 c[i-1] 到 d[i-1] 每个都尝试一遍
        for (next_c = c[i-1]+1; next_c < d[i-1]; next_c++) {

            // 从第一项开始比较，查看是否有与之相同的
            for (j = i;
                j < i && next_c != c[j] && next_c != d[j];
                 j++)
            {
                /* do nothing */
            }

            if (j == i) {

                c[i] = next_c;
                d[i] = c[i] + i;

                // update the index of the maximum fraction
                if (c[i] * d[max_i] > d[i] * c[max_i]) {
                    max_i = i;
                }

                break;
            }

        }
    }

#ifdef DEBUG

    for (int i = 1; i <= n; i++) {
        printf("%d / %d\n", c[i], d[i]);
    }

#endif

    std::cout << "the " << n << "th fraction is: " << c[n] << " / " << d[n] << std::endl;
    std::cout << "max: " << c[max_i] << " / " << d[max_i] << std::endl;
}
