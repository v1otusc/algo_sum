/*
 * @Description:
 *
 * 一个人能看到他右边另一个人的条件是这两人之间的所有人都比他们两人矮
 * 请你返回一个长度为 n 的数组 answer ，其中 answer[i] 是第 i
 * 个人在他右侧队列中能看到的人数 。
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
 * heights 中所有数互不相同
 *
 * @题目思路：
 *
 * 对第 i
 * 个人来说，他能看到的人中，靠右的不能被靠左的挡住，所以这些人从左往右的高度必须是严格单调递增的。
 *
 * 逆序遍历，如果当前高度大于栈顶，则这个栈顶对其他再往前的人就看不到了，可以将其弹出
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> ans(n);
    stack<int> stk;
    // stk.push(INT_MAX);
    for (int i = n - 1; i >= 0; --i) {
      // 如果没有遇到比他高的人
      while (!stk.empty() && stk.top() < heights[i]) {
        ans[i]++;
        stk.pop();
      }
      // 这里非空，还能看到一个人(最后一个把别人遮住的人)
      ans[i] += (!stk.empty()) ? 1 : 0;
      stk.push(heights[i]);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
