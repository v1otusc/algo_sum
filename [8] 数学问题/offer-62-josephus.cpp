/*
 * @Description:
 *
 * 0,1,···,n-1 这 n 个数字排成一个圆圈，从数字 0 开始，每次从这个圆圈里删除第 m
 * 个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。
 *
 * @输入示例：
 *
 * n = 5, m = 3
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 例如，0、1、2、3、4这 5 个数字组成一个圆圈，从数字 0 开始每次删除第 3
 * 个数字，则删除的前 4 个数字依次是 2、0、4、1，因此最后剩下的数字是3。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 详见约瑟夫环问题的解法
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int lastRemaining(int n, int m) {
    // 最后剩下的人下标是 0
    int res = 0;
    for (int i = 2; i <= n; ++i) {
      // f(n, m) = (f(n - 1, m) + m) % n
      res = (res + m) % i;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  cout << s.lastRemaining(5, 3) << endl;
  return 0;
}
