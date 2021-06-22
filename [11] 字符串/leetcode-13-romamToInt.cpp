/*
 * @Description:
 *
 * 将罗马数字转换为整数
 *
 * @输入示例：
 *
 * "LVIII"
 *
 * @输出实例：
 *
 * 58
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
 private:
  unordered_map<char, int> symbolValues = {
      {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
      {'C', 100}, {'D', 500}, {'M', 1000},
  };

 public:
  int romanToInt(string s) {
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
      int value = symbolValues[s[i]];
      if (i < n - 1 && value < symbolValues[s[i + 1]]) {
        ans -= value;
      } else {
        ans += value;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
