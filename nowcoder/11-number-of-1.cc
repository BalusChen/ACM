
/*
 * Copyright (C) Jianyong Chen
 */


#include <climits>
#include <cstdio>


class Solution {
    public:
        int  NumberOf1(int n) {
            int       count;
            unsigned  u;

            u = UINT_MAX;
            u = u & n;
            count = 0;
            while (u != 0) {
                count += u & 1;
                u >>= 1;
            }

            printf("count: %d\n", count);
            return count;
        }
};


int
main(int argc, char **argv)
{
    int       n;
    Solution  ans;

    n = 7;
    ans.NumberOf1(n);

    n = -4;
    ans.NumberOf1(n);

    n = -128;
    ans.NumberOf1(n);

    return 0;
}
