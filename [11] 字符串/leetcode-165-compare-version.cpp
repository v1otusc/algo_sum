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
  int compareVersion(string version1, string version2) {
    int n = version1.length(), m = version2.length();
    int i = 0, j = 0;
    while (i < n || j < m) {
      int x = 0;
      for (; i < n && version1[i] != '.'; ++i) {
        x = x * 10 + version1[i] - '0';
      }
      ++i;  // 跳过点号
      int y = 0;
      for (; j < m && version2[j] != '.'; ++j) {
        y = y * 10 + version2[j] - '0';
      }
      ++j;  // 跳过点号
      if (x != y) {
        return x > y ? 1 : -1;
      }
    }
    return 0;
  }
};

int main(int argc, char const* argv[]) { return 0; }
