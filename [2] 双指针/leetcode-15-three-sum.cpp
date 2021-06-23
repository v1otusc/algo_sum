/*
 * @Description:
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得
 * a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
 *
 * @输入示例：
 *
 * nums = [-1,0,1,2,-1,-4]
 *
 * @输出实例：
 *
 * [[-1,-1,2],[-1,0,1]]
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
 * 排序
 * 首先固定一个数，然后对剩下的数字双指针滑动
 * 如果nums[i] > 0 因为已经拍好序，所以后面不可能有三个数相加等于 0
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
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    // 考虑特殊情况
    if (nums.size() < 3) return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      // 剪枝,必不可能
      if (nums[i] > 0) return ans;
      // 如果此数已选过，跳过
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int l = i + 1;
      int r = nums.size() - 1;
      while (l < r) {
        if (nums[r] + nums[l] > -nums[i]) {
          r--;
        } else if (nums[r] + nums[l] < -nums[i]) {
          l++;
        } else {
          ans.push_back(vector<int>{nums[i], nums[l], nums[r]});
          l++;
          r--;
          // 去重：第二个数和第三个数也不重复
          // 例如：[-4, 1, 1,1, 2, 3, 3, 3] i=0, l=1, r=5
          while (l < r && nums[l] == nums[l - 1]) l++;
          while (l < r && nums[r] == nums[r + 1]) r--;
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
