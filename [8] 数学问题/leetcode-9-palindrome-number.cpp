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
 * 不使用转化为字符串的方法
 *
 * @题目思路：
 *
 * 反转一半的数字，很巧妙的想法
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    if (x < 10) return true;

    int revert = 0;
    // 判断是否已经达到了中点
    while (x > revert) {
      revert = revert * 10 + x % 10;
      x /= 10;
    }
    // 包含位数是奇数和偶数的情况
    return x == revert || x == revert / 10;
  }
};

int main(int argc, char const* argv[]) { return 0; }
