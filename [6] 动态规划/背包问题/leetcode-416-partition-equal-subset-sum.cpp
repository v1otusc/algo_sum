/*
 * @Description:
 *
 * 给定一个正整数数组，求是否可以把这个数组分成相同的两部分
 *
 * @输入示例：
 *
 * [1, 5, 11, 5]
 *
 * @输出实例：
 *
 * true
 *
 * @输入输出说明：
 *
 * 在这个样例中，满足条件的分割方法为 [1, 5, 5] 和 [11]
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 目标是选取一部分数字，使他们的总和为 sum/2
 * 用一个布尔值矩阵来表示状态转移矩阵
 * 注意边界条件的处理
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

/*class Solution {
 public:
  static bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    int target = sum / 2, n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    // 考虑边界情况，如果 target == 0
    // 那么所有的情况都能满足，不加进去就是了
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = true;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= target; ++j) {
        if (j >= nums[i - 1]) {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
        } else {
          // 竟然小于 nums[i - 1], 说明根本不能加进去
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[n][target];
  }
};*/

// 进行空间压缩的做法
class Solution {
 public:
  static bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    int target = sum / 2, n = nums.size();
    vector<bool> dp(target + 1, false);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = target; j <= nums[i - 1]; --j) {
        dp[j] = dp[j - nums[i - 1]] || dp[j];
      }
    }
    return dp[target];
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 5, 10, 6};
  string s = (Solution::canPartition(nums)) ? "true" : "false";
  cout << s << endl;
  return 0;
}
