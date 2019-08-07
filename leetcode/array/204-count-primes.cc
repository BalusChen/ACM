
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>


class Solution {
    public:
        int countPrimes(int n) {
            int                i, j, count;
            std::vector<bool>  is_prime(n, true);

            if (n < 2) {
                return 0;
            }

            count = 0;
            is_prime[0] = false;
            is_prime[1] = false;
            for (i = 2; i < n; i++) {
                if (is_prime[i]) {
                    count++;

                    for (j =  2 * i; j < n; j += i) {
                        is_prime[j] = false;
                    }
                }
            }

            return count;
        }
};
