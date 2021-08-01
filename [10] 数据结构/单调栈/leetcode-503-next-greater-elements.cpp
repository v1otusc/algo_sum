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
 * 从下到上单调递减的栈，逆序遍历
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> stk;
    for (int i = 2 * n - 1; i >= 0; --i) {
      while (!stk.empty() && stk.top() <= nums[i % n]) {
        stk.pop();
      }
      ans[i % n] = (stk.empty()) ? -1 : stk.top();
      stk.push(nums[i % n]);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
