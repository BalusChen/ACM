#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int reverse(int x) {
    long    lx;
    long    val;    /* use long rather than int */

    // cannot use `x` but use `lx` in case that `x == INT_MIN`(-INT_MIN will overflow in int)
    lx = (x < 0) ? -(long) x : (long) x;
    val = 0;

    printf("lx = %ld\n", lx);

    while (lx != 0) {
        val *= 10;
        val += lx % 10;
        lx /= 10;
    }


    // check if the result overflows
    if (val > INT32_MAX) {
        return 0;
    }

    return (x < 0) ? -val : val;
}

int
main(int argc, char **argv)
{
    int x = INT32_MIN;

    printf("%d reverse to: %d\n", x, reverse(x));

    printf("-10 %% 7 = %d\n", -10%7);
}
