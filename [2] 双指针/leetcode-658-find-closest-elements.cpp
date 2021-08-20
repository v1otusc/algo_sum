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
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int l = 0, r = arr.size() - 1;
    // 结果一定是连续的
    while(r - l >= k) {
      if (abs(arr[r] - x) < abs(arr[l] - x)) {
        l++;
      } else {
        r--;
      }
    }
    vector<int> ans;
    for (int i = l; i <= r; ++i) {
      ans.push_back(arr[i]);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
