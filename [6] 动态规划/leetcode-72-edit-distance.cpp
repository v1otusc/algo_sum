/*
 * @Description:
 *
 给定两个字符串，已知可以删除、替换和插入任何字符串的任意字符，求最少编辑几步可以将两个字符串变成相同
 *
 * @输入示例：
 *
 * word1 = "horse", word2 = "ros"
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 在这个样例中，一种最优的编辑方法是
 * horse -> rorse
 * rorse->rose
 * rose->ros
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 类似于题目 1143,我们使用一个二维数组 dp[i][j],表示将第一个字符串到位置 i
 为止,和第二个字符串到位置 j 为止,最多需要几步编辑。当第 i 位和第 j
 位对应的字符相同时,dp[i][j] 等于
 dp[i-1][j-1];当二者对应的字符不同时,**修改**的消耗是 dp[i-1][j-1]+1,插入 i
 位置/删除 j 位置的 dp[i][j-1] + 1，插入 j/删除 i 位置的消耗是 dp[i-1][j] + 1
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        if (i == 0) {
          dp[i][j] = j;
        } else if (j == 0) {
          dp[i][j] = i;
        } else {
          dp[i][j] =
              min(dp[i - 1][j - 1] + ((word1[i - 1] == word2[j - 1]) ? 0 : 1),
                  min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        }
      }
    }
    return dp[m][n];
  }
};

int main(int argc, char const* argv[]) { return 0; }