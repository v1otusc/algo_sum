/*
 * @Description:
 *
 * 输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
 * 要求时间复杂度为O(n)。
 *
 * @输入示例：
 *
 * nums = [-2,1,-3,4,-1,2,1,-5,4]
 *
 * @输出实例：
 *
 * 6
 *
 * @输入输出说明：
 *
 * 连续子数组[4，-1，2，1]的和最大，为6
 *
 * @限制条件：
 *
 *
 *
 * @题目思路：
 *
 * 动态规划
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int ret = nums[0];
    int pre = 0;
    for (auto& num : nums) {
      pre = max(pre + num, num);
      ret = max(ret, pre);
    }
    return ret;
  }
};

int main(int argc, char const* argv[]) { return 0; }
