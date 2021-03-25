/*
 * @Description:
 *
 * 给定一些硬币的面额，求最少可以用多少硬币组成给定的金额
 *
 * @输入示例：
 *
 * coins = [1, 2, 5]
 * amount = 11
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 在这个样例中，最少的组合方法是 11 = 5 + 5 + 1
 * 可以认为每种硬币的数量是无限的
 *
 * @限制条件：
 *
 * NULLn
 *
 * @题目思路：
 *
 * 是一个完全背包问题
 * 这里注意,我们把 dp 数组初始化为 amount + 1 而不是-1
的原因是,在动态规划过程中有求 最小值的操作,如果初始化成-1
则会导致结果始终为-1。至于为什么取这个值,是因为 i 最大可以取
amount,因为最多的组成方式是只用 1 元硬币,因此 amount + 1 一定大于所有可能的组合
方式,取最小值时一定不会是它。在动态规划完成后,若结果仍然是此值,则说明不存在满足条
件的组合方法,返回-1。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int coinChange(vector<int>& coins, int amount) {
    if (coins.empty()) return -1;
    // 此时的 dp[i][j] 表示，当遍历到第 i coins 中的元素时
    // 为了组成 j 而需要的最少的组合方法
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
      for (const int& coin : coins) {
        if (i >= coin) {
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};

int main(int argc, char const* argv[]) { return 0; }