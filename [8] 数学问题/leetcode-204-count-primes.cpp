/*
 * @Description:
 *
 * 给定一个数字 n,求小于 n 的质数的个数。
 *
 * @输入示例：
 *
 * 10
 *
 * @输出实例：
 *
 * 4
 *
 * @输入输出说明：
 *
 * 输入一个整数,输出也是一个整数,表示小于输入数的质数的个数。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 使用埃氏筛法
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> primes(n, true);
    // 去掉不是质数的 1 和 n(因为范围为小于 n)
    int count = n - 2;
    for (int i = 2; i < n; ++i) {
      if (primes[i]) {
        for (int j = 2 * i; j < n; j += i) {
          if (primes[j]) {
            primes[j] = false;
            count--;
          }
        }
      }
    }
    return count;
  }
};

int main(int argc, char const* argv[]) { return 0; }
