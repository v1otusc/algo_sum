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

struct Cmp {
  bool operator()(vector<int>& lhs, vector<int>& rhs) {
    if (lhs[0] == rhs[0]) {
      return lhs[1] < rhs[1];
    } else {
      return lhs[0] < rhs[0];
    }
  }
};

class Solution {
 public:
  int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int n = times.size();
    vector<vector<int>> sort_times = times;
    for (int i = 0; i < n; ++i) {
      sort_times[i].push_back(i);
    }
    sort(sort_times.begin(), sort_times.end(), Cmp());

    for (int i = 0; i < n; ++i) {
      
    }
  }
};

int main(int argc, char const* argv[]) { return 0; }
