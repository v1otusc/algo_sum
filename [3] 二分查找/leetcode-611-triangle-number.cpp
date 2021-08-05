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
  int triangleNumber(vector<int>& nums) {
    int ans = 0;
    if (nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        // 因为有可能 k -j = 0 所以初始值一定要为 k = j;
        int k = j;
        int left = j + 1, right = nums.size() - 1;
        while (left <= right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] < nums[i] + nums[j]) {
            k = mid;
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        }
        ans += k - j;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
