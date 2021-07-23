/*
 * @Description:
 *
 * 正则表达式是否能匹配
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
  unordered_map<string, bool> memo;

 public:
  // 计算 s[i...] 是否能够匹配 p[j...]
  bool dp(string& s, int i, string& p, int j) {
    int m = s.size();
    int n = p.size();
    // 考虑 base case
    // 已经走完了
    if (j == n) {
      return i == m;
    }
    if (i == m) {
      if ((n - j) % 2 != 0) {
        return false;
      }
      for (; j + 1 < n; j += 2) {
        if (p[j + 1] != '*') {
          return false;
        }
      }
      return true;
    }

    // 记录状态(i,j)消除重叠子问题
    string key = to_string(i) + ',' + to_string(j);
    if (memo.count(key)) return memo[key];
    bool res = false;
    // 直接匹配
    if (s[i] == p[j] || p[j] == '.') {
      if (j < n - 1 && p[j + 1] == '*') {
        // 匹配 0 次或匹配多次
        res = dp(s, i, p, j + 2) || dp(s, i + 1, p, j);
      } else {
        res = dp(s, i + 1, p, j + 1);
      }
    } else {
      if (j < n - 1 && p[j + 1] == '*') {
        // 匹配 0 次
        res = dp(s, i, p, j + 2);
      } else {
        res = false;
      }
    }

    memo[key] = res;
    return res;
  }

  bool isMatch(string s, string p) { return dp(s, 0, p, 0); }
};

int main(int argc, char const* argv[]) {
  string s = "aab";
  string p = "c*a*b";
  Solution sol;
  bool res = sol.isMatch(s, p);
  if (res == true) {
    cout << "True" << endl;
  } else {
    cout << "False" << endl;
  }
  return 0;
}
