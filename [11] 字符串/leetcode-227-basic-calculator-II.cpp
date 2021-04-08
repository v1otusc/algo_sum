/*
 * @Description:
 *
 * 给定一个包含加减乘除整数运算的字符串,求其运算结果,只保留整数。
 *
 * @输入示例：
 *
 * "3+5 / 2"
 *
 * @输出实例：
 *
 * 5
 *
 * @输入输出说明：
 *
 * 在这个样例中,因为除法的优先度高于加法,所以结果是 5 而非 4。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 如果我们在字符串左边加上一个加号,可以证明其并不改变运算结果,且字符串可以分割成
 多个 <一个运算符,一个数字>
 对子的形式;这样一来我们就可以从左往右处理了。由于乘除的
 优先级高于加减,因此我们需要使用一个中间变量来存储高优先度的运算结果。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int calculate(string s) {
    int i = 0;
    return parseExpr(s, i);
  }

  // 辅函数--parse 从位置 i 开始的一个数字
  // 注意 i 也要传引用
  long parseNum(const string& s, int& i) {
    long n = 0;
    while (i < s.length() && isdigit(s[i])) {
      n = 10 * n + (s[i++] - '0');
    }
    return n;
  }

  // 辅函数--parse 从位置 i 开始的剩余字符串
  // 注意 i 也要传引用
  long parseExpr(const string& s, int& i) {
    char op = '+';
    long left = 0;
    long right = 0;
    while (i < s.length()) {
      if (s[i] != ' ') {
        long n = parseNum(s, i);
        switch (op) {
          case '+':
            left += right;
            right = n;
            break;
          case '-':
            left += right;
            right = -n;
            break;
          case '*':
            right *= n;
            break;
          case '/':
            right /= n;
            break;
          default:
            break;
        }
        if (i < s.length()) {
          op = s[i];
        }
      }
      ++i;
    }
    return left + right;
  }
};

int main(int argc, char const* argv[]) { return 0; }
