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
  int sumOddLengthSubarrays(vector<int>& arr) {
    int res = 0;
    for (int i = 0; i < arr.size(); ++i) {
      for (int sz = 1; i + sz - 1 < arr.size(); sz += 2) {
        res += accumulate(arr.begin() + i, arr.begin() + i + sz, 0);
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }