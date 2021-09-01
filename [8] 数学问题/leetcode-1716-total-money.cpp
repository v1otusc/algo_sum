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
  int totalMoney(int n) {
    int total, week, offset;
    for (int i = 0; i < n; ++i) {
      week = i / 7;
      offset = i % 7 + 1;
      total += week + offset;
    }
    return total;
  }
};

int main(int argc, char const* argv[]) { return 0; }
