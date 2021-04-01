/*
 * @Description:
 *
 * 给定两个十进制数，求他们二进制表示的汉明距离（不同位的个数）
 *
 * @输入示例：
 *
 * x = 1, y = 4
 *
 * @输出实例：
 *
 * 2
 *
 * @输入输出说明：
 *
 * 在这个样例中,1 的二进制是 0001,4 的二进制是 0100,一共有两位不同。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 对两个数进行按位异或者操作，统计有多少个 1 即可。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int hammingDistance(int x, int y) {
    int diff = x ^ y;
    int ans = 0;
    while (diff) {
      ans += (diff & 1);
      diff >>= 1;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
