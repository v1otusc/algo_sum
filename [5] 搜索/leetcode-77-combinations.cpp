/*
 * @Description:
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 *
 * @输入示例：
 *
 *  n = 4, k = 2
 *
 * @输出实例：
 *
 * [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
   ]
 *
 * @输入输出说明：
 *
 * NULL
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 类似于排列问题,我们也可以进行回溯。排列回溯的是交换的位置,而组合回溯的是否把当前的数字加入结果中。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> comb(k, 0);
    int count = 0;
    backtracking(ans, comb, count, 1, n, k);
    return ans;
  }

  static void backtracking(vector<vector<int>> &ans, vector<int> &comb,
                           int &count, int pos, int n, int k) {
    if (count == k) {
      ans.push_back(comb);
      return;
    } else {
      for (int i = pos; i <= n; ++i) {
        comb[count++] = i;
        // 按照引用传递状态
        backtracking(ans, comb, count, i + 1, n, k);
        // 所有状态在递归完成后回改；
        --count;
      }
    }
  }
};

int main(int argc, char const *argv[]) {
  int n = 4;
  int k = 2;

  vector<vector<int>> ans = Solution::combine(n, k);
  for (auto &i : ans) {
    for (auto &j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
  return 0;
}
