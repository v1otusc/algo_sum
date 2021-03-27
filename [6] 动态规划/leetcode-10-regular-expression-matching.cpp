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

 正则表达式规则：
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i) {
      
    }
    return dp[m][n];
  }
};

int main(int argc, char const* argv[]) { return 0; }
