/*
 * @Description:
 *
 * 分割平衡字符串
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
  int balancedStringSplit(string str) {
    int cntl = 0, cntr = 0;
    int ans = 0;
    for (auto& s : str) {
      if (s == 'R') {
        cntr++;
      } else {
        cntl++;
      }
      if (cntr == cntl) ans++;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }