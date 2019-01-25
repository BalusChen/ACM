#include <iostream>

bool
Solve(int &W)
{
    int W1, D1, W2, D2;
    bool is_left_balanced = true, is_right_balanced = true;
    std::cin >> W1 >> D1 >> W2 >> D2;
    // weight为0则表示砝码其实是一个子天平
    if (W1 == 0) is_left_balanced = Solve(W1);
    if (W2 == 0) is_right_balanced = Solve(W2);
    // 子天平的和作为权重
    W = W1+W2;

    return is_left_balanced && is_right_balanced && (W1*D1 == W2*D2);
}
