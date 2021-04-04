/*
 * @Description:
 *
 * 给定建筑物的起止位置和高度，返回建筑物轮廓(天际线，水平线的左端点)的拐点
 * 此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。
 *
 * @输入示例：
 *
 * [[2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8]]
 *
 * @输出实例：
 *
 * [[2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0]]
 *
 * @输入输出说明：
 *
 * 输入是一个二维整数数组,表示每个建筑物的 [左端, 右端,
 * 高度];输出是一个二维整数数组,表示每个拐点的横纵坐标
 * 列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0
 *
 * 注意：输出天际线中不得有连续的相同高度的水平线。
 *
 * @限制条件：
 *
 * NULL
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
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> ans;
    // pair<高度，右端 x 坐标>
    // 这里使用 pair，默认比较函数是先比较第一个值，如果相等再比较第二个值
    // 目的是，获取目前会拔高天际线，且妨碍到前一个建筑物(右端端点)的下一个建筑物
    priority_queue<pair<int, int>> max_heap;
    int i = 0;
    int len = buildings.size();
    // x 和 h 两个数值为返回的轮廓结果
    int cur_x = 0;
    int cur_h = 0;
    while (i < len || !max_heap.empty()) {
      // 此时，建筑物左端 < max_heap.top().second，说明被遮挡了
      if (max_heap.empty() ||
          (i < len && buildings[i][0] <= max_heap.top().second)) {
        cur_x = buildings[i][0];
        while (i < len && cur_x == buildings[i][0]) {
          max_heap.emplace(buildings[i][2], buildings[i][1]);
          ++i;
        }
      } else {
        // 此时，建筑物左端 >= max_heap.top().second 说明没有遮挡
        cur_x = max_heap.top().second;
        while (!max_heap.empty() && cur_x >= max_heap.top().second) {
          max_heap.pop();
        }
      }
      cur_h = (max_heap.empty()) ? 0 : max_heap.top().first;
      // 不能 push 进高度相同的拐点
      if (ans.empty() || cur_h != ans.back()[1]) {
        vector<int> tmp{cur_x, cur_h};
        ans.push_back(tmp);
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
