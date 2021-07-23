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
 * 暴力法，偏向于贪心
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    sort(ranges.begin(), ranges.end());
    for (auto range : ranges) {
      // [left] 到 range[1] 之间的都是可以匹配的
      if (range[0] <= left && range[1] >= left) left = range[1] + 1;
    }
    return right < left;
  }
};

int main(int argc, char const* argv[]) { return 0; }
