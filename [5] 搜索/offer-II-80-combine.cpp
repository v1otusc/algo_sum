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
  vector<vector<int>> ans;
  vector<int> path;
  void backtrace(int index, int k, const int n) {
    if (k == 0) {
      ans.push_back(path);
      return;
    }
    for (int i = index; i <= n; ++i) {
      path.push_back(i);
      backtrace(i + 1, k - 1, n);
      path.pop_back();
    }
    return;
  }

 public:
  vector<vector<int>> combine(int n, int k) {
    backtrace(1, k, n);
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
