#include <stdio.h>
#include <stdlib.h>


#define INT_MAX_LEN  10
#define true         1
#define false        0
#define bool         int

bool isPalindrome(int x) {
    int   len, x2;
    char  x_str[INT_MAX_LEN];

    if (x < 0) {
        return false;
    }

    x2 = x;
    len = 0;
    while (x2 != 0) {
        x_str[len] = (x2 % 10) + '0';
        x2 /= 10;
        len++;
    }

    while (--len != 0) {
        if (x_str[len] != (x % 10)+'0') {
            return false;
        }
        x /= 10;
    }

    return true;
}

/*
 * TODO: x2 can overflow, but it works well, why?
 */
bool isPalindrome2(int x) {
    int x2;
    int tmp;

    x2 = 0;
    tmp = x;
    while (x != 0) {
        x2 *= 10;
        x2 += (x % 10);
        x /= 10;
    }

    return x2 == tmp;
}

int
main(int argc, char **argv)
{
    // int x = 37;

    for (int i = 0; i < INT32_MAX; i++) {
        printf("isPalindrome(%d) = %d\n", i, isPalindrome2(i));
    }

    return 0;
}
