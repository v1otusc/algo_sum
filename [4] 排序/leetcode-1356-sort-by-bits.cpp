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
 * 自己写 sort 函数规则
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

int get1(int x) {
  int ans = 0;
  while (x) {
    // 位运算技巧记住
    x &= (x - 1);
    ans++;
  }
  return ans;
}

struct Cmp {
  bool operator()(const int a, const int b) { 
    if(get1(a) == get1(b)) {
      return a < b;
    } else {
      return get1(a) < get1(b);
    }
  }
};

class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), Cmp());
    return arr;
  }
};

int main(int argc, char const* argv[]) { return 0; }
