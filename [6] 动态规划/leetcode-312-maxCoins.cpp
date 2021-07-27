/*
 * @Description:
 *
 * 戳气球问题
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
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    // 新建两个虚拟气球，最左侧和最右侧，分数为 1
    vector<int> points(n + 2);
    points[0] = points[n + 1] = 1;
    for (int i = 0; i < n; ++i) {
      points[i] = nums[i];
    }
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 0; --i) {
      for (int j = i + 1; j < n + 2; ++j) {
        for (int k = i + 1; k < j; ++k) {
          dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] +
                                       points[i] * points[j] * points[k]);
        }
      }
    }

    // 使用开区间来记录
    return dp[0][n + 1];
  }
};

int main(int argc, char const* argv[]) { return 0; }
