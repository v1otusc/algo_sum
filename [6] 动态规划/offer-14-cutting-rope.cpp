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
  int cuttingRope(int n) {
    // 长度的 i 的绳子，被减之后的最大乘积为 dp[i]
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    for (int i = 3; i < n + 1; ++i) {
      for (int j = 2; j < i; ++j) {
        // 先把绳子减去第一段，长度为 j, 剩下的可以减也可以不减
        dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
      }
    }
    return dp[n];
  }
};

int main(int argc, char const* argv[]) { return 0; }
