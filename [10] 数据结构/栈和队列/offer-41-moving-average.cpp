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

class MovingAverage {
  int size_;
  queue<int> window;

 public:
  /** Initialize your data structure here. */
  MovingAverage(int size) { size_ = size; }

  double average(queue<int>& vec) {
    double sum = 0;
    queue<int> q = vec;
    while (!q.empty()) {
      sum += q.front();
      q.pop();
    }

    return sum / vec.size();
  }

  double next(int val) {
    if (window.size() < size_) {
      window.push(val);
      return average(window);
    } else {
      window.pop();
      window.push(val);
      return average(window);
    }
  }
};

int main(int argc, char const* argv[]) { return 0; }
