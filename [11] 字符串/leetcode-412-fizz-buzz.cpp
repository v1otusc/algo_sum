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
  vector<string> fizzBuzz(int n) {
    vector<string> ans;
    for (int i = 1; i <= n; ++i) {
      if ((i % 3 == 0) && (i % 5 == 0)) {
        ans.push_back("FizzBuzz");
      } else if (i % 3 == 0) {
        ans.push_back("Fizz");
      } else if (i % 5 == 0) {
        ans.push_back("Buzz");
      } else {
        ans.push_back(to_string(i));
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }