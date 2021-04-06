/*
 * @Description:
 *
 * 给定一个字符,求其有多少个回文子字符串。回文的定义是左右对称。
 *
 * @输入示例：
 *
 * "aaa"
 *
 * @输出实例：
 *
 * 6
 *
 * @输入输出说明：
 *
 * 六个回文子字符串分别是 ["a","a","a","aa","aa","aaa"]。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 我们可以从字符串的每个位置开始,向左向右延长,判断存在多少以当前位置为中轴的回文
 子字符串。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int countSubstrings(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); ++i) {
      // 奇数长度
      count += extendSubstrings(s, i, i);
      // 偶数长度
      count += extendSubstrings(s, i, i + 1);
    }
    return count;
  }

  int extendSubstrings(string s, int l, int r) {
    int count = 0;
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
      --l;
      ++r;
      ++count;
    }
    return count;
  }
};

int main(int argc, char const* argv[]) { return 0; }
