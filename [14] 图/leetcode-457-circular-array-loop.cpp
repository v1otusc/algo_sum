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
  // 邻接表存的图
  vector<vector<int>> graph;
  // 入度数组
  vector<int> Indeg;

 public:
  // 拓扑排序
  bool topo_sort(int n) {
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (!Indeg[i]) q.push(i);
    }

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (auto& end_ : graph[cur]) {
        int end = end_;
        Indeg[end]--;
        if (!Indeg[end]) q.push(end);
      }
    }

    // 仍然有入度不为 0 的点，说明图中有环
    for (auto& ind : Indeg) {
      if (ind) return true;
    }
    return false;
  }

  bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    graph.resize(n);
    Indeg.resize(n);

    // 先处理正向边 num[i] > 0 的情况
    for (int i = 0; i < n; ++i) {
      // 处理环形的情况
      // 图中是下标
      int end = ((i + nums[i]) % n + n) % n;
      // i = end 是自环
      if (nums[i] <= 0 || i == end) continue;
      graph[i].push_back(end);
      Indeg[end]++;
    }

    if (topo_sort(n)) return true;

    // 更新数组，把刚才的正向边扔掉
    graph.clear();
    graph.resize(n);
    Indeg.clear();
    Indeg.resize(n);

    // 再处理负向边的情况
    for (int i = 0; i < n; ++i) {
      // 处理环形的情况
      // 图中是下标
      int end = ((i + nums[i]) % n + n) % n;
      // i = end 是自环
      if (nums[i] >= 0 || i == end) continue;
      graph[i].push_back(end);
      Indeg[end]++;
    }

    if (topo_sort(n)) return true;
    return false;
  }
};

int main(int argc, char const* argv[]) { return 0; }