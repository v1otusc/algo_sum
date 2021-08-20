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
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // vector<vector<int>> res;
    int n = intervals.size();
    if (n == 0 || n == 1) return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    for (int i = 0; i < n; ++i) {
      if (res.size() == 0 || res.back()[1] < intervals[i][0]) {
        res.push_back(intervals[i]);
      } else {
        res.back()[1] = max(res.back()[1], intervals[i][1]);
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }