/*
 * @Description:
 *
 * 找出数组中不连续的子序列的个数
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
 * 动态规划 + 哈希表，实在是太难想了
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return 0;
    int ans = 0;
    // 末尾元素为 i, 相差为 d 的弱等差子序列个数（两个就行）
    // d —— i 组成键值对
    vector<unordered_map<long long, int>> dp(n);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        long long d = (long long)nums[i] - nums[j];
        auto it = dp[j].find(d);
        int cnt = it == dp[j].end() ? 0 : it->second;
        // 此时 dp 实际上为真等差序列
        dp[i][d] += cnt + 1;
        ans += cnt;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
