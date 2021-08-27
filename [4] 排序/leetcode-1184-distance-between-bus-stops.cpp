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
  int distanceBetweenBusStops(vector<int>& distance, int start, int end) {
    int sa = 0, sb = 0;
    int n = distance.size();
    for (int i = 0; (start + i) % n != end; ++i)
      sa += distance[(start + i) % n];
    for (int i = 0; (end + i) % n != start; ++i) {
      sb += distance[(end + i) % n];
    }
    int res = min(sa, sb);
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
