/*
 * @Description:
 *
 * 动态规划中分割类型的题目
 * 给定一个正整数，求其最少可以由几个完全平方数相加构成
 *
 * @输入示例：
 *
 * n = 13
 * n = 12
 *
 * @输出实例：
 *
 * 2
 * 3
 *
 * @输入输出说明：
 *
 * 13 = 4 + 9
 * 12 = 4 + 4 + 4
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 对于分割类的题目，动态规划的状态转移方程通常并不依赖相邻的位置，而是依赖于满足分割条件的位置
 我们定义一个一维矩阵 dp,其中 dp[i] 表示数字 i 最少可以由几个完全平方数相加构成
 在本题中，位置 i 只依赖 i - k^2 的位置，,如 i - 1、i - 4、i - 9
 等等,才能满足完全平方分割的条件，因此 dp[i] 可以取得的最小值即为  1 +
 min(dp[i-1], dp[i-4], dp[i-9] · · · )。
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
  static int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};

int main(int argc, char const* argv[]) { return 0; }
