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
  int numPairsDivisibleBy60(vector<int>& time) {
    // 记录 time 中的值模 60 的次数
    vector<int> store(60, 0);
    for (int& t : time) store[t % 60]++;
    // 组合计算公式 c_n^2
    int res = (store[0] - 1) * store[0] / 2;
    for (int i = 0; i < time.size(); ++i) {
      store[time[i] % 60]--;
      if (time[i] % 60 != 0) {
        res += store[60 - time[i] % 60];
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
