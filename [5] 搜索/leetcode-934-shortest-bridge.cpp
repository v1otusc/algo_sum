/*
 * @Description:
 *
 * 给定一个二维 0-1 矩阵，其中 1 表示陆地，0 表示海洋，每个位置与上下左右相连。
 * 已知矩阵中有且只有两个岛屿，求最少要填海造陆多少个位置才可以将两个岛屿相连
 *
 * @输入示例：
 *
 [[1,1,1,1,1],
 [1,0,0,0,1],
 [1,0,1,0,1],
 [1,0,0,0,1],
 [1,1,1,1,1]]
 *
 * @输出实例：
 *
 * 1
 *
 * @输入输出说明：
 *
 * 输入是一个二维整数数组,输出是一个非负整数,表示需要填海造陆的位置数。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 本题实际上是求两个岛屿间的最短距离,因此我们可以先通过任意搜索方法找到其中一个岛
 屿,然后利用广度优先搜索,查找其与另一个岛屿的最短距离。

 首先用 dfs
 找到其中一个岛屿的全部坐标，并将这座岛的所有元素都标记为2；我们要求的就是标记为2的坐标与标记为1的坐标的最小距离
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

vector<int> directions{-1, 0, 1, 0, -1};

class Solution {
 public:
  void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid,
                  int m, int n, int i, int j) {
    if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == 2) {
      return;
    }
    if (grid[i][j] == 0) {
      points.push({i, j});
      return;
    }
    // 将岛屿原有的 1 标记为 2
    grid[i][j] = 2;
    dfs(points, grid, m, n, i - 1, j);
    dfs(points, grid, m, n, i + 1, j);
    dfs(points, grid, m, n, i, j - 1);
    dfs(points, grid, m, n, i, j + 1);
  }

  int shortestBridge(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    // 找到岛屿周围所有海洋的坐标
    queue<pair<int, int>> points;
    // dfs 寻找第一个岛屿，并把 1 全部赋值为 2
    // flipped 的作用就是找到岛屿后就跳出循环
    bool flipped = false;
    for (int i = 0; i < m; ++i) {
      if (flipped) {
        break;
      }
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          dfs(points, grid, m, n, i, j);
          flipped = true;
          break;
        }
      }
    }

    // bfs 寻找第二个岛屿，并把过程中经过的 0 变成
    // 2（从第一个岛屿出发，向外扩张）；
    int x = 0;
    int y = 0;
    int level = 0;
    while (!points.empty()) {
      ++level;
      int n_points = points.size();
      while (n_points--) {
        int r = points.front().first;
        int c = points.front().second;
        points.pop();
        for (int k = 0; k < 4; ++k) {
          x = r + directions[k];
          y = c + directions[k + 1];
          if (x >= 0 && y >= 0 && x < m && y < n) {
            if (grid[x][y] == 2) {
              continue;
            }
            if (grid[x][y] == 1) {
              return level;
            }
            points.push({x, y});
            grid[x][y] = 2;
          }
        }
      }
    }
    return 0;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> grid = {
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,0,1,0,1},
    {1,0,0,0,1},
    {1,1,1,1,1},
  };
  Solution s;
  cout << s.shortestBridge(grid) << endl;
  return 0;
}