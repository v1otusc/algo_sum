/*
 * @Description:
 *
 * 给定一个十进制整数，输出它在二进制下的翻转结果
 *
 * @输入示例：
 *
 * 43261596 (00000010100101000001111010011100)
 *
 * @输出实例：
 *
 * 964176192 (00111001011110000010100101000000)
 *
 * @输入输出说明：
 *
 * 输入和输出都是十进制整数
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 利用算数左移和右移
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for (int i = 0; i < 32; ++i) {
      // 当 ans = 0 时， a << 1 还是 0
      ans <<= 1;
      ans += n & 1;
      n >>= 1;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }