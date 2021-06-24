/*
 * @Description:
 *
 * 给你一个数组 points, 其中 points[i] = [x_i, y_i] 表示 X-Y 平面上的一个点
 * 求最多有多少个点在同一条直线上
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
  int maxPoints(vector<vector<int>>& points) {
    int len = points.size();
    // 点的数量不够
    if (len < 3) {
      return len;
    }
    int maxNum = 2;
    // 遍历每两个点
    for (int i = 0; i < len; i++) {
      // 注意此时 count 出现的位置
      unordered_map<double, int> count;
      for (int j = 0; j < len; j++) {
        if (i != j) {
          long long dx = points[i][0] - points[j][0];
          long long dy = points[i][1] - points[j][1];
          double gradient = 0.0;
          if (dx == 0) {
            gradient = DBL_MAX;
          } else if (dy == 0) {
            gradient = 0.0;
          } else {
            gradient = dy * 1.0 / dx;
          }
          if (count.count(gradient)) {
            count[gradient]++;
          } else {
            count[gradient] = 2;
          }
          // 因为已经初始化过了 count[gradient] = 2
          maxNum = max(maxNum, count[gradient]);
        }
      }
    }
    return maxNum;
  }
};

int main(int argc, char const* argv[]) { return 0; }
