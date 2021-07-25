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
  bool areOccurrencesEqual(string s) {
    if (s.size() == 0 || s.size() == 0) return true;
    unordered_map<char, int> ump;
    for (auto& c : s) {
      ump[c]++;
    }
    int count = ump[s[0]];
    for (auto& p : ump) {
      if (p.second != count) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }
