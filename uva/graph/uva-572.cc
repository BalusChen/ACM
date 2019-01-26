#include <cstdio>
#include <cstring>

const int maxn = 100+5;
char pic[maxn][maxn];
int row, col, idx[maxn][maxn];

void
DFS(int r, int c, int id)
{
    // 格子越界
    if (r < 0 || r > row || c < 0 || c > col)
        return;
    // 不是@或者已经访问过的格子
    if (idx[r][c] != 0 || pic[r][c] != '@')
        return;
    // 记录连通分量号
    idx[r][c] = id;

    // 访问周边的格子
    // 这里是使用一个二重循环访问周边的8个格子
    // 也可以使用8条DFS调用语句
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if (!(dr == 0 && dc == 0)) DFS(r+dr, c+dc, id);
}

int
main(int argc, char **argv)
{
    // 读取行、列数
    if (scanf("%d%d", &row, &col) != 2) {
        perror("incorrect number of input");
        return 1;
    }
    // 检查输入是否正确
    if (row == 0 || col == 0) {
        perror("incorrect input");
        return 1;
    }

    // 读取图的每个节点
    for (int r = 0; r < row; r++)
        scanf("%s", pic[r]);

#ifdef DEBUG    // for debug
    printf("row = %d, col = %d\n", row, col);
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            printf("%c", pic[r][c]);
        }
        printf("\n");
    }
#endif

    // 将连通分量号数组置0
    memset(idx, 0, sizeof(idx));
    // 每个连通分量都有一个连通分量号
    // 这是通过count来赋予的
    int count = 0;
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            if (idx[r][c] == 0 && pic[r][c] == '@')
                DFS(r, c, ++count);
        }
    }
    printf("count: %d\n", count);

#ifdef DEBUG    // for debug
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            printf("%d", idx[r][c]);
        }
        printf("\n");
    }
#endif

    return 0;
}
