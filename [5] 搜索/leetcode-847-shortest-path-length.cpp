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
 * 使用 mask 从低到高第 i 位为 0 表示第 i 个节点还未被访问过
 *
 * 访问第 i 个点的状态 state = (1 << i) & mask;
 * 更新第 i 个点的状态为 1 mask = mask | (1 << i);
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    // 1. 初始化队列及标记数组，存入起点
    // 三个属性分别为 idx, mask, dist
    queue<vector<int>> q;
    // 节点编号及当前状态，同一种状态下访问同一个节点必然是无用工;
    vector<vector<bool>> vis(n, vector<bool>(1 << n));
    for (int i = 0; i < n; ++i) {
      q.push({i, 1 << i, 0});
      vis[i][1 << i] = true;
    }

    // 2. 开始搜索
    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        auto vec = q.front();
        int cur = vec[0];
        int mask = vec[1];
        int dist = vec[2];
        q.pop();

        if (mask == (1 << n) - 1) return dist;

        // 然后进行扩展
        for (int x : graph[cur]) {
          // 标记为访问过了
          int nextmask = mask | (1 << x);
          if (!vis[x][nextmask]) {
            q.push({x, nextmask, dist + 1});
            vis[x][nextmask] = true;
          }
        }
      }
    }
    return 0;
  }
};

int main(int argc, char const* argv[]) { return 0; }
