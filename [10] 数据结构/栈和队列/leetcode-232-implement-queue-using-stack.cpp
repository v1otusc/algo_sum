/*
 * @Description:
 *
 * 使用栈来实现队列
 *
 * @输入输出示例：
 *
 * MyQueue queue = new MyQueue();
 * queue.push(1);
 * queue.push(2);
 * queue.peek(); // 返回队列开头的元素 returns 1
 * queue.pop(); // returns 1
 * queue.empty(); // returns false
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
 * 我们可以使用两个栈来实现队列：
 * 因为需要得到先入先出的结果，所以必定要通过一个额外栈翻转一次数组。
 * 这个翻转过程既可以在插入时完成,也可以在取值时完成。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class MyQueue {
 private:
  stack<int> in, out;

 public:
  MyQueue();

  void push(int x) { in.push(x); }

  int peek() {
    in2out();
    return out.top();
  }

  int pop() {
    in2out();
    int x = out.top();
    out.pop();
    return x;
  }

  bool empty() { return in.empty() && out.empty(); }

  // 翻转数组
  void in2out() {
    if (out.empty()) {
      while (!in.empty()) {
        int x = in.top();
        in.pop();
        out.push(x);
      }
    }
  }
};

int main(int argc, char const* argv[]) { return 0; }
