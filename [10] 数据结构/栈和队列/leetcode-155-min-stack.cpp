/*
 * @Description:
 *
 设计一个最小栈,除了需要支持常规栈的操作外,还需要支持在 O(1)
 时间内查询栈内最小值的功能。
 *
 * @输入输出示例：
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // Returns -3.
 * minStack.pop();
 * minStack.top(); // Return 0
 * minStack.getMin(); // Returns -2.
 *
 * @输入输出说明：
 *
 * NULL
 *
 * @限制条件：
 *
 * NULL
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

class MinStack {
 private:
  stack<int> s;
  stack<int> min_s;

 public:
  MinStack() {}

  void push(int x) {
    s.push(x);
    if (min_s.empty() || min_s.top() >= x) {
      min_s.push(x);
    }
  }

  int top() { return s.top(); }

  void pop() {
    if (!min_s.empty() && min_s.top() == s.top()) {
      min_s.pop();
    }
    s.pop();
  }

  int getMin() { return min_s.top(); }
};

int main(int argc, char const* argv[]) { return 0; }
