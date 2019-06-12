
/*
 * Copyright (C) Jianyong Chen
 */

#include <cstdio>
#include <vector>
#include <cstdlib>


std::vector<int>  dp;


static int aux_1(int lo, int hi);
static int aux_2(int lo, int root, int hi);


static int
numTrees(int n) {
    dp.resize(n, 0);

    return aux_1(1, n);
}

static int
aux_1(int lo, int hi) {
    int  i, sum;

    if (lo > hi) {
        return 0;
    }

    // 由于 lo 和 hi 是从 1 开始的，所以从 dp 中取数据时要-1
    if (dp[hi-lo] != 0) {
        return dp[hi-lo];
    }

    sum = 0;
    for (i = lo; i <= hi; i++) {
        sum += aux_2(lo, i, hi);
    }

    dp[hi-lo] = sum;

    return sum;
}

static int
aux_2(int lo, int root, int hi) {
    int  num_left, num_right, sum;

    if (lo == hi) {
        return 1;
    }

    num_left = aux_1(lo, root-1);
    num_right = aux_1(root+1, hi);

    if (num_left == 0 || num_right == 0) {
        sum = (num_left == 0) ? num_right : num_left;

    } else {
        sum = num_left * num_right;
    }

    return sum;
}

int
main(int argc, char **argv)
{
    int  n, sum;

    if (argc != 2) {
        fprintf(stderr, "usage: %s n\n", argv[0]);
        exit(-1);
    }

    n = atoi(argv[1]);
    sum = numTrees(n);
    printf("num = %d\n", sum);

    for (auto c : dp) {
        printf("%d  ", c);
    }

    printf("\n");
    exit(0);
}
