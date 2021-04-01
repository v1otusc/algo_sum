/*
 * @Description:
 *
 给定一个整数数组,这个数组里只有一个数次出现了一次,其余数字出现了两次,求这个只
 出现一次的数字。
 *
 * @输入示例：
 *
 * [4, 1, 2, 1, 2]
 *
 * @输出实例：
 *
 * 4
 *
 * @输入输出说明：
 *
 * 输入是一个一维整数数组,输出是该数组内的一个整数。
 *
 * @限制条件：
 *
 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 *
 * @题目思路：
 *
 我们可以利用 x ∧ x = 0 和 x ∧ 0 = x
 的特点，将数组内所有的数字进行按位异或。出现两次
 的所有数字按位异或的结果是 0， 0与出现一次的数字异或可以得到这个数字本身。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (const int& num : nums) {
      // 根据异或运算的交换律
      ans ^= num;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }