/*
 * @Description:
 *
 * 请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32
 * 位有符号整数（类似 C/C++ 中的 atoi 函数）。
 *
 * @输入示例：
 *
 * s = "-42"
 *
 * @输出实例：
 *
 * -42
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
 * 官方题解是使用有限状态机
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int myAtoi(string s) {
    int res = 0;
    int sign = 1;
    int i = 0;
    int n = s.size();
    // 跳过之前的空格
    while (s[i] == ' ') {
      i++;
    }
    if (i < n && (s[i] == '+' || s[i] == '-')) {
      sign = (s[i] == '-') ? -1 : 1;
      // 位置++
      i++;
    }
    for (; i < n; ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
        // 即将溢出
        // INT_MAX == 2^31 - 1 ==
        // 2147483647，最后一位是 7，超过就溢出了。如果是负数，可以到-2147483648，统一处理设置为INT_MIN就好了
        // 很巧合，一个是 7 一个是 8
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (s[i] - '0' > 7))) {
          return (sign + 1) ? INT_MAX : INT_MIN;
        }
        res = res * 10 + (s[i] - '0');
      } else {
        break;
      }
    }
    return res * sign;
  }
};

int main(int argc, char const* argv[]) { return 0; }

/*       if (c = ' ' && (c - 'a' > 0 || ) {
        res = 0;
      } else if (c - '0' >= 0 && c - '0' < 9) {
        res += c - '0';
      } */
