/*
 * @Description:
 *
 * 设计一个数据结构,使得其能够快速查询给定数组中,任意两个位置间所有数字的和。
 *
 * @输入输出示例：
 *
 * 以下是数据结构的调用样例
 *
 * vector<int> nums{-2, 0, 3, -5, 2, -1};
 * NumArray* num_array = new NumArray(nums);
 * nums_array->sumRange(0, 2); // Result = -2+0+3 = 1
 * nums_array->sumRange(1, 5); // Result = 0+3-5+2-1 = -1
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
 * 对于一维的数组,我们可以使用前缀和来解决此类问题。先建立一个与数组 nums 长度相
 * 同的新数组 psum,表示 nums 每个位置之前前所有数字的和。如果我们需要获得位置 i
 * 和 j 之间的数字和。只需要计算 psum[j+1] - psum[i]
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class NumArray {
  vector<int> psum;

 public:
  NumArray(vector<int> nums) : psum(nums.size() + 1, 0) {
    // 对范围[first,last)内的元素逐个求累加和，放在result容器中。
    // 函数原型如下：
    // template <class InputIterator, class OutputIterator>
    // OutputIterator partial_sum(InputIterator first, InputIterator last,
    //                           OutputIterator result);
    // 这种写法真精
    partial_sum(nums.begin(), nums.end(), psum.begin() + 1);
  }
  int sumRange(int i, int j) { return psum[j + 1] - psum[i]; }
};

int main(int argc, char const* argv[]) { return 0; }
