/*
 * @Description:
 *
 * 给定一个整数 n, 返回 n! 结果尾数中零的数量
 *
 * @输入示例：
 *
 * 12
 *
 * @输出实例：
 *
 * 2
 *
 * @输入输出说明：
 *
 * 在这个样例中,12 != 479001600 的结尾有两个 0。
 *
 * @限制条件：
 *
 * 算法的时间复杂度为 O(nlogn)
 *
 * @题目思路：
 *
 每个尾部的 0 由 2 × 5 = 10
 而来,因此我们可以把阶乘的每一个元素拆成质数相乘,统计有多少个 2 和 5
 。明显的,质因子 2 的数量远多于质因子 5 的数量,因此我们可以只统计阶乘结果
 里面有多少个质因子 5
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int trailingZeroes(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
  }
};

int main(int argc, char const* argv[]) { return 0; }