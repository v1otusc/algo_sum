/*
 * @Description:
 *
 * 从相邻元素中还原数组
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
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    unordered_map<int, vector<int>> mp;
    for (auto& adjacentPair : adjacentPairs) {
      mp[adjacentPair[0]].push_back(adjacentPair[1]);
      mp[adjacentPair[1]].push_back(adjacentPair[0]);
    }
    int n = mp.size();
    vector<int> ans(n);
    // 如果仅有一个相邻元素，说明是首元素或者末尾元素
    for (auto m : mp) {
      if (m.second.size() == 1) {
        ans[0] = m.first;
        break;
      }
    }
    // 然后就可以恢复了
    ans[1] = mp[ans[0]][0];
    for (int i = 2; i < n; ++i) {
      auto adj = mp[ans[i - 1]];
      ans[i] = (ans[i - 2] == adj[0]) ? adj[1] : adj[0];
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> adjacentPairs{{2, 1}, {3, 4}, {3, 2}};
  Solution s;
  vector<int> ret;
  ret = s.restoreArray(adjacentPairs);
  for (auto& r : ret) {
    cout << r << endl;
  }
  return 0;
}
