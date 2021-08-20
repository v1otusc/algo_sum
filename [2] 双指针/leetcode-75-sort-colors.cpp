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
  void sortColors(vector<int>& nums) {
    if (nums.size() == 0 || nums.size() == 1) return;
    int left = 0, right = nums.size() - 1;
    int i = left;
    while (i >= left && i <= right) {
      if (nums[i] == 2) {
        swap(nums[i], nums[right]);
        right--;
      } else if (nums[i] == 0) {
        swap(nums[i], nums[left]);
        left++;
        if (i <= left) i = left;
      } else {
        i++;
      }
    }
  }
};

int main(int argc, char const* argv[]) { return 0; }