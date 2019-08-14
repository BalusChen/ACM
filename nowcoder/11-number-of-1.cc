
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


class Solution2 {
    public:
        int  NumberOf1(int n) {
            int  count, mask;

            count = 0;
            mask = 1;
            while (mask != 0) {
                if ((mask & n) != 0) {
                    count++;
                }
                mask <<= 1;
            }

            printf("count: %d\n", count);
            return count;
        }
};


class Solution3 {
    public:
        int  NumberOf1(int n) {
            int  count;

            count = 0;
            while (n != 0) {
                count++;
                n &= (n - 1);
            }

            return count;
        }
};


int
main(int argc, char **argv)
{
    int        n;
    Solution2  ans;

    n = 7;
    ans.NumberOf1(n);

    n = -4;
    ans.NumberOf1(n);

    n = -128;
    ans.NumberOf1(n);

    return 0;
}
