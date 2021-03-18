/*
 * @Description:
 *
 * 给定 n 节台阶，每次可以走一步或走两步，求一共有多少种方式可以走完这些台阶
 *
 * @输入示例：
 *
 *  3
 *
 * @输出实例：
 *
 *  3
 *
 * @输入输出说明：
 *
 * 输入是一个数字，表示台阶数量，输出是爬台阶的方式数量
 *
在这个样例中,一共有三种方法走完这三节台阶:每次走一步;先走一步,再走两步;先走两步,再走一步。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 这是十分经典的斐波那契数列题。定义一个数组 dp,dp[i] 表示走到第 i
 阶的方法数。因为 我们每次可以走一步或者两步,所以第 i 阶可以从第 i-1 或 i-2
 阶到达。换句话说,走到第 i 阶的 方法数即为走到第 i-1 阶的方法数加上走到第 i-2
 阶的方法数。这样我们就得到了状态转移方程 dp[i] = dp[i-1] +
 dp[i-2]。注意边界条件的处理。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int climbStairs(int n) {
    if (n <= 2) return n;
    // 因为要返回 dp[n], 所以需要有 n + 1 个元素
    // 爬第 0 级台阶共有一种选择
    // 爬第 1 级台阶共有一种选择
    // 爬第 2 级台阶共有两种选择
    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};

int main(int argc, char const* argv[]) { return 0; }
