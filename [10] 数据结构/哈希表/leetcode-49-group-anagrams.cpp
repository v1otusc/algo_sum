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
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> ump;
    for (auto& str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      ump[key].push_back(str);
    }

    vector<vector<string>> ret;

    for (auto& m : ump) {
      ret.push_back(m.second);
    }
    return ret;
  }
};

int main(int argc, char const* argv[]) { return 0; }