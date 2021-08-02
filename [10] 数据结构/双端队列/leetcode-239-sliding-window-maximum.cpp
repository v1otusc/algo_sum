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
 private:
  class MyQueue {  //单调队列（从大到小）
   public:
    deque<int> que;  // 使用deque来实现单调队列
    // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
    // 同时pop之前判断队列当前是否为空。
    void pop(int value) {
      if (!que.empty() && value == que.front()) {
        que.pop_front();
      }
    }
    // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
    // 这样就保持了队列里的数值是单调从大到小的了。
    void push(int value) {
      while (!que.empty() && value > que.back()) {
        que.pop_back();
      }
      que.push_back(value);
    }
    // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
    int front() { return que.front(); }
  };

 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MyQueue que;
    vector<int> result;
    if (nums.size() == 0 || k == 0) return result;
    for (int i = 0; i < k; i++) {  // 先将前k的元素放进队列
      que.push(nums[i]);
    }
    result.push_back(que.front());  // result 记录前k的元素的最大值
    for (int i = k; i < nums.size(); i++) {
      que.pop(nums[i - k]);           // 滑动窗口移除最前面元素
      que.push(nums[i]);              // 滑动窗口前加入最后面的元素
      result.push_back(que.front());  // 记录对应的最大值
    }
    return result;
  }
};

int main(int argc, char const* argv[]) { return 0; }
