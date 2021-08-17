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
  bool checkRecord(string s) {
    int absents = 0, lates = 0;
    for (auto& c : s) {
      if (c == 'L') {
        lates++;
        if (lates == 3) return false;
      } else {
        lates = 0;
        if (c == 'A') {
          absents++;
          if (absents == 2) return false;
        }
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }
