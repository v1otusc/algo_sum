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
 * 使用 dijkstra 单源单向最短路径算法
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    const int inf = INT_MAX / 2;
    // 初始化图
    vector<vector<int>> graph(n, vector<int>(n, inf));
    for (auto& t : times) {
      // 将节点编号减1，从而使节点编号位于 [0,n-1] 范围
      int x = t[0] - 1;
      int y = t[1] - 1;
      // 从 x 到 y 的距离
      graph[x][y] = t[2];
    }
    // 从源点到某点的距离数组
    vector<int> dist(n, inf);
    // 由于从 k 开始，所以该点距离设为 0，也即源点
    dist[k - 1] = 0;

    // 代表节点是否被更新，初始值未被更新
    vector<int> used(n);
    for (int i = 0; i < n; ++i) {
      // 在还未确定最短路的点中，寻找距离最小的点
      int x = -1;
      for (int y = 0; y < n; ++y) {
        if (!used[y] && (x == -1 || dist[y] < dist[x])) {
          x = y;
        }
      }
      // 用该点更新所有其他点的距离
      used[x] = true;
      for (int y = 0; y < n; ++y) {
        dist[y] = min(dist[y], dist[x] + graph[x][y]);
      }
    }
    // 找到距离最远的点
    int ans = *max_element(dist.begin(), dist.end());
    return ans == inf ? -1 : ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
