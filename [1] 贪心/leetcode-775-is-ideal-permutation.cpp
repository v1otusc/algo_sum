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
 * 局部倒置也是全局倒置，因此只要没有非局部倒置就是可以的
 * 非局部倒置，就是满足 j > i + 1, 且 num[i] > nums[j]
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool isIdealPermutation(vector<int>& nums) {
    int n = nums.size();
    int min_ = n;
    // 只记录 min_ 大大降低复杂度
    for (int i = n - 1; i >= 2; --i) {
      min_ = min(min_, nums[i]);
      if (nums[i - 2] > min_) return false;
    }
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }