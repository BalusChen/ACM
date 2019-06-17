
/*
 * Copyright (C) Jianyong Chen
 */

#include <cstdio>
#include <string>

int
gcd(int a, int b)
{
    while (b != 0) {
        a = a % b;
        std::swap(a, b);
    }

    return a;
}


int
gcd2(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}


int
main(int argc, char **argv)
{
    int  a, b;

    a = 1;
    b = 2;
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("gcd2(%d, %d) = %d\n", a, b, gcd2(a, b));

    a = 2;
    b = 1;
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("gcd2(%d, %d) = %d\n", a, b, gcd2(a, b));

    a = 3;
    b = 7;
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("gcd2(%d, %d) = %d\n", a, b, gcd2(a, b));

    a = 4;
    b = 12;
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("gcd2(%d, %d) = %d\n", a, b, gcd2(a, b));

    a = 12;
    b = 4;
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("gcd2(%d, %d) = %d\n", a, b, gcd2(a, b));

    a = 17;
    b = 37;
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));
    printf("gcd2(%d, %d) = %d\n", a, b, gcd2(a, b));


    return 0;
}
