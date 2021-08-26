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
  int numRescueBoats(vector<int>& people, int limit) {
    int l = 0, r = people.size() - 1;
    sort(people.begin(), people.end());
    int ans = 0;
    while (l <= r) {
      if(people[l] + people[r] > limit) {
        r--;
      } else {
        r--;
        l++;
      }
      ans++;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
