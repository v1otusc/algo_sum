/*
 * @Description:
 *
 单调栈通过维持栈内值的单调递增(递减)性,在整体 O(n) 的时间内处理需要大小比较的
 问题。

 给定每天的温度，求**对于每一天**需要等几天才能等到更暖和的一天。如果该天之后不存在
 更暖和的天气,则记为 0。
 *
 * @输入示例：
 *
 * [73, 74, 75, 71, 69, 72, 76, 73]
 *
 * @输出实例：
 *
 * [1, 1, 4, 2, 1, 1, 0, 0]
 *
 * @输入输出说明：
 *
 * 输入是一个一维整数数组,输出是同样长度的整数数组,表示对于每天需要等待多少天。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 维持一个单调递减的栈，表示每天的温度，但是为了方便计算天数差，存放位置(即日期)而非温度本身
 我们从左向右遍历温度数组,对于每个日期 p,如果 p 的温度比栈顶存储位置 q
 的温度高,则我们取出 q,并记录 q 需要等待的天数为 p − q;我们重复这一过程
 直到 p 的温度小于等于栈顶存储位置的温度(或空栈)时,我们将 p
 插入栈顶,然后考虑下一天。在这个过程中,栈内数组永远保持单调递减,避免了使用排序进行比较。最后若栈内剩余一些日
 期，说明他们之后都没有出现更暖和的日期
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n);
    stack<int> indices;
    for (int i = 0; i < n; ++i) {
      while (!indices.empty()) {
        int pre_index = indices.top();
        if (temperatures[i] <= temperatures[pre_index]) {
          break;
        }
        indices.pop();
        ans[pre_index] = i - pre_index;
      }
      indices.push(i);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
