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

#define ll long long
class Solution {
 public:
  vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
    // 计算每个位置对应的颜色和改变量并用哈希表存储
    // 其中 k 表示 [k, k+1) 的颜色
    unordered_map<int, ll> colors;
    for (auto& segment : segments) {
      int l = segment[0];
      int r = segment[1];
      int c = segment[2];
      // 记录变化值，在闭区间增加，在开区间减少，简直太巧妙了
      colors[l] += c;
      colors[r] -= c;
    }
    vector<vector<ll>> ans;
    ll last = 0, col = 0;
    for (auto& color : colors) {
      if (col != 0) ans.push_back({last, color.first, col});
      last = color.first;
      col += color.second;
    }
  }
};

int main(int argc, char const* argv[]) { return 0; }
