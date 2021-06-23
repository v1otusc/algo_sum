/*
 * @Description:
 *
 * 请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1
 * 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入
 * 9，则该函数输出 2
 *
 * @输入示例：
 *
 * 00000000000000000000000000001011
 *
 * @输出实例：
 *
 * 3
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
 *
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int low_bit(uint32_t n) { return n & -n; }

  int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
      n -= low_bit(n);
      ans++;
    }
    return ans;
  }
};

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n) {
      n &= n - 1;
      ret++;
    }
    return ret;
  }
};

int main(int argc, char const* argv[]) { return 0; }
