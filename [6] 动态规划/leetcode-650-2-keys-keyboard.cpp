/*
 * @Description:
 *
给定一个字母 A,已知你可以每次选择复制全部字符,或者粘贴之前复制的字符,求最少需
要几次操作可以把字符串延展到指定长度。
 *
 * @输入示例：
 *
 * 3
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 输入是一个正整数,代表指定长度;输出是一个整数,表示最少操作次数。
 * 在这个样例中,一种最优的操作方法是先复制一次,再粘贴两次。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
不同于以往通过加减实现的动态规划,这里需要乘除法来计算位置,因为粘贴操作是倍数增加的
我们使用一个一维数组 dp,其中位置 i 表示延展到长度 i
的最少操作次数。对于每个位置 j,如果 j 可以被 i 整除,那么长度 i 就可以由长度 j
操作得到，其操作次数把**等价于**把一个长度为 1 的 A 延展到长度为
i/j，因此我们可以得到递推公式
dp[i] = dp[j] + d[i/j]
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int minSteps(int n) {
    // i == 0 和 i == 1 都只需要 0 步
    // dp[0] = dp[1] == 0
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
      dp[i] = i;
      // 为什么 j <= sqrt(n)?
      // for (int j = 2;; j <= sqrt(n); ++j)
      for (int j = 2; j <= i-1; ++j) {
        if(i % j == 0) {
          // 不需要再 +1(表示复制的一步) 了，i / j 中已经包括进去了
          dp[i] = dp[j] + dp[i / j];
        }
      }
    }
    return dp[n];
  }
};

int main(int argc, char const* argv[]) { return 0; }