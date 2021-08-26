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
 * 使用拓扑排序!
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
    // 入度
    // 从子节点指向父节点的有向图
    vector<int> in_deg(nodes);
    for (int i = 0; i < nodes; ++i) {
      if (parent[i] != -1) ++in_deg[parent[i]];
    }

    vector<int> node_cnt(nodes, 1);
    queue<int> q;
    // push 进所有的叶子节点
    for (int i = 0; i < nodes; ++i) {
      if (in_deg[i] == 0) {
        q.push(i);
      }
    }

    while(!q.empty()) {
      int v = q.front();
      q.pop();
      if (value[v] == 0) node_cnt[v] = 0;
      int u = parent[v];
      if (u != -1) {
        value[u] += value[v];
        node_cnt[u] += node_cnt[v];
        if (--in_deg[u] == 0) {
          q.push(u);
        }
      }
    }
    return node_cnt[0];
  }
};

int main(int argc, char const* argv[]) { return 0; }
