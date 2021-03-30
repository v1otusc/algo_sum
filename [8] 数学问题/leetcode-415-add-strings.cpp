/*
 * @Description:
 *
 * 给定两个由数字组成的字符串，求他们相加的结果
 *
 * @输入示例：
 *
 * num1 = "99"
 * num2 = "1"
 *
 * @输出实例：
 *
 * "100"
 *
 * @输入输出说明：
 *
 * 输入是两个字符串,输出是一个整数,表示输入的数字和。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 因为相加运算是从后往前进行的,所以可以先翻转字符串,再逐位计算。这种类型的题考察
 的是细节,如进位、位数差等等。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  string addStrings(string num1, string num2) {
    string output("");
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int onelen = num1.length();
    int twolen = num2.length();
    int addbit = 0;
    // 始终使 num2 的长度较小
    if (onelen <= twolen) {
      swap(num1, num2);
      swap(onelen, twolen);
    }

    for (int i = 0; i < twolen; ++i) {
      int cur_sum = (num1[i] - '0') + (num2[i] - '0') + addbit;
      output += to_string(cur_sum % 10);
      addbit = (cur_sum >= 10) ? 1 : 0;
    }
    for (int i = twolen; i < onelen; ++i) {
      int cur_sum = (num1[i] - '0') + addbit;
      output += to_string(cur_sum % 10);
      addbit = (cur_sum >= 10) ? 1 : 0;
    }
    if (addbit == 1) {
      output += '1';
    }
    reverse(output.begin(), output.end());
    return output;
  }
};

int main(int argc, char const* argv[]) { return 0; }