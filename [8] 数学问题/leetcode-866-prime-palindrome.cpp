/*
 * @Description:
 *
 *
 *
 * @输入示例：
 *
 *
 *
 * @输出实例：
 *
 *
 *
 * @输入输出说明：
 *
 *
 *
 * @限制条件：
 *
 *
 *
 * @题目思路：
 *
 * 使用回文根来构造回文数
 * 例如回文根为 12 可以构造出两种 1221 和 12x21 x 属于 [0, 9]
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
  // 不超过 10^8
  const int f[10] = {1,      10,      100,      1000,     10000,
                     100000, 1000000, 10000000, 100000000};

 public:
  bool is_prime(int n) {
    int i = sqrt(n);
    if (i * i == n) return false;
    for (int j = 2; j <= i; ++j) {
      if (n % j == 0) return false;
    }
    return true;
  }

  // 得到以 n 为回文根(左边)的回文素数
  int get_pre_n(int n, bool odd, int x) {
    int len = 0;
    int t = n;
    // 右边的 n
    int rn = 0;
    while (t) {
      rn = rn * 10 + t % 10;
      t /= 10;
      len++;
    }
    // 如果回文素数位数为奇数
    if (odd) {
      return rn + n * f[len + 1] + x * f[len];
    }

    // 如果回文素数位数为偶数
    return rn + n * f[len];
  }

  int primePalindrome(int n) {
    // 找有没有小于 11 的
    if (n <= 10) {
      for (int i = n; n < 12; ++i) {
        if (is_prime(i)) return i;
      }
    }

    // 11 22 33 44 55 66 77 88 99 
    // 二位数字只有只有 11 有机会

    for (int i = 1;; ++i) {
      int t = get_pre_n(i, false, 0);
      // 先求偶数位数
      if (t >= n && is_prime(t)) return t;
      for (int j = 0; j <= 9; ++j) {
        t = get_pre_n(i, true, j);
        if (t >= n && is_prime(t)) return t;
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) { return 0; }
