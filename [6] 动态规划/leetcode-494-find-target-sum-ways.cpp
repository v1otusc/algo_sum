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
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    if (sum < target || (sum + target) % 2 == 1) {
      return 0;
    }
    return find_sum(nums, ((sum + target) / 2));
  }

  int find_sum(vector<int>& nums, int sum) {
    int n = nums.size();
    // n 个物品，装满 sum 的解决方案，可以选也可以不选
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i < n + 1; ++i) {
      dp[i][0] = 1;
    }
    for (int i = 1; i < n + 1; ++i) {
      // j 可以是 0
      for (int j = 0; j < sum + 1; ++j) {
        if (j < nums[i - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
        }
      }
    }
    return dp[n][sum];
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{0,0,0,0,0,0,0,0,1};
  int target = 1;
  Solution s;
  cout << s.findTargetSumWays(nums, target) << endl;
  return 0;
}
