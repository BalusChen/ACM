
/*
 * Copyright (C) Jianyong chen
 */

#include <vector>
#include <utility>
#include <iostream>
#include <cmath>


/*
 * 定义 m 位超级素数：
 *      1. m 位超级素数本身为素数
 *      2. 从高位开始，去掉 1 位后为 m-1 位素数；去掉 2 位后为 m-2 位素数......；去掉 m-1 位后为 1 位素数
 *
 *  问题：输入整数 m(1 < m <= 10)，统计 m 位超级素数的个数，并输出其中最大的 m 位超级素数
 */

static bool IsPrime(long x);
static std::pair<int, long> LargestPrime(int m);
static std::pair<int, long> LargestPrime2(int m);


int
main(int argc, char **argv)
{
    int                  m;
    std::pair<int, int>  results;

    std::cout << "Please input m: ";
    std::cin >> m;

    results = LargestPrime2(m);

    std::cout << "#super primes of length " << m  << ": " <<
        results.first << std::endl;
    std::cout << "largest super prime: " << results.second << std::endl;

    return 0;
}

/*
 * 采用枚举
 * 很慢很慢
 */
static std::pair<int, long>
LargestPrime(int m)
{
    bool                  is_prime;
    long                  start, end, x, i, k, t;
    std::pair<int, long>  results;

    start = std::pow(10, m-1) + 1;
    end = (start - 1) * 10 - 1;

    printf("start: %ld\tend: %ld\n", start, end);

    results.first = 0;
    results.second = 0;

    for (x = start; x < end; x += 2) {

        /*
         * 超级素数的个位数字必须为 3 或者 7 (注意 m > 1)
         * 不能为 1，因为去掉所有最高位后 1 不是素数
         */

        if (!IsPrime(x) || !(x % 10 == 3 || x % 10 == 7)) {
            continue;
        }

        // 枚举 m-2 次中间的数字
        // 中间的数字不能为 0，因为最高位肯定不为 0，所以是枚举 m-2 次
        for (is_prime = true, t = x / 10, i = 1; is_prime && i <= m-2; i++) {

            // 中间数字不能出现 0
            if (t % 10 == 0) {
                is_prime = false;
            }

            t = t / 10;
        }

        if (!is_prime) {
            continue;
        }

        // 枚举 m-2 次丢弃最高位的操作
        for (is_prime = true, k = 10, i = 1; is_prime && i <= m - 2; i++) {
            k = k * 10;
            is_prime = is_prime && IsPrime(x % k);
        }

        if (!is_prime) {
            continue;
        }

        results.first++;
        results.second = x;
    }

    return results;
}


/*
 * 采用递推方法
 * 比前面的枚举方法快很多很多
 */
static std::pair<int, long>
LargestPrime2(int m)
{
    long                  i, j, k, x, t, base, start, size;
    std::vector<long>     primes;
    std::pair<int, long>  results;

    primes = std::vector<long> {3, 7};
    results.first = 0;
    base = 1;

    /*
     * 每一轮产生的素数我都放在 primes 这个数组中
     * 产生素数的方法是是通过第 n 轮的素数来推出第 n+1 轮的素数
     * 所以必须知道这一轮的素数是哪些
     * 用 start 表示第 n 轮素数开始的下标，size 表示其结束的下标的后一个位置
     *
     * 最开始只有 3 和 7 这两个素数
     */

    start = 0;
    size = primes.size();

    /*
     * 从 3，7 开始，让他们作个位数字
     *
     * 13, 17; 23, 27; ... 93, 97
     * 113, 117 123, 127,... 193, 197; 213, 217, ... ,293, 297; ...... ; 913, 917 ... , 993, 997
     */
    for (k = 2; k <= m; k++) {
        base = base * 10;
        t = 0;

        for (i = 1; i <= 9; i++) {

            for (j = start; j < size; j++) {

                x = base * i + primes[j];

                if (IsPrime(x)) {

                    if (k == m) {
                        results.first++;
                        results.second = x;

                    } else {

                        // 小于 m 位的素数得记下来
                        // 留作后面增加一位后再次检测是否为素数，直到增大到 m 位
                        primes.push_back(x);
                    }
                }
            }
        }

        start = size;
        size = primes.size();
    }

    return results;
}


static bool
IsPrime(long x)
{
    int  sqrt_x, i;

    if (x == 1) {
        return false;

    } else if (x == 2) {
        return true;
    }

    sqrt_x = std::sqrt(x) + 1;

    for (i = 3; i <= sqrt_x; i += 2) {

        if (x % i == 0) {
            return false;
        }
    }

    return true;
}
