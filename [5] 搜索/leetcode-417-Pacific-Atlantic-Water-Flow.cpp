/*
 *@Description:用一个非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
 *规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
 *  请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
 *
 *
 * @输入示例：
 *
 *   太平洋 ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

 * @输出实例：
 *
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]]
 * (上图中带括号的单元).
 *
 * @输入输出说明：
 *
 * 输出坐标的顺序不重要
 * 坐标 m 和 n 都小于150
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 可以反过来想,从两个大洋开始向上流,这样我们只需要对矩形四条边进行搜索。
 * 搜索完成后,只需遍历一遍矩阵,满足条件的位置即为两个大洋向上流都能到达的位置。
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
  static void dfs(const vector<vector<int>>& matrix,
                  vector<vector<bool>>& can_reach, int r, int c) {
    if (can_reach[r][c]) {
      return;
    }
    can_reach[r][c] = true;
    int x = 0;
    int y = 0;
    for (int i = 0; i < 4; i++) {
      x = r + directions[i];
      y = c + directions[i + 1];
      if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() &&
          matrix[r][c] <= matrix[x][y]) {
        dfs(matrix, can_reach, x, y);
      }
    }
  }

  static vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    // 考虑特殊情况
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }
    vector<vector<int>> ans;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
    vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      dfs(matrix, can_reach_p, i, 0);
      dfs(matrix, can_reach_a, i, n - 1);
    }

    for (int i = 0; i < n; ++i) {
      dfs(matrix, can_reach_p, 0, i);
      dfs(matrix, can_reach_a, m - 1, i);
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (can_reach_a[i][j] && can_reach_p[i][j]) {
          // 二维
          // vector：可以用花括号指定行数，无法指定列长，但可以用花括号初始化列元素。
          // vector<vector<int>> c{ N };
          // vector<vector<int>> d1{ N ,vector<int> {1,2,3} };
          // 二维 vector push_back() 的方式
          ans.push_back(vector<int>{i, j});
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }