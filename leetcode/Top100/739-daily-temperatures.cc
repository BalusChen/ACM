
/*
 * Copyright (C) Jianyong Chen
 */


#include <vector>
#include <stack>

class Solution {
    public:
        std::vector<int> dailyTemperatures(std::vector<int>& T) {
            int               i;
            std::stack<int>   stk;
            std::vector<int>  ret;

            ret.resize(T.size(), 0);
            for (i = 0; i < T.size(); i++) {
                while (!stk.empty() && T[i] > T[stk.top()]) {
                    ret[stk.top()] = i - stk.top();
                    stk.pop();
                }

                stk.push(i);
            }

            return ret;
        }
};
