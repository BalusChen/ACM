
/*
 * Copyright (C) Jianyong Chen
 */

#include <cstdio>
#include <queue>

class Solution
{
    public:
        void solve() {
            int  i, j, round_nelts, res, res_1, round;

            std::vector<int>              num, new_num;
            std::queue<std::vector<int>>  que;

            for (i = 1; i <= 9; i++) {
                que.push(std::vector<int>(1, i));
            }

            round = 2;
            for ( ;; ) {

                round_nelts = que.size();
                printf("# %dth round: %d\n", round, round_nelts);

                /*
                 * 对上一轮每个 round-位整除数，尝试在后面添加一个数字
                 * 看它是否满足 round+1 位整除数的要求
                 */

                for (i = 0; i < round_nelts; i++) {
                    num = que.front();
                    que.pop();


                    res = 0;
                    for (auto digit : num) {
                        res = res * 10 + digit;
                        res %= round;
                    }

                    for (j = 0; j <= 9; j++) {

                        // 添加 1 位
                        res_1 = res * 10 + j;
                        if (res_1 % round == 0) {
                            new_num = num;
                            new_num.push_back(j);
                            que.push(new_num);
                        }
                    }
                }

                /*
                 * 最大的 n 位整除数就到 25 位就停了
                 * 所以上面这个 for 循环在 26 开始就找不到任何可行的添加了
                 */
                if (que.empty()) {
                    printf("no viable number since the %dth epoch\n", round);
                    break;
                }

                // printf("# %d-digits: %ld\n", round, que.size());
                round++;
            }
        }
};


int
main(int argc, char **argv)
{
    Solution  ans;

    ans.solve();

    return 0;
}
