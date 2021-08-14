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
  string toHex(int num) {
    if (num == 0) return "0";
    string hex = "0123456789abcdef";
    string res;
    unsigned int n = num;
    while (n) {
      res += hex[n % 16];
      n /= 16;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
