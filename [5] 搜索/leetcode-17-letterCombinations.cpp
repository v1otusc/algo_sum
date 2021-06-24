/*
 * @Description:
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按
 * 任意顺序返回。
 *
 * @输入示例：
 *
 * digits = "23"
 *
 * @输出实例：
 *
 * ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
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
  unordered_map<int, vector<char>> mp = {
      {2, vector<char>{'a', 'b', 'c'}}, {3, vector<char>{'d', 'e', 'f'}},
      {4, vector<char>{'g', 'h', 'i'}}, {5, vector<char>{'j', 'k', 'l'}},
      {6, vector<char>{'m', 'n', 'o'}}, {7, vector<char>{'p', 'q', 'r', 's'}},
      {8, vector<char>{'t', 'u', 'v'}}, {9, vector<char>{'w', 'x', 'y', 'z'}}};

  void backtrace(const string& digits, vector<string>& ans, string& s,
                 int index) {
    if (s.size() == digits.size()) {
      ans.push_back(s);
      return;
    } else {
      char c_digit = digits[index];
      int digit = c_digit - '0';
      const vector<char> char_vec = mp[digit];
      for (auto c : char_vec) {
        s.push_back(c);
        backtrace(digits, ans, s, index + 1);
        s.pop_back();
      }
    }
  }
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.empty()) {
      return ans;
    }
    string s;
    backtrace(digits, ans, s, 0);
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
