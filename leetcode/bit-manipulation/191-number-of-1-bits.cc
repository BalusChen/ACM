
/*
 * Copyright (C) Jianyong Chen
 */


#include <stdint.h>


class Solution
{
    public:
        int hammingWeight(uint32_t n)
        {
            int  rv;

            rv = 0;
            while (n != 0) {
                n &= (n - 1);
                rv++;
            }

            return rv;
        }
};
