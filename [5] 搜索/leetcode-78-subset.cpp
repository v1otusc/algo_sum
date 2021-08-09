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
 * 使用回溯的 start 区别全排列
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
  vector<vector<int>> res;

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> path;
    // 首先 push 进空集
    backtrace(nums, 0, path);
    return res;
  }

  void backtrace(vector<int>& nums, int index, vector<int>& path) {
    res.push_back(path);
    // 以某个数开头的子集
    for (int i = index; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      backtrace(nums, i + 1, path);
      path.pop_back();
    }
    return;
  }
};

int main(int argc, char const* argv[]) { return 0; }