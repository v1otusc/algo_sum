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
 * the sky is blue ->
 * ehe yks si eulb ->
 * blue is sky the
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    int k = 0;
    for (int i = 0; i < s.size(); ++i) {
      int j = i;
      // 跳过单词的前导空格
      while (j < s.size() && s[j] == ' ') ++j;
      if (j == s.size()) break;
      i = j;
      while (j < s.size() && s[j] != ' ') ++j;
      // 左闭右开
      reverse(s.begin() + i, s.begin() + j);
      // 赋值之后要给单词后补个空格作为单词之间的分隔符
      if (k) s[k++] = ' ';
      while (i < j) s[k++] = s[i++];
    }
    // 擦除多余的空格
    s.erase(s.begin() + k, s.end());
    reverse(s.begin(), s.end());
    return s;
  }
};

int main(int argc, char const* argv[]) { return 0; }