/*
 * @Description:
 *
 * 判断两个字符串包含的字符是否完全相同
 *
 * @输入示例：
 *
 * s = "anagram"
 * t = "nagaram"
 *
 * @输出实例：
 *
 * true
 *
 * @输入输出说明：
 *
 * 输入两个字符串,输出一个布尔值,表示两个字符串是否满足条件。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 用数组统计两个数组中每个数字出现的频次，若频次相同，说明它们包含的字符串完全相同
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }

    vector<int> count(26, 0);
    for (int i = 0; i < s.length(); ++i) {
      ++count[s[i] - 'a'];
      --count[t[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if (count[i]) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }
