/*
 * @Description:
 *
 给定一个只由左右原括号、花括号和方括号组成的字符串，求这个字符串是否合法。
 合法的定义是每一个类型的左括号都有一个右括号一一对应，且括号内的字符串也满足此要求
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 *
 * @输入示例：
 *
 * {[]}()
 * ([)]
 *
 * @输出实例：
 *
 * true
 * false
 *
 * @输入输出说明：
 *
 * 输入是一个字符串,输出是一个布尔值,表示字符串是否合法。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 括号匹配是典型的使用栈来解决的问题。我们从左往右遍历,每当遇到左括号便放入栈内,
 遇到右括号则判断其和栈顶的括号是否是统一类型,是则从栈内取出左括号,否则说明字符串不
 合法。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> parsed;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
        parsed.push(s[i]);
      } else {
        // 碰到右括号
        // 但是栈里是空的
        if (parsed.empty()) {
          return false;
        }
        char c = parsed.top();
        if ((s[i] == ']' && c == '[') || (s[i] == '}' && c == '{') ||
            (s[i] == ')' && c == '(')) {
          parsed.pop();
        } else {
          return false;
        }
      }
    }
    return parsed.empty();
  }
};

int main(int argc, char const* argv[]) { return 0; }