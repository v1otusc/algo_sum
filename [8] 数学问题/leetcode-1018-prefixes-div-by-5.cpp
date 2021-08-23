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
  vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> ans;
    // vector<int> pre;
    int pre = 0;
    for (auto& num : nums) {
      pre = (pre << 1) + num;
      // 只判断最后一位
      pre %= 10;
      ans.push_back(pre ==  0 || pre == 5);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
