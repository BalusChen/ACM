#include <vector>
#include <stdio.h>

class Solution
{
    template<typename T>
    using Matrix = std::vector<std::vector<T>>;

    public:
        int NumIslands(std::vector<std::vector<int>> &grid) {
            int           count;
            Matrix<bool>  visited;

            if (grid.empty()) {
                return 0;
            }

            count = 0;
            visited = Matrix<bool> (grid.size(), std::vector<bool>(grid[0].size(), false));

            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (grid[i][j] != 0 && !visited[i][j]) {
                        printf("i = %d\tj = %d\tcount = %d\n", i, j, count);    // debug
                        dfs(grid, visited, i, j);
                        count++;
                    }
                }
            }

            return count;
        }

        void dfs(Matrix<int> &grid, Matrix<bool> &visited, int i, int j) {
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
                // out of bound
                return;
            }

            if (grid[i][j] == 0) {
                // meet water
                return;
            }

            if (visited[i][j]) {
                // has already visited this grid
                return;
            }

            visited[i][j] = true;

            dfs(grid, visited, i-1, j);      // top
            dfs(grid, visited, i, j+1);      // right
            dfs(grid, visited, i+1, j);      // bottom
            dfs(grid, visited, i, j-1);      // left
        }
};

int
main(int argc, char **argv)
{
    Solution  solution;
    int       count;

    std::vector<std::vector<int>>  grid;

    grid = {
        { 1, 1, 1, 1, 0 },
        { 1, 1, 0, 1, 0 },
        { 1, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0 },
    };

    grid = {
        { 1, 1, 0, 0, 0 },
        { 1, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 1 },
    };

    count = solution.NumIslands(grid);

    printf("count: %d\n", count);
}
