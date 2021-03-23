/*
 * @Description:
 *
 * 给定两个字符串，求他们最长的公共子序列
 *
 * @输入示例：
 *
 * text1 = "abcde"
 * text2 = "ace"
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 在这个样例中，最长公共子序列为 "ace"
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 对于子序列问题,第二种(第一种为题目 300)动态规划方法是,定义一个 dp 数组,其中
 dp[i] 表示到位置 i 为止的子序列的性质,并不必须以 i 结尾。这样 dp
 数组的最后一位结果即为题目所求,不需要再对每个位置进行统计。

 在本题中，我们可以建立一个二维数组 dp,其中 dp[i][j] 表示到第一个字符串位置 i
 为止，到第二个字符串位置 j
 为止，最长的公共子序列长度。这样一来我们就可以很方便地分情况讨论这两个位置对应的字母
 相同与不同的情况了。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    return dp[m][n];
  }
};

int main(int argc, char const* argv[]) { return 0; }