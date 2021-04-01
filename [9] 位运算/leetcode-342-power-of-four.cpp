/*
 * @Description:
 *
 * 给定一个整数，判断它是否是 4 的次方
 *
 * @输入示例：
 *
 * 16
 *
 * @输出实例：
 *
 * true
 *
 * @输入输出说明：
 *
 * 输入是一个整数,输出是一个布尔值,表示判断结果。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 首先我们考虑一个数字是不是 2 的(整数)次方:如果一个数字 n 是 2
 的整数次方,那么它的二进制一定是  0...010...0 这样的形式；考虑到
 ;考虑到 n − 1 的二进制是 0...001...1,这两个数求按位与的结果一定是 0
 因此如果 n & (n - 1) 为 0,那么这个数是 2 的次方。

 如果这个数是 4 的次方，那二进制表示中 1 的位置必须是奇数位。
 可以把 n 和二进制 10101...101 做按位与，如果结果不是 0
 说明这个数是 4 的次方。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool isPowerOfFour(int n) {
    // int 类型共有 32 位
    return (n > 0) && !(n & (n - 1)) && (n & 1431655765);
  }
};

int main(int argc, char const* argv[]) { return 0; }
