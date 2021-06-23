/*
 * @Description:
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 * @输入示例：
 *
 * strs = ["flower","flow","flight"]
 *
 * @输出实例：
 *
 * "fl"
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
  string longestCommonPrefix(vector<string>& strs) {
    string ans{""};
    if (strs.empty()) {
      return ans;
    }
    sort(strs.begin(), strs.end());
    string start = strs.front();
    string end = strs.back();
    int n = min(start.size(), end.size());
    int i = 0;
    for (; i < n && start[i] == end[i]; ++i)
      ;
    // 已经++i过了
    ans = start.substr(0, i);
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
