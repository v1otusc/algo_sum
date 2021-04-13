/*
 * @Description:
 *
 * 给定一组非负整数
 * nums,重新排列每个数的顺序(每个数不可拆分)使之组成一个最大的整数
 *
 * @输入示例：
 *
 * nums = [10, 2]
 * nums = [3, 30, 34, 5, 9]
 *
 * @输出实例：
 *
 * "210"
 * "9534330"
 *
 * @输入输出说明：
 *
 * 输出结果可能非常大，所以需要返回一个字符串而不是整数
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 利用 lambda 表达式
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    string ans;
    vector<string> v;
    for (int num : nums) {
      v.push_back(to_string(num));
    }

    sort(v.begin(), v.end(),
         // 两个字符串先后组合大小降序排序
         [](const string& a, const string& b) { return a + b > b + a; });

    if (v[0] == "0") return "0";
    for (string t : v) {
      ans += t;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
