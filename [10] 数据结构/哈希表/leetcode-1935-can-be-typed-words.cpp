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
  int canBeTypedWords(string text, string brokenLetters) {
    unordered_set<char> s;
    for (auto& ch : brokenLetters) {
      s.insert(ch);
    }
    bool flag = true;
    int res = 0;
    for (char& ch : text) {
      if (ch == ' ') {
        if (flag) {
          res++;
        }
        // else
        flag = true;
      } else if (s.count(ch)) {
        flag = false;
      }
    }
    if (flag) {
      res++;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
