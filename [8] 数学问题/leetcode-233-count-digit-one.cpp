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
 * 枚举某位中 1 出现的次数
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int countDigitOne(int n) {
    // 最后的结果可能会超，因为还要 x 10
    long long digit = 1;
    int res = 0;
    // 位次
    int high = n / 10, cur = n % 10, low = 0;
    while (high != 0 || cur != 0) {
      if (cur == 0)
        res += high * digit;
      else if (cur == 1)
        res += high * digit + low + 1;
      else
        res += (high + 1) * digit;
      low += cur * digit;
      cur = high % 10;
      high /= 10;
      digit *= 10;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
