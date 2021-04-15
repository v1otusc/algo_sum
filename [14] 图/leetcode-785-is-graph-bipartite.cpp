/*
 * @Description:
 *
 * 给定一个无向图，判断其是否可以二分
 *
 * @输入示例：
 *
 *  [[1,3], [0,2], [1,3], [0,2]]
 *
 * @输出实例：
 *
 * true
 *
 * @输入输出说明：
 *
 * 输入是邻接链表表示的图(如位置 0 的邻接链表为 [1,3],表示 0 与 1、0 与 3 相连)
 * ;输出是一个布尔值,表示图是否二分。
 *
 * 在上述实例中，可以把{0，2}分为一组，把{1，3}分为一组
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 利用队列和广度优先搜索，可以对未染色的节点进行染色，并且检查是否有颜色相同的相邻节点存在
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    if (n < 3) {
      return true;
    }
    // 用 0 表示未检查的节点，用 1 和 2 表示两种不一样的颜色
    vector<int> color(n, 0);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (!color[i]) {
        q.push(i);
        color[i] = 1;
      }
      // 广度优先搜索节点
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int j : graph[node]) {
          if (color[j] == 0) {
            q.push(j);
            color[j] = (color[node] == 1) ? 2 : 1;
          } else if (color[j] == color[node]) {
            return false;
          }
        }
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }
