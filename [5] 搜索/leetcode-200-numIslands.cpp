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
 public:
  void dfs(vector<vector<char>>& grid, int r, int c) {
    grid[r][c] = '0';
    int maxr = grid.size() - 1;
    int maxc = grid[0].size() - 1;
    if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
    if (r + 1 <= maxr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
    if (c + 1 <= maxc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
    if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
    return;
  }

  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    if (nr == 0) return 0;
    int nc = grid[0].size();

    int count = 0;
    for (int i = 0; i < nr; ++i) {
      for (int j = 0; j < nc; ++j) {
        if (grid[i][j] == '1') {
          count++;
          dfs(grid, i, j);
        }
      }
    }
    return count;
  }
};

int main(int argc, char const* argv[]) { return 0; }
