/*
 * @Description:
 *
 * 给定一个字符串 s 和一个整数 k, 从字符串开头算起，每 2k 个字符反转前 k 个字符
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
  string reverseStr(string s, int k) {
    int n = s.length();
    for (int i = 0; i < n; i += 2 * k) {
      reverse(s.begin() + i, s.begin() + min(i + k, n));
    }
    return s;
  }
};

int main(int argc, char const* argv[]) { return 0; }
