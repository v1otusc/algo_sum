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
 * 定义 dp[i][j][k] 表示前 i 天有 j 个 'A' 且结尾有连续 k 个 'L'
 * 的可奖励的出勤记录，那么
 *
 * 0 <= i <= n, 0<=j<=1, 0<=k<=2
 *
 * 当 i = 0 时(没有出勤记录)，dp[0][0][0] = 1
 *
 * 当 0 < i <= n 时，dp[i][][] 的值从 dp[i-1][][] 的值转移得到
 *
 * 然后再分析结尾是 P A L 的情况
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
  const int mod = 1000000007;

 public:
  int checkRecord(int n) {
    // 长度，A 的数量，结尾连续 L 的数量
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(2, vector<int>(3)));
    // 没有出勤记录也可以获得奖励
    dp[0][0][0] = 1;

    // 如果 i 以 P 结尾
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= 1; ++j) {
        for (int k = 0; k <= 2; ++k) {
          // A 的数量不变，结尾连续 L 的数量清零
          dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % mod;
        }
      }

      // 如果以 A 结尾
      for (int k = 0; k <= 2; ++k) {
        dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % mod;
      }

      // 如果以 L 结尾
      for (int j = 0; j <= 1; ++j) {
        for (int k = 1; k <= 2; ++k) {
          dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % mod;
        }
      }
    }

    int sum = 0;
    for (int j = 0; j <= 1; ++j) {
      for (int k = 0; k <= 2; ++k) {
        sum = (sum + dp[n][j][k]) % mod;
      }
    }
    return sum;
  }
};

int main(int argc, char const* argv[]) { return 0; }
