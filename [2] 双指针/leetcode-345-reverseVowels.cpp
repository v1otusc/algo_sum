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
  bool isVowel(char& c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
        c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      return true;
    }
    return false;
  }

 public:
  string reverseVowels(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
      while (l < s.size() && !isVowel(s[l])) {
        ++l;
      }
      while (r > 0 && !isVowel(s[r])) {
        --r;
      }
      if (l < r) {
        swap(s[l], s[r]);
        ++l;
        --r;
      }
    }
    return s;
  }
};

int main(int argc, char const* argv[]) {
  string s = "hello";
  Solution sol;
  cout << sol.reverseVowels(s) << endl;
  return 0;
}