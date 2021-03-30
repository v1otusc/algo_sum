/*
 * @Description:
 *
 * 判断一个数字是否是 3 的次方
 *
 * @输入示例：
 *
 * 27
 *
 * @输出实例：
 *
 * true
 *
 * @输入输出说明：
 *
 * 输入一个整数，输出一个布尔值
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 利用对数，设，如果 log_3(n) = m  是 3 的整数次方，那么 m 一定是整数
 * 换底公式 log_3(n) = log10(n) / log10(3)
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool isPowerOfThree(int n) {
    // 对浮点数取模
    return (fmod(log10(n) / log10(3), 1) == 0);
  }
};

int main(int argc, char const* argv[]) { return 0; }