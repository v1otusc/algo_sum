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
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int k) {
    // 根据题目条件，再怎么飞，花费也不会超过这个值了
    const int INF = 10000 * 101 + 1;
    // 经过 k 站中转，一共走了 k + 1 步
    // dp[i][city] 表示走了 i 步到城市 city 所需的花费
    // 这个初始值设置比较难想
    vector<vector<int>> dp(k + 2, vector<int>(n, INF));

    // 无论经过多少次，到 src 的花费为 0
    for (int i = 0; i < k + 2; ++i) dp[i][src] = 0;
    // dp[0][src] = 0;

    for (int i = 1; i < k + 2; ++i) {
      // dp[i][src] = 0;
      for (auto& flight : flights) {
        dp[i][flight[1]] = min(dp[i - 1][flight[0]] + flight[2], dp[i][flight[1]]);
      }
    }
    return dp[k+1][dst] == INF ? -1 : dp[k+1][dst];
  }
};

int main(int argc, char const* argv[]) { return 0; }