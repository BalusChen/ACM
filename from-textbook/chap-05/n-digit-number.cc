
/*
 * Copyright (C) Jianyong Chen
 */

#include <cstdio>

static void solve(int ndigits);


int
main(int argc, char **argv)
{
    int  ndigits;

    while (scanf("%d", &ndigits)) {
        solve(ndigits);
    }

    return 0;
}

static void
solve(int ndigits)
{
    int   i, j, count, res;
    int   target[100] = { 0 };
    bool  is_valid;

    target[0] = 1;
    i = 0;
    is_valid = false;
    count = 0;
    while (target[0] <= 9) {

        /*
         * 前 i 位满足条件，但是没有到 n 位
         * 所以继续向后，看看后面的位是否也满足要求
         */
        if (is_valid && i < ndigits-1) {
            i++;
        }

        /*
         * 检测已取的 i 位数能否被 i 整除
         * NOTE: 这里这种防溢出的方法值得学习
         */
        for (res = 0, j = 0; j <= i; j++) {
            res = res * 10 + target[j];
            res %= (i+1);
        }

        if (res != 0) {

            /*
             * 如果不能被整除的话，那就从在第 i 位上+1(记得要处理进位)
             * 并且向前回溯到最近一个可以被对应的 i 整除的位置上
             */

            target[i]++;
            while (target[i] > 9 && i > 0) {
                target[i] = 0;
                i--;
                target[i]++;
            }

            is_valid = false;

        } else {
            is_valid = true;
        }

        /*
         * 这 n 位都满足要求，说明这是一个解
         * 递增计数器，并将该解输出
         */
        if (is_valid && i == ndigits-1) {
            count++;
            printf("    %d: ", count);

            for (j = 0; j < ndigits; j++) {
                printf("%d", target[j]);
            }

            printf("\n");

            /*
             * 既然这个数字已经满足要求了，那么最低位+1 继续探索下一个可行数字
             * QUESTION: 但是这里有一个不太懂，+1 之后不用处理可能产生的进位么？
             */
            target[i]++;
        }
    }

    if (count == 0) {
        printf("No such %d-digit number!\n", ndigits);
    }
}
