/*
 * @Description:
 *
 * 给定一个由 0 和 1 组成的二维矩阵，求每个位置到最近 0 的距离
 *
 * @输入示例：
 *
 * [[0, 0, 0],
 *  [0, 1, 0],
 *  [1, 1, 1]]
 *
 * @输出实例：
 *
 * [[0, 0, 0],
 *  [0, 1, 0],
 *  [1, 2, 1]]
 *
 * @输入输出说明：
 *
 * NULL
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 从左上到右下进行一次动态搜索，再从右下到左上进行一次动态搜索。
 * 这样就能完成四个方向的搜索
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    // 考虑特殊情况
    if (matrix.empty()) {
      return {};
    }
    int m = matrix.size();
    int n = matrix[0].size();
    // 注意初始化数组的方式--无限大
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == 0) {
          dp[i][j] = 0;
        } else {
          if (j > 0) {
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
          }
          if (i > 0) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
          }
        }
      }
    }

    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        // 因为已经判断过 if (matrix[i][j] == 0) 了
        if (matrix[i][j] != 0) {
          if (j < n - 1) {
            dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
          }
          if (i < m - 1) {
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
          }
        }
      }
    }
    return dp;
  }
};

int main(int argc, char const* argv[]) { return 0; }
