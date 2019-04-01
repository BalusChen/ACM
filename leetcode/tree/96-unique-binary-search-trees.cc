#include <stdio.h>
#include <vector>
#include <stdlib.h>

std::vector<std::vector<int>> dp;

int aux_1(int lo, int root, int hi);
int aux_2(int lo, int hi);

int numTrees(int n) {
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        dp[i] = std::vector<int>(n, 0);
    }
    return aux_2(1, n);
}


int aux_1(int lo, int root, int hi) {
    int     num_left, num_right, sum;

    if (lo >= hi) {
        return 1;
    }

    num_left = aux_2(lo, root-1);
    num_right = aux_2(root+1, hi);

    if (num_left == 0 || num_right == 0) {
        sum = (num_left == 0) ? num_right : num_left;
    } else {
        sum = num_left * num_right;
    }

    return sum;
}

int aux_2(int lo, int hi) {
    int     sum;

    if (lo > hi) {
        return 0;
    }

    if (dp[lo-1][hi-1] != 0) {
        return dp[lo-1][hi-1];
    }

    sum = 0;
    for (int i = lo; i <= hi; i++) {
        sum += aux_1(lo, i, hi);
    }

    dp[lo-1][hi-1] = sum;

    return sum;
}


int
main(int arg, char **argv)
{
    int     n, sum;

    n = 18;
    sum = numTrees(n);
    printf("num = %d\n", sum);
}
