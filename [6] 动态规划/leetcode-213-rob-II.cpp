/*
 * @Description:
 *
 * 环形打家劫舍
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
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return max(rob_range(nums, 1, n - 1), rob_range(nums, 0, n - 2));
  }

  // 滚动数组的方法
  int rob_range(vector<int>& nums, int begin, int end) {
    int dp_i_1 = 0;
    int dp_i_2 = 0;
    int dp_i = 0;
    for (int i = end; i >= begin; --i) {
      dp_i = max(nums[i] + dp_i_2, dp_i_1);
      dp_i_2 = dp_i_1;
      dp_i_1 = dp_i;
    }
    return dp_i;
  }
};

int main(int argc, char const* argv[]) { return 0; }
