/*
 * @Description:
 *
 * 输入一个字符串，打印出该字符串中字符的所有排列。
 * 可以任意顺序返回这个字符串数组，但里面不能有重复元素。
 *
 * @输入示例：
 *
 * s = "abc"
 *
 * @输出实例：
 *
 * ["abc", "acb", "bac", "cab", "cba"]
 *
 * @输入输出说明：
 *
 *  NULL
 *
 * @限制条件：
 *
 * 1 <= s的长度 <= 8
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
  vector<string> rec;
  vector<bool> vis;

  void backtrace(const string& str, int i, int n, string& tmp) {
    // 到达了终止条件
    if (i == n) {
      rec.push_back(tmp);
      return;
    }

    // for 选择 in 选择列表
    for (int j = 0; j < n; ++j) {
      // 将该选择从选择列表中移除
      // 保证重复字符只会被填入一次
      if (vis[j] || (j > 0 && str[j - 1] == str[j] && !vis[j - 1])) {
        continue;
      }

      vis[j] = true;
      tmp.push_back(str[j]);
      backtrace(str, i + 1, n, tmp);
      tmp.pop_back();
      vis[j] = false;
    }
  }

  vector<string> permutation(string s) {
    int n = s.size();
    vis.resize(n);
    string tmp{""};
    // 为了和保证重复字符只会被填入一次配合
    // 比较笨的方法是再进行去重
    sort(s.begin(), s.end());
    backtrace(s, 0, n, tmp);
    return rec;
  }
};

int main(int argc, char const* argv[]) {
  vector<string> res;
  string input{"aab"};
  Solution s;
  res = s.permutation(input);
  for (auto r : res) {
    cout << r << endl;
  }
  return 0;
}
