/*
 * @Description:
 *
 * 给一个字符串 s，找到 s 中最长的回文子串
 *
 * @输入示例：
 *
 * s = "babad"
 *
 * @输出实例：
 *
 * "aba" 或者 “bab”
 *
 * @输入输出说明：
 *
 * NULL
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 用 P(i,j) 表示字符串 s 的第 i 到 j 个字母组成的串（下文表示成
 * s[i:j]）是否为回文串，那么动态规划的状态转移方程可以写为
 *
 * P(i,j)=P(i+1,j−1)∧(Si​==Sj​)
 *
 * 也就是说,只有 s[i+1:j-1] 是回文串,并且 s 的第 i 和 j
 * 个字母相同时,s[i:j] 才会是回文串
 *
 * 上面的所有讨论是建立在子串长度大于 2
 * 的前提之上的，我们还需要考虑动态规划中的边界条件，即子串的长度为 1 或
 * 2。对于长度为 1 的子串，它显然是个回文串；对于长度为 2
 * 的子串，只要它的两个字母相同，它就是一个回文串。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    if (n == 1) return s;

    int max_len = 1;
    int begin = 0;

    // 用一个 0-1 的二维矩阵来表示 s[i:j] 是否为回文串, 初始化元素均为 0
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // 边界条件，长度为 1 的子串一定是回文串
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }

    // 枚举所有子串可能长度
    for (int L = 2; L <= n; L++) {
      // 枚举左边界，左边界的上限设置可以宽松一些
      for (int i = 0; i < n; i++) {
        // 由 L 和 i 可以确定右边界，即 j - i + 1 = L 得
        int j = L + i - 1;
        // 如果右边界越界，就可以退出当前循环
        if (j >= n) {
          break;
        }

        if (s[i] != s[j]) {
          dp[i][j] = 0;
        } else {
          // 对于长度为 2 的子串，两个元素相同就是回文串
          if (j - i < 3) {
            dp[i][j] = 1;
          } else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }

        // 只要 dp[i][L] == true 成立，就表示子串 s[i..L]
        // 是回文，此时记录回文长度和起始位置
        if (dp[i][j] && j - i + 1 > max_len) {
          max_len = j - i + 1;
          begin = i;
        }
      }
    }
    return s.substr(begin, max_len);
  }
};

int main(int argc, char const* argv[]) {
  cout << "" << endl;
  return 0;
}