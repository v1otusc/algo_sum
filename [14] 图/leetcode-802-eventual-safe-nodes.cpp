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
 * 拓扑排序 + 出度入度反图
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    // 反图，邻接表存储
    vector<vector<int>> new_graph(n);
    // 节点入度
    vector<int> Indeg(n, 0);

    // 反图的构造方法
    for (int i = 0; i < n; i++) {
      for (int x : graph[i]) {
        new_graph[x].push_back(i);
      }
      // 原数组记录的节点出度，在反图中就是入度
      Indeg[i] = graph[i].size();
    }

    // 拓扑排序
    queue<int> q;

    // 首先将入度为 0 的点存入队列
    for (int i = 0; i < n; i++) {
      if (!Indeg[i]) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      // 每次弹出队头元素
      int cur = q.front();
      q.pop();

      for (int x : new_graph[cur]) {
        // 将以其为起点的有向边删除，更新终点入度
        Indeg[x]--;
        if (!Indeg[x]) q.push(x);
      }
    }

    // 最终入度（原图中出度）为 0 的所有点均为安全点
    vector<int> ret;
    for (int i = 0; i < n; i++) {
      if (!Indeg[i]) ret.push_back(i);
    }
    sort(ret.begin(), ret.end());
    return ret;
  }
};

int main(int argc, char const* argv[]) { return 0; }
