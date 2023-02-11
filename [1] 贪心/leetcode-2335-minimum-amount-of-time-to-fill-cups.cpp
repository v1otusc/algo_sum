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
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int fillCups(vector<int>& amount) {
    sort(amount.begin(), amount.end());
    if (amount[2] > amount[1] + amount[0]) {
      return amount[2];
    }
    // 地板除，舍去
    return (accumulate(amount.begin(), amount.end(), 0) + 1) / 2;
  }
};

int main(int argc, char const* argv[]) { return 0; }
