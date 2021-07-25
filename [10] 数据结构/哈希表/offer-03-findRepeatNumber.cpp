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
 * 哈希表
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  unordered_set<int> uset;

 public:
  int findRepeatNumber(vector<int>& nums) {
    for (auto& n : nums) {
      if (uset.find(n) != uset.end()) {
        return n;
      } else {
        uset.insert(n);
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) { return 0; }
