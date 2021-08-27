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
 * len_n = 2^n - 1
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  char findKthBit(int n, int k) {
    if (k == 1) return '0';
    int mid = 1 << (n - 1);
    // 正好处于中间
    if (k == mid) return '1';
    // 在字符串 Sn-1 中
    if (k < mid) {
      return findKthBit(n - 1, k);
    } else {
      // 在字符串 Sn 的后半段
      // k = 2^n - k;
      k = mid * 2 - k;
      return invert(findKthBit(n - 1, k));
    }
  }

  char invert(char bit) {
    // 如果是 '1' 变为 '0'，反之亦然
    return (char)('0' + '1' - bit);
  }
};

int main(int argc, char const* argv[]) { return 0; }
