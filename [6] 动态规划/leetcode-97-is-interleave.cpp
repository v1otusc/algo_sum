/*
 * @Description:
 *
 * 字符串是否交错
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
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size(), t = s3.size();
    if (m + n != t) return false;

    vector<vector<int>> dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

    dp[0][0] = true;
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        int p = i + j - 1;
        if (i > 0) {
          dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[p]);
        }
        if (j > 0) {
          dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[p]);
        }
      }
    }
    return dp[m][n];
  }
};

int main(int argc, char const* argv[]) { return 0; }
