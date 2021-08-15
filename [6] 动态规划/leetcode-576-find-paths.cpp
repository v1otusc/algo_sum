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
  const int mod = 1000000007;

 public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    // 定义 dp[i][j][k] 表示球移动 i 次之后位于坐标(j, k) 的路径数量
    vector<vector<vector<int>>> dp(maxMove + 1,
                                   vector<vector<int>>(m, vector<int>(n, 0)));
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int ans = 0;
    dp[0][startRow][startColumn] = 1;
    for (int i = 0; i < maxMove; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < n; ++k) {
          // 走了 i 步骤到了坐标 (j, k) 点的次数
          int count = dp[i][j][k];
          if (count > 0) {
            for (auto& direction : directions) {
              // 新坐标
              int j1 = j + direction[0], k1 = k + direction[1];
              // 如果在界内
              if (j1 >= 0 && j1 < m && k1 >= 0 && k1 < n) {
                dp[i + 1][j1][k1] = (dp[i + 1][j1][k1] + count) % mod;
              } else {
                // 如果在界外
                ans = (ans + count) % mod;
              }
            }
          }
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
