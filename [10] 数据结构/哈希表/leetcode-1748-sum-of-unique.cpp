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
  int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> uset;
    int ans = 0;
    for (auto& num : nums) {
      uset[num]++;
    }
    for (auto& us : uset) {
      if (uset[us.first] == 1) {
        ans += us.first;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
