/*
 * @Description:
 *
 * 给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。
 * 请你返回让 s 成为回文串的 最少操作次数 。
 *
 * @输入示例：
 *
 * s = "mbadm"
 *
 * @输出实例：
 *
 * 2
 *
 * @输入输出说明：
 *
 * 字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
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
  int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 2; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1];
        } else {
          dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
      }
    }
    return dp[0][n - 1];
  }
};

int main(int argc, char const* argv[]) { return 0; }
