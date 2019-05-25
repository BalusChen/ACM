
/*
 * Copyright (C) Jianyong Chen
 */

#include <vector>
#include <cstdio>
#include <random>


using Triangle = std::vector<std::vector<int>>;

static void best_path(Triangle &triangle);
static Triangle get_triangle(int nline);


int
main(int argc, char **argv)
{
    int       nline;
    Triangle  triangle;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <#line>\n", argv[0]);
        exit(-1);
    }

    nline = std::atoi(argv[1]);
    triangle = get_triangle(nline);

    Triangle triangle2 = {
        { 22 },
        { 14, 19 },
        { 30, 25, 10 },
        { 8, 20, 12, 27 },
        { 6, 25, 32, 6, 4 },
        { 6, 10, 10, 6, 2, 32 },
        { 32, 29, 2, 13, 15, 3, 24 }
    };

    best_path(triangle2);
    best_path(triangle);

    return 0;
}


static Triangle
get_triangle(int nline)
{
    int                              i, j;
    std::random_device               rd;
    std::mt19937                     gen(rd());
    std::vector<std::vector<int>>    triangle;
    std::uniform_int_distribution<>  dis(1, 51);

    for (i = 0; i < nline; i++) {

        triangle.push_back(std::vector<int>());

        for (j = 0; j <= i; j++) {
            triangle[i].push_back(dis(gen));
        }
    }

    for (auto &line : triangle) {
        for (auto c : line) {
            printf("%-3d", c);
        }
        printf("\n");
    }

    return triangle;
}

static void
best_path(Triangle &triangle)
{
    int   nline = triangle.size();
    char  dir[nline][nline];
    int   sum[nline][nline];
    int   i, j;

    // 设置边界条件
    for (j = 0; j < nline; j++) {
        sum[nline-1][j] = triangle[nline-1][j];
    }

    // 动态规划
    for (i = nline-2; i >= 0; i--) {

        for (j = 0; j <= i; j++) {
            if (sum[i+1][j] < sum[i+1][j+1]) {
                sum[i][j] = sum[i+1][j] + triangle[i][j];
                dir[i][j] = 'L';

            } else {
                sum[i][j] = sum[i+1][j+1] + triangle[i][j];
                dir[i][j] = 'R';
            }
        }
    }

    printf("minimum path sum: %d\n", sum[0][0]);
    printf("minimum path: ");
    printf("%d", triangle[0][0]);

    for (i = 1, j = 0; i < nline; i++) {
        if (dir[i-1][j] == 'R') {
            printf("-R-%d", triangle[i][j+1]);
            j++;

        } else {
            printf("-L-%d", triangle[i][j]);
        }
    }

    printf("\n");
}
