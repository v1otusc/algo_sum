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
 * 二十六进制转十进制
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int ans = 0;
    long long multiple = 1;
    for (int i = columnTitle.size() - 1; i >= 0; --i) {
      int k = columnTitle[i] - 'A' + 1;
      ans += k * multiple;
      multiple *= 26;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  string input = "FXSHRXW";
  cout << s.titleToNumber(input) << endl;
  return 0;
}
