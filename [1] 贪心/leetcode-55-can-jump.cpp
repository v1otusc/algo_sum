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
 * 记录每个位置能否大于等于 n - 1
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int rightmost = 0;
    for (int i = 0; i < n; ++i) {
      if (i <= rightmost) {
        rightmost = max(rightmost, i + nums[i]);
        if (rightmost >= n - 1) {
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) { return 0; }
