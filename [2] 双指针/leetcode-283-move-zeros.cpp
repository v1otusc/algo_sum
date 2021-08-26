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
 * 左指针左边都是非零
 * 右指针左边直到左指针处都是非零
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    if (nums.size() == 0) return;
    int left = 0, right = 0;
    while (right < nums.size()) {
      if (nums[right]) {
        swap(nums[left], nums[right]);
        left++;
      }
      right++;
    }
  }
};

int main(int argc, char const* argv[]) { return 0; }