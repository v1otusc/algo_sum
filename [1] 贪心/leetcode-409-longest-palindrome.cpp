/*
 * @Description:
 *
 * 利用给的字符构造最大回文串的长度
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
  int longestPalindrome(string s) {
    unordered_map<char, int> ump;
    for (auto& ch : s) {
      ump[ch]++;
    }
    int ans = 0;
    for (auto& p : ump) {
      int v = p.second;
      // 向下取整
      ans += v / 2 * 2;
      if (v % 2 == 1 && ans % 2 == 0) {
        ans++;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }