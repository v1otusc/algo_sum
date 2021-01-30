/*
 * @Description:
 *
 * 给定一个增序的整数数组和一个值,查找该值第一次和最后一次出现的位置。
 *
 * @输入示例：
 *
 * nums = [5,7,7,8,8,10], target = 8
 *
 * @输出实例：
 *
 * [3,4]
 *
 * @输入输出说明：
 *
 * 输入是一个数组和一个值,输出为该值第一次出现的位置和最后一次出现的位置(从 0
 * 开始);如果不存在该值,则两个返回值都设为-1。
 *
 * @限制条件：
 *
 * 实现时间复杂度为 O(log n) 的算法
 *
 * @题目思路：
 *
 * 这道题可看作自己实现 C++ 中的 lower_bound 函数和 uppper_bound 函数
 * 这里是左闭右开的写法--最常见的写法
 *
 * lower_bound 函数 和 upper_bound 函数，在从小到大的排序数组中，
 *
 * lower_bound(begin,end,num)：
 * 从数组的 begin 位置到 end-1 位置二分查找第一个大于或等于 num
 * 的数字，找到返回该数字的地址，不存在则返回 end。
 * 通过返回的地址减去起始地址 begin,得到找到数字在数组中的下标。
 *
 * upper_bound(begin,end,num):
 * 从数组的 begin 位置到 end-1 位置二分查找第一个大于 num
 * 的数字，找到返回该数字的地址，不存在则返回 end。
 * 通过返回的地址减去起始地址 begin,得到找到数字在数组中的下标。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/[3] 二分查找/
 */

#include "bits/stdc++.h"

using namespace std;

int solution_upper_bound(vector<int>&, int);
int solution_lower_bound(vector<int>&, int);

class Solution {
 public:
  static vector<int> searchRange(vector<int>& nums, int target) {
    // 一定要考虑特殊情况
    if (nums.empty()) {
      return vector<int>{-1, -1};
    }
    int lower = solution_lower_bound(nums, target);
    // 根据 upper_bound 的返回值，这里减一位
    int upper = solution_upper_bound(nums, target) - 1;
    if (lower == nums.size() || nums[lower] != target) {
      return vector<int>{-1, -1};
    }
    return vector<int>{lower, upper};
  }
};

// 找出第一个大于 target 的数字
int solution_upper_bound(vector<int>& nums, int target) {
  // 左闭右开的写法，r 并不在取值范围之内
  int l = 0, r = nums.size(), mid;
  // **跳出循环的条件就是 l == r**
  while (l < r) {
    mid = (l + r) / 2;
    if (nums[mid] > target) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  // 左闭右开的写法
  return l;
}

// 找出第一个大于等于 target 的数字
int solution_lower_bound(vector<int>& nums, int target) {
  // 左闭右开的写法，r 并不在取值范围之内
  int l = 0, r = nums.size(), mid;
  // **跳出循环的条件就是 l == r**
  while (l < r) {
    mid = (l + r) / 2;
    if (nums[mid] >= target) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  // 左闭右开的写法
  return l;
}

int main(int argc, char const* argv[]) {
  vector<int> nums{5, 7, 7, 8, 10};
  int target = 8;
  vector<int> res(2, 0);

  res = Solution::searchRange(nums, target);

  for (auto i = res.begin(); i != res.end(); i++) {
    cout << *i << endl;
  }

  return 0;
}
