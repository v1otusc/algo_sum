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
  int unhappyFriends(int n, vector<vector<int>>& preferences,
                     vector<vector<int>>& pairs) {
    // 首先配对
    unordered_map<int, int> cp;
    for (auto& pair : pairs) {
      cp[pair[0]] = pair[1];
      cp[pair[1]] = pair[0];
    }

    int res = 0;

    for (int i = 0; i < n; ++i) {
      int x = i, y = cp[i];
      // 找到顺位
      int y_pos = find(preferences[x].begin(), preferences[x].end(), y) -
                  preferences[x].begin();
      // j 的顺位都是小于 y 的位置，即是说 x 与 u 的亲近程度大于 x 与 y 的亲近程度
      for (int j = 0; j < y_pos; ++j) {
        int u = preferences[i][j], v = cp[u];
        // x 在 u 的顺位
        int t1 = find(preferences[u].begin(), preferences[u].end(), x) -
                 preferences[u].begin();
        // v 在 u 中的顺位
        int t2 = find(preferences[u].begin(), preferences[u].end(), v) -
                 preferences[u].begin();
        // 表示 u 与 x 的亲近程度大于 u 与 x 的亲近程度
        if (t1 < t2) {
          res++;
          break;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }