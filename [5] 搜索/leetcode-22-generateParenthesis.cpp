/*
 * @Description:
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且
 * 有效的括号组合。
 *
 * @输入示例：
 *
 * 3
 *
 * @输出实例：
 *
 * ["((()))","(()())","(())()","()(())","()()()"]
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
  void backtrace(vector<string>& ans, string& cur, int l_num, int r_num,
                 int n) {
    if (cur.size() == 2 * n) {
      ans.push_back(cur);
      return;
    }
    if (l_num < n) {
      cur.push_back('(');
      backtrace(ans, cur, l_num + 1, r_num, n);
      cur.pop_back();
    }
    if (r_num < l_num) {
      cur.push_back(')');
      backtrace(ans, cur, l_num, r_num + 1, n);
      cur.pop_back();
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string cur{""};
    backtrace(ans, cur, 0, 0, n);
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
