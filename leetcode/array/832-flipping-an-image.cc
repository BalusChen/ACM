#include <vector>

class Solution {
    public:
        std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>> &A) {
            int rows = A.size();
            int begin, end;
            for (int i = 0; i < rows; i++) {
                begin = 0; end = A[i].size()-1;
                while (begin < end) {
                    // 如果不相等则经过reverse和invert两步不会变
                    // 相等则将其取反
                    if (A[i][begin] == A[i][end]) {
                        A[i][begin] = !A[i][begin];
                        A[i][end]   = !A[i][end];
                    }
                    ++begin;
                    --end;
                }
                if (begin == end)
                    A[i][begin] = !A[i][end];
            }

            return A;
        }

};
