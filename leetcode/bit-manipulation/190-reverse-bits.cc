
/*
 * Copyright (C) Jianyong Chen
 */


#include <stdint.h>
#include <limits.h>
#include <stdio.h>


class Solution
{
    public:
        uint32_t reverseBits(uint32_t n) {
            int  i, l, r, rv;

            rv = n;
            for (i = 0; i < 16; i++) {
                l = (n >> (31 - i)) & 1;
                r = (n >> i) & 1;

                printf("l:%d\tr:%d\n", l, r);

                if (l ^ r) {    // 不同才需要交换
                    if (l == 0) {

                        /* l == 0 && r == 1 */
                        rv &= ~(1 << i);        // clear bit(index i)
                        rv |= (1 << (31 - i));  // set bit(index 31-i)

                    } else {
                        /* l == 1 && r == 0 */
                        rv |= (1 << i);
                        rv &= ~(1 << (31 - i));
                    }
                }
            }

            return rv;
        }
};


int
main(int argc, char **argv)
{
    int       n;
    Solution  ans;

    n = 43261596;
    printf("%d\n", ans.reverseBits(n));

    n = 0;
    printf("%d\n", ans.reverseBits(n));

    return 0;
}
