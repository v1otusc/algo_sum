/*
 * @Description:
 *
 *
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。
 *
 * @输入示例：
 *
 * amout = 5, coins = [1, 2, 5]
 *
 * @输出实例：
 *
 * 4
 *
 * @输入输出说明：
 *
 * 5 = 5
 * 5 = 2 + 2 + 1
 * 5 = 2 + 1 + 1 + 1
 * 5 = 2 + 1 + 1 + 1 + 1
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 可以通过动态规划的方法计算可能的组合数。用 dp[x]
 * 表示金额之和等于 x 的硬币组合数，目标是求 dp[amount]
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
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    // 当目标结果为 0，不选择硬币，所以也是有一种选择的
    dp[0] = 1;
    for (int coin : coins) {
      for (int i = coin; i <= amount; ++i) {
        dp[i] += dp[i - coin];
      }
    }
    //-- 上述做法是不会出现重复的情况的
    // 因为外层循环保证 i 从 coin 开始
    // 而 dp[i] += dp[i - coin] 保证了最后选择的一定是 coin
    // 所以 coins = [1, 2] 对于 dp[3]
    // 只会出现 3 = 1 + 1 + 1 和 3 = 1 + 2
    // 不会出现 3 = 1 + 2 和 3 = 2 + 1 重复计数
    return dp[amount];
  }
};

int main(int argc, char const* argv[]) { return 0; }
