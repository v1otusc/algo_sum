/*
 * @Description:
 *
 * 给定一个数组，求这个数组中连续且等差的子数组一共有多少个
 *
 * @输入示例：
 *
 * nums = [1, 2, 3, 4]
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 输入是一个一维数组，输出是满足等差条件的连续子数组个数
 * 在这个样例中，
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 这道题略微特殊,因为要求是等差数列,可以很自然的想到子数组必定满足 num[i] -
   num[i-1] = num[i-1] - num[i-2]。然而由于我们对于 dp 数组的定义是--以 i
   结尾的,满足某些条件的子数组数量,而等差子数组可以在任意一个位置终结,因此此题在最后需要对
   dp 数组求和。

   ！！需要找规律

   数组	        等差数列的数目	    与上一数组的等差数列数目比较
  1 2 3	            1	                    1 - 0 = 1
  1 2 3 4	          3	                    3 - 1 = 2
  1 2 3 4 5	        6	                    6 - 3 = 3
  1 2 3 4 5 6	      10	                  10 - 6 = 4
  1 2 3 4 5 6 7	    15	                  15 - 10 = 5
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    // 小于 3 个必不可能是等差数组
    if (n < 3) {
      return 0;
    }
    vector<int> dp(n, 0);
    for (int i = 2; i < n; ++i) {
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
        // dp
        // 数组中存储的实际上是等差数列中每增加一个元素和未增加此元素的等差数列相比，而增加的子集合元素！
        dp[i] = dp[i - 1] + 1;
      }
    }
    return accumulate(dp.begin(), dp.end(), 0);
  }
};

int main(int argc, char const* argv[]) { return 0; }
