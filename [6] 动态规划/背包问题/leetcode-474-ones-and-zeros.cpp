/*
 * @Description:
 *
 * 给定 m 个数字 0 和 n 个数字 1,以及一些由 0-1
 构成的字符串,求利用这些数字最多可以构成多少个给定的字符串,字符串只可以构成一次。
 *
 * @输入示例：
 *
 *  Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 *
 * @输出实例：
 *
 * 4
 *
 * @输入输出说明：
 *
 * 在这个样例中，我们可以用 5 个 0 和 3 个 1 构成 Array 中的元素
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 定义状态：尝试题目问啥，就把啥定义成状态。dp[i][j][k] 表示输入字符串在子区间
 [0, i] 能够使用 j 个 0 和 k 个 1 的字符串的最大数量。

 那么实际上要装两个背包（0背包和1背包），在这里直接展示三维空间压缩到二维的写法
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (const string& str : strs) {
      auto cnt = count01(str);
      int count0 = cnt.first;
      int count1 = cnt.second;
      for (int i = m; i >= count0; --i) {
        for (int j = n; j >= count1; --j) {
          dp[i][j] = max(dp[i][j], 1 + dp[i - count0][j - count1]);
        }
      }
    }
    return dp[m][n];
  }

  // 辅助函数
  static pair<int, int> count01(const string& s) {
    int count0 = s.length();
    int count1 = 0;
    for (const char& c : s) {
      if (c == '1') {
        ++count1;
        --count0;
      }
    }
    return make_pair(count0, count1);
  }
};

int main(int argc, char const* argv[]) { return 0; }
