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
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    // 军人数量 —— 行数
    vector<pair<int, int>> power;
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; ++i) {
      int p = 0;
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          break;
        } else {
          p++;
        }
      }
      power.push_back(pair<int, int>(p, i));
    }
    sort(power.begin(), power.end());
    auto it = power.begin();
    auto end = it + k;
    vector<int> ans;
    for (; it < end; ++it) {
      ans.push_back(it->second);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> mat;
  mat = {{1, 1, 0, 0, 0},
         {1, 1, 1, 1, 0},
         {1, 0, 0, 0, 0},
         {1, 1, 0, 0, 0},
         {1, 1, 1, 1, 1}};
  int k = 3;
  Solution s;
  vector<int> ans = s.kWeakestRows(mat, k);
  for (auto a : ans) {
    cout << a << endl;
  }

  return 0;
}
