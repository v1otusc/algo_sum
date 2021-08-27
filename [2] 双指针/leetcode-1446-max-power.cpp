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
  int maxPower(string s) {
    int n = s.size();
    if (n <= 1) return n;
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int j = i;
      while (j < n && s[j] == s[i]) j++;
      res = max(res, j - i);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }