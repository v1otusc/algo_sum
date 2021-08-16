/*
 * @Description:
 *
 *
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
 *
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 private:
  int ans;
  vector<int> vis;
  vector<vector<int>> match;

  void backtrace(int index, int n) {
    if (index == n + 1) {
      ans++;
      return;
    }
    // 从选择列表中选择
    for (auto& x : match[index]) {
      if (!vis[x]) {
        vis[x] = true;
        backtrace(index + 1, n);
        vis[x] = false;
      }
    }
  }

 public:
  int countArrangement(int n) {
    vis.resize(n + 1);
    match.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i % j == 0 || j % i == 0) {
          match[i].push_back(j);
        }
      }
    }
    backtrace(1, n);
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
