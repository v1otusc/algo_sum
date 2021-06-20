/*
 * @Description:
 *
 * 对于给定的整数 n, 如果 n 的 k(k>=2) 进制数的所有的位数全为 1，则称k(k>=2)
 * 是n的一个好进制。
 *
 * 以字符串的形式给出 n, 以字符串的形式返回 n 的最小好进制。
 *
 * @输入示例：
 *
 * "13"
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 13 的三进制是 111
 *
 * @限制条件：
 *
 * n的取值范围是 [3, 10^18]
 *
 * @题目思路：
 *
 * 数学方法
 * https://leetcode-cn.com/problems/smallest-good-base/solution/shu-xue-fang-fa-fen-xi-dai-ma-by-zerotrac/
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

#define ll long long

class Solution {
 public:
  string smallestGoodBase(string N) {
    ll n = stol(N);
    // 位数为 s + 1，满足 s>=1
    // 返回 s = 1 的情况；
    ll ans = n - 1;
    // 下面是返回 s >= 2 的情况
    for (int s = 59; s >= 2; --s) {
      // k 为 n^(1/s) 的整数部分
      int k = pow(n, 1.0 / s);
      if (k > 1) {            // 判断 k 是否是一个合法的进制
        ll sum = 1, mul = 1;  // 计算 (11...11)k 对应的十进制值
        for (int i = 1; i <= s; ++i) {
          mul *= k;
          sum += mul;
        }
        if (sum == n) {
          ans = k;
          break;
        }
      }
    }
    return to_string(ans);
  }
};

int main(int argc, char const* argv[]) {
  string n;
  Solution s;
  while (cin >> n) {
    cout << s.smallestGoodBase(n) << endl;
  }
}