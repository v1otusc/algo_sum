/*
 * @Description:
 *
 * 给定一个字符串和一个正则表达式(regular expression, regex)
 ,求该字符串是否可以被匹配。
 *
 * @输入示例：
 *
 *  s = "aab", p = "c*a*b"
 *
 * @输出实例：
 *
 * true
 *
 * @输入输出说明：
 *
 输入是一个待匹配字符串和一个用字符串表示的正则表达式,输出是一个布尔值,表示是否
 可以匹配成功。
 在这个样例中，可以重复 c 零次，重复 a 两次
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 我们可以使用一个二维数组 dp,其中 dp[i][j] 表示以 i 截止的字符串是否可以被以 j
 截止的正则表达式匹配。根据正则表达式的不同情况，即字符、星号,点号,我们可以分情况讨论
 更新 dp 数组

 正则表达式规则：'.'匹配任意单个字符 '*'匹配零个或多个前面的那一个元素

 最困难的就是：
 字母 + 星号的组合在匹配的过程中，本质上只会有两种情况：

    匹配 s 末尾的一个字符，将该字符扔掉，而该组合还可以继续进行匹配；

    不匹配字符，将该组合扔掉，不再进行匹配。

  f[i][j]= f[i−1][j] or f[i][j−2] --​ s[i]=p[j−1]
         = f[i][j-2]  -- s[i]!=p[j−1]​
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 1;

    auto matches = [&](int i, int j) {
      if (i == 0) {
        return false;
      }
      if (p[j - 1] == '.') {
        return true;
      }
      return s[i - 1] == p[j - 1];
    };

    // i 从 0 开始
    // j 从 1 开始
    for (int i = 0; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] |= dp[i][j - 2];
          if (matches(i, j - 1)) {
            dp[i][j] |= dp[i - 1][j];
          }
        } else {
          if (matches(i, j)) {
            dp[i][j] |= dp[i - 1][j - 1];
          }
        }
      }
    }
    return dp[m][n];
  }
};

int main(int argc, char const* argv[]) { return 0; }
