/*
 * @Description:
 *
 * 给定一个 0-1 字符串,求有多少非空子字符串的 0 和 1 数量相同。
 *
 * @输入示例：
 *
 * "00110011"
 *
 * @输出实例：
 *
 * 6
 *
 * @输入输出说明：
 *
 这个样例中, 6 个 0 和 1 数量相同的子字符串是
 ["0011","01","1100","10","0011","01"]。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 首先将字符串 s 按照 0 和 1 的连续段分组，存在
 counts 数组中，例如 s=00111011
 可以得到 counts={2,3,1,2}。

 这里 counts数组中两个相邻的数一定代表的是两种不同的字符。假设
 counts 数组中两个相邻的数字为 u 或者 v，它们对应着 u
 个 0 和 v 个 1，或者 u 个 1 和 v 个
 0。它们能组成的满足条件的子串数目为 min⁡{u,v}
 即一对相邻的数字对答案的贡献。

 我们只要遍历所有相邻的数对，求它们的贡献总和，即可得到答案。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int countBinarySubstrings(string s) {
    vector<int> counts;
    int ptr = 0;
    while (ptr < s.length()) {
      char c = s[ptr];
      int count = 0;
      while (ptr < s.length() && s[ptr] == c) {
        ++ptr;
        ++count;
      }
      counts.push_back(count);
    }
    int ans = 0;
    for (int i = 0; i < counts.size() - 1; ++i) {
      ans += min(counts[i], counts[i + 1]);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
