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
 private:
  vector<vector<int>> ans;
  vector<int> path;

  void backtrace(vector<vector<int>>& g, int x, int n) {
    if (x == n) ans.push_back(path);

    for (auto y : g[x]) {
      path.push_back(y);
      backtrace(g, y, n);
      path.pop_back();
    }
  }

 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    // 一切都要从 0 开始
    path.push_back(0);
    backtrace(graph, 0, graph.size() - 1);
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }