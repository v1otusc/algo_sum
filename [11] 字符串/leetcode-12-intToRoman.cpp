/*
 * @Description:
 *
 * 将整数转化为罗马数字
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
 *
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

// 不要使用 map ,否则会自动排序
const pair<int, string> valueSymbols[] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
    {5, "V"},    {4, "IV"},   {1, "I"},
};

class Solution {
 public:
  string intToRoman(int num) {
    string roman;
    for (const auto& valueSymbol : valueSymbols) {
      while (num >= valueSymbol.first) {
        num -= valueSymbol.first;
        roman += valueSymbol.second;
      }
      if (num == 0) {
        break;
      }
    }
    return roman;
  }
};

int main(int argc, char const* argv[]) { return 0; }
