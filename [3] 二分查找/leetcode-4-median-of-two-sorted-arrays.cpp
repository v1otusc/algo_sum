/*
 * @Description:
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 num1 和 num2
 * 找出并返回这两个正序数组的 中位数
 *
 * @输入示例：
 *
 * num1 = [1,3] num2 = [2]
 *
 * @输出实例：
 *
 * 2.00000
 *
 * @输入输出说明：
 *
 * 合并数组 = [1,2,3], 中位数 2
 *
 * @限制条件：
 *
 * NULL
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
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double ans = 0;
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums1{1, 2};
  vector<int> nums2{3, 4};

  Solution s;
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;

  return 0;
}
