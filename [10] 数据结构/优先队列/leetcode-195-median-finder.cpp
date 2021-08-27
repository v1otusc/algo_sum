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
 * 使用两个堆，大根堆和小根堆
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class MedianFinder {
 private:
  // 大顶堆，记录比中位数小的数字
  priority_queue<int, vector<int>, less<int>> queMin;
  // 小顶堆，记录比中位数大的数字
  priority_queue<int, vector<int>, greater<int>> queMax;

 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    // 优先 push 进大顶堆
    // 如果要添加的数比大顶堆最大值小
    if(queMin.empty() || num <= queMin.top()) {
      queMin.push(num);
      if(queMax.size() + 1 < queMin.size()) {
        queMax.push(queMin.top());
        queMin.pop();
      }
    } else {
      queMax.push(num);
      if(queMax.size() > queMin.size()) {
        queMin.push(queMax.top());
        queMax.pop();
      }
    }
  }

  double findMedian() {
    // 优先 push 进大顶堆，queMin.size() >= queMax.size()
    if(queMin.size() > queMax.size()) {
      return queMin.top();
    }
    return (queMin.top() + queMax.top()) / 2.0;
  }
};

int main(int argc, char const* argv[]) { return 0; }