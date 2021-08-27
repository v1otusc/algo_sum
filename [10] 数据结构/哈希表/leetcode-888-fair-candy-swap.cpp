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
 * 用哈希表快速找出某个数
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
    int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
    int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
    int delta = (sumA - sumB) / 2;
    unordered_set<int> uset;
    for (auto& a : aliceSizes) {
      uset.insert(a);
    }
    vector<int> res;
    for (auto& y : bobSizes) {
      if (uset.find(delta + y) != uset.end()) {
        res = vector<int>{delta + y, y};
        break;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }