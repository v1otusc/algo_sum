/*
 * @Description:
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums
 * 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
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
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int best = 1e7;
    for (int i = 0; i < n - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int l = i + 1;
      int r = n - 1;
      while (l < r) {
        int sum = nums[i] + nums[r] + nums[l];
        if (sum == target) {
          return sum;
        }
        if (abs(sum - target) < abs(best - target)) {
          best = sum;
        }
        if (sum > target) {
          // 如果和大于 target, 移动 r 对应的指针
          int r0 = r - 1;
          // 直到 nums[r0] != nums[r]
          while (l < r0 && nums[r0] == nums[r]) {
            --r0;
          }
          r = r0;
        } else {
          // 如果和小于 target, 移动 l 对应的指针
          int l0 = l + 1;
          // 直到 nums[l0] != nums[l]
          while (l0 < r && nums[l0] == nums[l]) {
            ++l0;
          }
          l = l0;
        }
      }
    }
    return best;
  }
};

int main(int argc, char const* argv[]) { return 0; }
