

/*
 * Copyright (C) Jianyong Chen
 */

class Solution {
    public:
        double Power(double base, int exp) {
            if (exp < 0) {
                return 1.0 / aux(base, -exp);

            } else {
                return aux(base, exp);
            }
        }

        double aux(double base, int exp) {
            if (exp == 0) {
                return 1;
            }
            if (exp == 1) {
                return base;
            }

            if (exp % 2 == 0) {
                return aux(base * base, exp / 2);

            } else {
                return aux(base, exp - 1) * base;
            }
        }
};
