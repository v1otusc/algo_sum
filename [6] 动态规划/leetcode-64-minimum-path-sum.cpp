/*
 * @Description:
 *
 给定一个 m × n
 大小的非负整数矩阵，求从左上角开始到右下角结束的、经过的数字的和最小的路径。
 每次只能向右或者向下移动
 *
 * @输入示例：
 *
 [[1,3,1],
 [1,5,1],
 [4,2,1]]
 *
 * @输出实例：
 *
 * 7
 *
 * @输入输出说明：
 *
 * 输入是一个二维数组,输出是最优路径的数字和。
 * 在这个样例中,最短路径为 1->3->1->1->1。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 以定义一个同样是二维的 dp 数组,其中 dp[i][j] 表示从左上角开始到 (i, j)
   位置的最优路径的数字和。因为每次只能向下或者向右移动，容易得到状态转移方程
   dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (i == 0 && j == 0) {
          dp[i][j] = grid[i][j];
        } else if (i == 0) {
          dp[i][j] = dp[i][j - 1] + grid[i][j];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j] + grid[i][j];
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
      }
    }
    return dp[m - 1][n - 1];
  }
};

int main(int argc, char const* argv[]) { return 0; }