/*
 * @Description:
 *
 * 给定一个只包含加减和乘法的数学表达式，求通过加括号可以得到多少种不同的结果
 *
 * @输入示例：
 *
 * 2-1-1
 *
 * @输出实例：
 *
 * [0, 2]
 *
 * @输入输出说明：
 *
 * 输入是一个字符串,表示数学表达式;输出是一个数组,存储所有不同的加括号结果。
 *
 * @限制条件：
 *
 * 在这个样例中,有两种加括号结果:((2-1)-1) = 0 和 (2-(1-1)) = 2。
 *
 * @题目思路：
 *
 * 利用分治思想，我们可以把加括号转化为，对于每一个运算符号，先执行处理两侧的数学表达式
 * 再处理此运算符号。
 *
 * 注意边界情况，即字符串内无运算符号，只有数字
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static vector<int> diffWaysToCompute(string input) {
    vector<int> ways;
    for (int i = 0; i < input.length(); ++i) {
      char c = input[i];
      if (c == '+' || c == '-' || c == '*') {
        // 第二个可选参数为长度
        vector<int> left = diffWaysToCompute(input.substr(0, i));
        vector<int> right = diffWaysToCompute(input.substr(i + 1));
        for (auto &l : left) {
          for (auto &r : right) {
            switch (c) {
              case '+':
                ways.push_back(l + r);
                break;
              case '-':
                ways.push_back(l - r);
                break;
              case '*':
                ways.push_back(l * r);
                break;
            }
          }
        }
      }
    }
    // 特殊情况字符串内无运算符号，只有数字
    if (ways.empty()) {
      ways.push_back(stoi(input));
    }
    return ways;
  }
};

int main(int argc, char const *argv[]) { return 0; }