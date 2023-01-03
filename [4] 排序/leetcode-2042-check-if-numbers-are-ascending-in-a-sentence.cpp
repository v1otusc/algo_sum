/*
 * @Description:
 *
 * 给定一个 string 检查其中的数字是不是严格递增的
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
  bool areNumbersAscending(string s) {
    int pre = 0, pos = 0;
    while (pos < s.size()) {
      if(isdigit(s[pos])){
        int cur = 0;
        while(pos < s.size() && isdigit(s[pos])) {
          cur = cur * 10 + s[pos] - '0';
          pos++;
        }
        if(cur <= pre) {
          return false;
        }
        pre = cur;
      } else {
        pos++;
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) {
  string s = "hello world 5 x 5";
  Solution sol;
  cout << sol.areNumbersAscending(s);
  return 0;
}