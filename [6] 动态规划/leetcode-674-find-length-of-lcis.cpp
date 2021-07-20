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
  int findLengthOfLCIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
      if (nums[i] > nums[i - 1]) {
        dp[i] = dp[i-1] + 1;
      }
    }
    int ans = 1;
    for (int i = 1; i < n; ++i) {
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
int main(int argc, char const* argv[]) { return 0; }
