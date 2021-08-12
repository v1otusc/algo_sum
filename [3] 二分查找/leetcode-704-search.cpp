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
 * 二分查找
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return -1;
    int ans = -1;
    int left = 0, right = n;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        ans = mid;
        break;
      }
      if (nums[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
