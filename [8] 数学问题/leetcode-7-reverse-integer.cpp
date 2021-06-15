/*
 * @Description:
 *
 * 给你一个 32 位的有符号整数 x ，返回将 x
 * 中的数字部分反转后的结果。如果反转后整数超过 32 位的有符号整数的范围 [−2^31,
 * 2^31 − 1] ，就返回 0。假设环境不允许存储 64 位整数（有符号或无符号）。
 *
 * @输入示例：
 *
 * -123
 *
 * @输出实例：
 *
 * -321
 *
 * @输入输出说明：
 *
 * 注意翻转后证书可能超过 32 位
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 函数内的局部变量不会初始化为 0 的...
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    // 局部变量一定要初始化！
    long res = 0;
    while (x != 0) {
      res = res*10 + x % 10;
      x /= 10;
    }
    return (res > INT_MAX || res < INT_MIN) ? 0 : res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  cout << s.reverse(213) << endl;
  return 0;
}