/*
 * @Description:
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums
 * 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target
 * 相等？找出所有满足条件且不重复的四元组。
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
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    if (nums.size() < 4) {
      return ans;
    }

    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      // 太大了
      if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
        break;
      }
      // nums[i] 不够大
      if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) {
        continue;
      }
      for (int j = i + 1; j < n - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        // 太大了
        if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
          break;
        }
        // nums[j] 不够大
        if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) {
          continue;
        }
        int left = j + 1, right = n - 1;
        while (left < right) {
          int sum = nums[i] + nums[j] + nums[left] + nums[right];
          if (sum == target) {
            ans.push_back(
                vector<int>{nums[i], nums[j], nums[left], nums[right]});
            while (left < right && nums[left] == nums[left + 1]) {
              left++;
            }
            left++;
            while (left < right && nums[right] == nums[right - 1]) {
              right--;
            }
            right--;
          } else if (sum < target) {
            left++;
          } else {
            right--;
          }
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
