/*
 * @Description:
 *
 * 已知字母 A-Z 可以表示成数字 1-26
 * 给定一个数字串，求有多少种不同的字符串等价于这个数字串
 *
 * @输入示例：
 *
 * "226"
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 输入是一个由数字组成的字符串,输出是满足条件的解码方式总数。
 * 在这个样例中,有三种解码方式:BZ(2 26)、VF(22 6) 或 BBF(2 2 6)。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 因为只有 1-26 可以表示字母,因此对于一些特殊情况,比如数字 0
 * 或者当相邻两数字大于 26 时,需要有不同的状态转移方程
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int numDecodings(string s) {
    int n = s.length();
    // -- 考虑特殊情况
    if (n == 0) return 0;
    int prev = s[0] - '0';
    // 如果首个数字为 0 ：
    if (!prev) return 0;
    // 如果只有一个数字
    if (n == 1) return 1;
    // -- 考虑特殊情况结束

    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
      // 从第二个数字开始
      int cur = s[i - 1] - '0';
      // 出现 00 或者 30 或者 40 这样的，没有解决方案
      if ((prev == 0 || prev > 2) && cur == 0) {
        return 0;
      }
      // 出现 1X 或者 2X 这样的情况
      if ((prev < 2 && prev > 0) || prev == 2 && cur < 7) {
        if (cur) {
          // 如果不是 10 或者 20 这两种情况
          dp[i] = dp[i - 1] + dp[i - 2];
        } else {
          // 如果是 10 或 20 这种情况
          // 那就只能组成 j 或者 t 了
          dp[i] = dp[i - 2];
        }

      } else {
        // 最简单的情况，就是没法 prev 和 cur 没法连上
        // 类似于 34 这种情况
        dp[i] = dp[i - 1];
      }
      prev = cur;
    }
    return dp[n];
  }
};

int main(int argc, char const* argv[]) { return 0; }
