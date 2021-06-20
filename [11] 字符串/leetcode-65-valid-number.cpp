/*
 * @Description:
 *
 * 有效数字(按顺序)可以分为以下几个部分：
 * 1. 一个小数或者整数
 * 2.（可选）一个‘e’或者‘E’，后面跟着一个整数
 *
 * 小数（按顺序）可以分成以下几个部分：
 * 1.（可选）一个符号字符（'+' 或 '-'）
 * 2. 下述格式之一：
 * 2.1 至少一位数字，后面跟着一个点 '.'
 * 2.2 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
 * 2.3 一个点 '.' ，后面跟着至少一位数字
 *
 * 整数（按顺序）可以分成以下几个部分：
 * 1. (可选）一个符号字符（'+' 或 '-'）
 * 2. 至少一位数字
 *
 * @输入示例：
 *
 * ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1",
 * "53.5e93", "-123.456e789"]
 *
 * @输出实例：
 *
 * 上述结果均为 true
 *
 * @输入输出说明：
 *
 * NULL
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 直接遍历即可，处理情况不同，难在情况多，列举出来，枚举处理即可
 *
 * +/-一样处理
 * 1. 只有+/-一个字符，为无效字符
 * 2. +/-在开头，后面必须是数字或点
 * 3. +/-在末尾，return false
 * 4. +/-在中间，前面必须是 e 或者 E
 *
 * . 处理
 * 1. 不能有多个.
 * 2. .在开头，后面只能是数字
 * 3. .在中间，前面必须是数字或者+/-，后面必须是数字或e/E
 * 4. 在末尾，前面只能是数字
 * 5. e/E后面不能有.
 *
 * e/E一样处理
 * 1. e/E只能有一个
 * 2. 不能在开头或者结尾
 * 3. e在中间 后面必须是数字或+/-
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool unValidChar(const char c) {
    if (c == 'e' || c == 'E') return false;
    if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
      return true;
    }
    return false;
  }

  bool isNumber(string s) {
    // 初始化 unordered_map
    unordered_map<char, int> sign = {
        {'-', 0}, {'+', 0}, {'.', 0}, {'e', 0}, {'E', 0}};

    for (int i = 0; i < s.size(); ++i) {
      // This function only makes sense for unordered_multimap;
      if (sign.count(s[i])) {
        sign[s[i]]++;
      }

      if (unValidChar(s[i])) return false;

      if (s[i] == '+' || s[i] == '-') {
        // 只有+/-一个字符
        if (i == 0 && s.size() == 1) return false;
        // +/- 在开头，后面必须是数字或者点
        if (i == 0 && i < s.size() - 1 && !isdigit(s[i + 1]) && s[i+1] != '.') return false;
        // +/- 不可能在结尾
        if (i == s.size() - 1) return false;
        // 在中间，前面必须是 e/E
        if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') return false;
      }

      if (s[i] == '.') {
        // 不能有多个 .
        if (sign['.'] > 1) return false;
        // 只有一个.字符
        if (i == 0 && s.size() == 1) return false;
        // .在开头，后面只能是数字
        if (i == 0 && !isdigit(s[i + 1])) return false;
        // 在中间，前面必须是数字或+/-
        if (i > 0 && s[i - 1] != '-' && s[i - 1] != '+' && !isdigit(s[i - 1]))
          return false;
        // 在中间，后面必须是数字或者e/E
        if (i < s.size() - 1 && s[i + 1] != 'e' && s[i + 1] != 'E' &&
            !isdigit(s[i + 1]))
          return false;
        // 在结尾，前面必须是数字
        if (i == s.size() - 1 && !isdigit(s[i - 1])) return false;
        // e 或 E 后面不能有 .
        if (sign['e'] > 0 || sign['E'] > 0) return false;
      }

      if (s[i] == 'e' || s[i] == 'E') {
        // e 或者 E 只能有一个
        if (sign['e'] > 1 || sign['E'] > 1) return false;
        // e/E 不能放在开头或者结尾
        if (i == 0 || i == s.size() - 1) return false;
        // e 在中间，后面必须是数字或+/=
        if (i < s.size() - 1 && !isdigit(s[i + 1]) && s[i + 1] != '+' &&
            s[i + 1] != '-')
          return false;
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }
