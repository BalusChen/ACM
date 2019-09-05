
/*
 * Copyright (C) Jianyong Chen
 */


class Solution
{
    public:
        bool isPowerOfTwo(int n)
        {
            long  l;

            l = n;
            return l != 0 && (l & (l-1)) == 0;
        }

};
