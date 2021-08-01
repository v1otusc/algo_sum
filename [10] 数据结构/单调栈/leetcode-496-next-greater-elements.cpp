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
 * 从下到上递增的栈，逆序遍历
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans(nums1.size());
    // 单调栈
    stack<int> stk;
    unordered_map<int, int> ump;
    for (int i = nums2.size() - 1; i >= 0; --i) {
      while (!stk.empty() && stk.top() <= nums2[i]) {
        stk.pop();
      }
      ump[nums2[i]] = (stk.empty()) ? -1 : stk.top();
      stk.push(nums2[i]);
    }
    for (int i = 0; i < nums1.size(); ++i) {
      ans[i] = ump.find(nums1[i]) != ump.end() ? ump[nums1[i]] : -1;
    }

    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
