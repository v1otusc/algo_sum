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
 * 二元数组记数
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    vector<int> nums(100);
    int res = 0;
    for (auto& domi : dominoes) {
      int val = (domi[0] > domi[1]) ? (domi[0] * 10 + domi[1])
                                    : (domi[1] * 10 + domi[0]);
      res += nums[val];
      nums[val]++;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> dominoes = {{1, 2}, {2, 1}, {3, 4}, {4, 5}};
  Solution s;
  cout << s.numEquivDominoPairs(dominoes) << endl;
  return 0;
}
