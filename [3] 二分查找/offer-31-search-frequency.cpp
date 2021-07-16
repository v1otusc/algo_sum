/*
 * @Description:
 *
 * 查找 target 在排序数组中的出现频次
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
    int i = 0;
    int j = 0;
    i = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    j = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    return j - i;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{5, 7, 7, 8, 8, 10};
  Solution s;
  cout << s.search(nums, 8);
  return 0;
}
