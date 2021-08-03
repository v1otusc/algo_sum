/*
 * @Description:
 *
 * 找出升序数组中的非升序连续子数组
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
  int findUnsortedSubarray(vector<int>& nums) {
    if (is_sorted(nums.begin(), nums.end())) {
      return 0;
    }
    vector<int> nums_sorted(nums);
    sort(nums_sorted.begin(), nums_sorted.end());
    int left = 0, right = nums.size() - 1;
    while (nums[left] == nums_sorted[left]) {
      left++;
    }
    while (nums[right] == nums_sorted[right]) {
      right--;
    }
    return right - left + 1;
  }
};

int main(int argc, char const* argv[]) { return 0; }
