/*
 * @Description:
 *
 *
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
 * 模拟
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  string boldWords(vector<string>& dict, string s) {
    int n = s.size();
    if (n == 0) return "";
    // 匹配的位置置为 true，未匹配的
    vector<bool> mask(n, false);

    for (int i = 0; i < n; ++i) {
      for (auto& word : dict) {
        int len = word.size();
        // 直接暴力匹配
        if (i + len <= n && s.substr(i, len) == word) {
          for (int j = i; j < i + len; ++j) {
            mask[j] = true;
          }
        }
      }
    }

    string res = "";
    for (int i = 0; i < n; ++i) {
      // 标签的开头
      if (mask[i] && (i == 0 || (i > 0 && mask[i - 1] == false))) {
        res += "<b>";
      }

      res.push_back(s[i]);

      // 标签的结尾
      if (mask[i] && (i == n - 1 || (i < n - 1 && mask[i + 1] == false))) {
        res += "</b>";
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }