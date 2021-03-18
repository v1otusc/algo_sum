/*
 * @Description:
 *
假如你是一个劫匪,并且决定抢劫一条街上的房子,每个房子内的钱财数量各不相同。如果
你抢了两栋相邻的房子,则会触发警报机关。求在不触发机关的情况下最多可以抢劫多少钱。
 *
 * @输入示例：
 *
 * [2, 7, 9, 3, 1]
 *
 * @输出实例：
 *
 * 12
 *
 * @输入输出说明：
 *
 * 输入是一个一维数组,表示每个房子的钱财数量;输出是劫匪可以最多抢劫的钱财数量。
 * 在这个样例中，最多的抢劫方式为抢劫第 1、3、5 个房子
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 定义一个数组 dp, dp[i] 表示抢劫到第 i 个房子时,可以抢劫的最大数量。我们考虑
 dp[i],
 此时可以抢劫的最大数量有两种可能,一种是我们选择不抢劫这个房子,此时累计的金额即为
 dp[i-1];另一种是我们选择抢劫这个房子,那么此前累计的最大金额只能是
 dp[i-2],因为我们不 能够抢劫第 i-1
 个房子,否则会触发警报机关。因此本题的状态转移方程为 dp[i] = max(dp[i-1],
 nums[i-1] + dp[i-2])。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int rob(vector<int>& nums) {
    // 考虑特殊情况
    if (nums.empty()) return 0;
    int n = nums.size();
    //
    vector<int> dp(n + 1, 0);
    dp[1] = nums[0];
    for (int i = 2; i <= n; ++i) {
      dp[i] = max(dp[i - 1], nums[i - 1] + dp[i - 2]);
    }
    return dp[n];
  }
};

int main(int argc, char const* argv[]) { return 0; }