/*
 * @Description:
 *
 * 给定一个整数数组和一个滑动窗口的大小
 * 求在这个窗口的滑动过程中，每个时刻包含的最大值
 *
 * @输入示例：
 *
 * nums = [1, 3, -1, -3, 5, 3, 6, 7]
 * k = 3
 *
 * @输出实例：
 *
 * [3, 3, 5, 5, 6, 7]
 *
 * @输入输出说明：
 *
 Window position
 -------------------------
 [1 3 -1] -3 5 3 6 7
 1 [3 -1 -3] 5 3 6 7
 1 3 [-1 -3 5] 3 6 7
 1 3 -1 [-3 5 3] 6 7
 1 3 -1 -3 [5 3 6] 7
 1 3 -1 -3 5 [3 6 7]
 Max
 -----
 3
 3
 5
 5
 6
 7
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 使用 deque 进行操作，！队列中的元素为数组的索引：
 每当向右移动时,把窗口左端的值从队列左端剔除,把队列
 右边小于窗口右端的值全部剔除。这样双端队列的最左端永远是当前窗口内的最大值。
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
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // 储存元素为数组的索引
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
      // 每当向右边移动时，把窗口左端的值从队列左端剔除，注意比较条件，不满足不能剔除
      if (!dq.empty() && (i - k) == dq.front()) {
        dq.pop_front();
      }

      // 把队列右边小于窗口右端的值全剔除，这样就能保证最左端为当前窗口内的最大值
      while (!dq.empty() && nums[dq.back()] < nums[i]) {
        dq.pop_back();
      }

      dq.push_back(i);

      // 至少向右移动了一个窗口
      if (i >= k - 1) {
        ans.push_back(nums[dq.front()]);
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
