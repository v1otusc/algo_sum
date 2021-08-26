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
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> m;
    for (auto& cpdomain : cpdomains) {
      int cur = 0;
      // 记录个数
      for (int i = 0; cpdomain[i] != ' '; ++i)
        cur = cur * 10 + (int)(cpdomain[i] - '0');

      int j = cpdomain.size() - 1;
      for (; cpdomain[j] != ' '; j--) {
        if (cpdomain[j] == '.') {
          // 参数为 pos
          m[cpdomain.substr(j + 1)] += cur;
        }
      }
      m[cpdomain.substr(j + 1)] += cur;
    }

    vector<string> res;
    for (auto& p : m) {
      res.push_back(to_string(p.second) + " " + p.first);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }