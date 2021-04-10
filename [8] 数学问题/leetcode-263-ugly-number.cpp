/*
 * @Description:
 *
 * 给你一个整数 n，判断 n 是否为丑数
 * 如果是，返回 true；否则，返回 false
 *
 * 丑数就是只包含质因数 2，3，5 的正整数
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-04-10 17:22:18
 * @FilePath: /algo_sum/[8] 数学问题/leetcode-263-ugly-number.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool isUgly(int n) {
    if (n == 1 || n == 2 || n == 3 || n == 5) {
      return true;
    }
    if (n <= 0) {
      return false;
    }

    vector<int> factors{5, 3, 2};
    for (int factor : factors) {
      while (n % factor == 0) {
        n /= factor;
      }
    }
    return n == 1;
  }
};

int main(int argc, char const* argv[]) { return 0; }
