/*
 * @Description:
 *
 * 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b
 * 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
 * 省份是一组直接或间接相连的城市，组内不含有其他没有相连的城市
 *
 * 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i
 * 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
 *
 * @输入实例：
 *
 * [[1, 1, 0],
 *  [1, 1, 0],
 *  [0, 0, 1]]
 *
 * @输出实例：
 *
 *  2
 *
 * @输入输出说明：
 *
 * 输入是一个二维数组,输出是一个整数,表示省份数量。因为连接关系具有对称性,该二
 * 维数组为对称矩阵。并且，对角线上的值全部为 1。
 * 在这个样例中，[1, 2] 是一个省份，[3] 是一个省份
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 深度优先搜索的思路是很直观的。遍历所有城市，对于每个城市，如果该城市尚未被访问过，则从该城市开始深度优先搜索，通过邻接矩阵
 * 得到与该城市直接相连的城市有哪些，这些城市和该城市属于同一个连通分量，然后对这些城市继续深度优先搜索，直到同一个连通分量的所有城市都被访问到，即可得到一个省份。遍历完全部城市以后，即可得到连通分量的总数，即省份的总数。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static void dfs(vector<vector<int>>& isConnected, vector<int>& visited,
                  int provinces, int i) {
    for (int j = 0; j < provinces; ++j) {
      if (isConnected[i][j] == 1 && !visited[j]) {
        visited[j] = 1;
        dfs(isConnected, visited, provinces, j);
      }
    }
  }

  static int findCircleNum(vector<vector<int>>& isConnected) {
    int provinces = isConnected.size();
    vector<int> visited(provinces);
    int circles = 0;
    for (int i = 0; i < provinces; ++i) {
      if (!visited[i]) {
        dfs(isConnected, visited, provinces, i);
        circles++;
      }
    }
    return circles;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  cout << Solution::findCircleNum(isConnected) << endl;
  return 0;
}
