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
  vector<int> path;
  vector<int> vis;
  vector<vector<int>> ans;

 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    vis.resize(n);
    sort(nums.begin(), nums.end());
    backtrace(nums, 0);
    return ans;
  }

  void backtrace(vector<int>& nums, int index) {
    if (index == nums.size()) {
      ans.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
        continue;
      }
      vis[i] = 1;
      path.push_back(nums[i]);
      backtrace(nums, index + 1);
      path.pop_back();
      vis[i] = 0;
    }
  }
};

int main(int argc, char const* argv[]) { return 0; }
