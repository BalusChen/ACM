#include <vector>

class Solution {
    public:
        bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
            int  out_lo, out_hi, out_mid, in_lo, in_hi, in_mid;
            int  val;

            out_lo = 0;
            out_hi = matrix.size() - 1;

            while (out_lo <= out_hi) {
                out_mid = out_lo + (out_hi - out_lo) / 2;
                in_lo = 0;
                in_hi = matrix[out_mid].size() - 1;

                while (in_lo <= in_hi) {
                    in_mid = in_lo + (in_hi - in_lo) / 2;
                    val = matrix[out_mid][in_mid];

                    if (val < target) {
                        in_lo = in_mid + 1;

                    } else if (val > target) {
                        in_hi = in_mid - 1;

                    } else {
                        return true;

                    }
                }

                if (in_hi < 0) {
                    out_hi = out_mid - 1;
                } else if (in_lo >= matrix[out_mid].size()) {
                    out_lo = out_mid + 1;
                } else {
                    return false;
                }
            }

            return false;
        }
};
