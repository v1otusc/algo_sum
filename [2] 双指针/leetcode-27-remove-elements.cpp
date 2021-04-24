/*
 * @Description:
 *
 * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val
 * 的元素，并返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。
 * 元素的顺序可以改变。**你不需要考虑数组中超出新长度后面的元素。**
 *
 * @输入示例：
 *
 * nums = [0,1,2,2,3,0,4,2], val = 2
 *
 * @输出实例：
 *
 * 5, nums = [0,1,3,0,4]
 *
 * @输入输出说明：
 *
 * NULL
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 使用快慢指针
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int left = 0;
    int right = 0;
    for (; right < nums.size(); ++right) {
      if(nums[right] != val) {
        nums[left] = nums[right];
        left++;
      }
    }
    return left;
  }
};

int main(int argc, char const* argv[]) { return 0; }
