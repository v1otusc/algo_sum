/*
 * @Description:
 *
 给定一个字符串和一个字符串集合，求是否存在一种分割方式，使得原字符串分割后的子字符串
 都可以在集合内找到
 *
 * @输入示例：
 *
 * s = "applepenapple"
 * wordList = ["apple", "pen"]
 *
 * @输出实例：
 *
 * true
 *
 * @输入输出说明：
 *
 * 在这个样例中，字符串可以被分割为 [“apple”,“pen”,“apple”]。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 这道题的分割条件由集合内的字符串决定，因此在考虑每个分割位置时，需要遍历字符串集合
 以确定当前位置是否可以成功分割。
 *
 * 注意对于位置 0，需要初始化值为真
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static bool wordBreak(string s, vector<string>& wordList) {
    // length() 和 size() 没什么区别
    int n = s.length();
    vector<bool> dp(n + 1, false);
    // 注意对于位置 0，需要初始化值为真
    dp[0] = true;
    for (int i = 1; i <= n; ++i) {
      for (auto& word : wordList) {
        int len = word.length();
        if (i >= len && s.substr(i - len, len) == word) {
          dp[i] = dp[i] || dp[i - len];
        }
      }
    }
    return dp[n];
  }
};

int main(int argc, char const* argv[]) { return 0; }
