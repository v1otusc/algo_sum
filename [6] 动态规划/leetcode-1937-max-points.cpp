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
  typedef long long ll;

 public:
  long long maxPoints(vector<vector<int>>& points) {
    int m = points.size();
    int n = points[0].size();
    vector<vector<ll>> dp(m, vector<ll>(n, 0));
    vector<ll> maxL(n, 0), maxR(n, 0);
    // 首行,并且计算出 maxL
    for (int j = 0; j < n; ++j) {
      dp[0][j] = points[0][j];
      maxL[j] = j == 0 ? dp[0][j] + j : max(maxL[j - 1], dp[0][j] + j);
    }

    for (int j = n - 1; j >= 0; --j) {
      maxR[j] = j == n - 1 ? dp[0][j] - j : max(maxR[j + 1], dp[0][j] - j);
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = points[i][j] + max(maxL[j] - j, maxR[j] + j);
        maxL[j] = j == 0 ? dp[i][j] + j : max(maxL[j - 1], dp[i][j] + j);
      }
      for (int j = n - 1; j >= 0; --j) {
        maxR[j] = j == n - 1 ? dp[i][j] - j : max(maxR[j + 1], dp[i][j] - j);
      }
    }
    return *max_element(dp.back().begin(), dp.back().end());
  }
};

int main(int argc, char const* argv[]) { return 0; }
