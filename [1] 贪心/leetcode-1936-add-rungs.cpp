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
  int addRungs(vector<int>& rungs, int dist) {
    // 需要添加台阶的数目
    int res = 0;
    // 当前的高度
    int cur = 0;
    for (int h : rungs) {
      int d = h - cur;
      // 向下取整
      res += (d - 1) / dist;
      cur = h;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
