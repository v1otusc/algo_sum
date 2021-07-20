/*
 * @Description:
 *
 * 包信封问题
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
 * 转化为找出最长递增子序列问题
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

struct Cmp {
  bool operator()(vector<int>& lhs, vector<int>& rhs) {
    if (lhs[0] == rhs[0]) {
      // 宽度相同，高度逆序排列
      return lhs[1] > rhs[1];
    } else {
      // 宽度从小到大排列
      return lhs[0] < rhs[0];
    }
  }
};

class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), Cmp());
    int n = envelopes.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (envelopes[j][1] < envelopes[i][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    // 最后输出
    int ret = 1;
    for (int i = 1; i < n; ++i) {
      ret = max(ret, dp[i]);
    }
    return ret;
  }
};

int main(int argc, char const* argv[]) { return 0; }
