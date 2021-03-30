/*
 * @Description:
 *
 * 给定一个十进制数，求它在七进制下的表示
 *
 * @输入示例：
 *
 * 100
 *
 * @输出实例：
 *
 * “202”
 *
 * @输入输出说明：
 *
 * 输入一个整数,输出一个字符串,表示其七进制。
 *
 *
 * @限制条件：
 *
 * 在这个样例中,100 的七进制表示法来源于 100 = 2 * 49 + 0 * 7 + 2 * 1。
 *
 * @题目思路：
 *
 * 进制转换类型的题,通常是利用除法和取模(mod)来进行计算,同时也要注意一些细节,如
 * 负数和零。如果输出是数字类型而非字符串,则也需要考虑是否会超出整数上下界。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static string convertToBase7(int num) {
    if (num == 0) return "0";
    // 考虑负数
    bool is_negative = (num < 0);
    if (is_negative) num = -num;
    string ans;
    while (num) {
      int a = num / 7;
      int b = num % 7;
      ans = to_string(b) + ans;
      num = a;
    }
    return is_negative ? ("-" + ans) : ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
