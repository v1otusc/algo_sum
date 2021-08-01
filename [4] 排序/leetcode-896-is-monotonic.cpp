/*
 * @Description:
 *
 * 判断数组是否单调
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
  bool isMonotonic(vector<int>& nums) {
    bool inc = true;
    bool dec = true;
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      if (nums[i] > nums[i + 1]) {
        inc = false;
      }
      if (nums[i] < nums[i + 1]) {
        dec = false;
      }
    }
    return inc || dec;
  }
};

int main(int argc, char const* argv[]) { return 0; }
