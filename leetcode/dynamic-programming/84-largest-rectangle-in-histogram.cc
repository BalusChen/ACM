
/*
 * Copyright (C) Jianyong Chen
 */

#include <vector>
#include <stack>

class Solution
{
    public:
        int largestRectangleArea(std::vector<int> heights) {
            int              max, cur, top, i;
            std::stack<int>  stk;

            if (heights.empty()) {
                return 0;
            }

            max = heights[0];
            stk.push(0);
            i = 1;

            while (i < heights.size()) {

                if (stk.empty() || heights[i] >= heights[stk.top()]) {

                    /*
                     * 遇到更大的，就压栈
                     * 当然因为可能会 pop(只要 heights 不是全非降序)，所以可能会导致栈空
                     * 如果栈空，遇到的就压栈
                     */

                    stk.push(i);
                    i++;

                } else {

                    /*
                     * 如果遇到的比栈顶更小
                     */

                    top = heights[stk.top()];
                    stk.pop();
                    cur = stk.empty() ? top * i : top * (i - stk.top() - 1);
                    max = std::max(max, cur);
                }
            }

            /*
             * 处理完所有元素后栈仍不为空
             */

            while (!stk.empty()) {
                top = heights[stk.top()];
                stk.pop();
                cur = stk.empty() ? top * i : top * (i - stk.top() - 1);
                max = std::max(max, cur);
            }

            return max;
        }
};


int
main(int argc, char **argv)
{
    Solution          ans;
    std::vector<int>  heights;

    heights = { 2, 1, 5, 6, 2, 3 };
    printf("max: %d\n", ans.largestRectangleArea(heights));

    heights = { 1, 1 };
    printf("max: %d\n", ans.largestRectangleArea(heights));

    return 0;
}
