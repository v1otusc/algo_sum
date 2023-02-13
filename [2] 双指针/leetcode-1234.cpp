/*
 * @Description:
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
 * 同向双指针
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int idx(char c) { return c - 'A'; }

  int balancedString(string s) {
    int n = s.length();
    int m = n / 4;
    vector<int> cnt(26);

    for (size_t i = 0; i < n; i++) {
      cnt[idx(s[i])]++;
    }
    if (cnt[idx('Q')] == m && cnt[idx('W')] == m && cnt[idx('R')] == m &&
        cnt[idx('E')] == m) {
      return 0;
    }

    int ans = n;
    int l = 0;
    for (int r = 0; r < n; ++r) {
      --cnt[idx(s[r])];
      while (cnt[idx('Q')] <= m && cnt[idx('W')] <= m && cnt[idx('R')] <= m &&
             cnt[idx('E')] <= m) {
        ans = min(ans, r - l + 1);
        ++cnt[idx(s[l++])];
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
