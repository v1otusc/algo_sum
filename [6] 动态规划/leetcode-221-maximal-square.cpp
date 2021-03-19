/*
 * @Description:
 *
 * 给定一个二维的 0-1 矩阵，求全由构成的最大正方形面积
 *
 * @输入示例：
 *
 [["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]]
 *
 * @输出实例：
 *
 * 4
 *
 * @输入输出说明：
 *
 * 输入是一个二维 0-1 数组,输出是最大正方形面积。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 对于在矩阵搜索正方形或者长方形的题型，一种常见的做法是定义一个二维 dp
 数组，其中dp[i][j] 表示满足题目条件的题目条件的，以 (i, j) 为右下角
 的正方形或者长方形的属性。对于本题，则表示以 (i, j) 为右下角的正方形或
 长方形的面积。如果当前位置是 0，那么 dp[i][j] 即为 0。如果当前位置为 1
 假设 dp[i][j] = k^2,其充分条件为 dp[i-1][j-1]、dp[i][j-1] 和 dp[i-1][j]
 的值必须不小于 (k - 1)^2--注意可以大于！
 否则 (i, j) 位置不可以构成一个边长为 k 的正方形。同理,如果这三个值中的最小值为
 k - 1, 则 (i, j) 位置一定且最大可以构成一个边长为 k 的正方形
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int maximalSquare(vector<vector<char>>& matrix) {
    // 考虑特殊情况
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }
    int max_side = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (matrix[i - 1][j - 1] == '1') {
          // 注意这里 min 只能比较两个
          dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
        }
        max_side = max(max_side, dp[i][j]);
      }
    }
    return max_side * max_side;
  }
};

int main(int argc, char const* argv[]) { return 0; }