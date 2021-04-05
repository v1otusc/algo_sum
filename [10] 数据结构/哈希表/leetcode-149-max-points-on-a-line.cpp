/*
 * @Description:
 *
 * 给定一些二维坐标中的点，求同一条线上最多有多少点
 *
 * @输入示例：
 *
 * [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 *
 * @输出实例：
 *
 * 4
 *
 * @输入输出说明：
 *
 * y = 5 − x 上有四个点。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 对于每个点，我们对其他点建立哈希表，统计同一斜率的点一共有多少个。
 *
 * 利用一条线可以由一个点和斜率唯一确定，另外也要考虑斜率不存在和重复坐标的情况
 * 利用了一个小技巧：在遍历每个点时，对于数组中位置 i 的点，我们只需要考虑 i
 * 之后的点，因为 i 之前的点已经考虑过 i 了
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
    // <斜率，点个数>
    unordered_map<double, int> hash;
    int max_count = 0;
    int same_x = 1;
    int same = 1;
    for (int i = 0; i < points.size(); ++i) {
      same_x = 1;
      same = 1;
      for (int j = i + 1; j < points.size(); ++j) {
        // 考虑特殊情况，x 坐标相同。此时斜率为无限大
        if (points[i][0] == points[j][0]) {
          same_x++;
          if (points[i][1] == points[j][1]) {
            same++;
          }
        } else {
          double dx = points[i][0] - points[j][0];
          double dy = points[i][1] - points[j][1];
          ++hash[dy / dx];
        }
      }
      // 斜率无限大的直线上
      max_count = max(max_count, same_x);
      for (auto& item : hash) {
        max_count = max(max_count, same + item.second);
      }
      hash.clear();
    }
    return max_count;
  }
};

int main(int argc, char const* argv[]) { return 0; }
