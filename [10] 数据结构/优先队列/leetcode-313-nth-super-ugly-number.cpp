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

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    unordered_set<long> seen;
    priority_queue<long, vector<long>, greater<long>> heap;
    seen.insert(1);
    heap.push(1);
    int ugly = 1;
    for (int i = 0; i < n; ++i) {
      long cur = heap.top();
      heap.pop();
      ugly = (int)cur;
      for (int& prime : primes) {
        long next = cur * prime;
        // seen.insert() 竟然会返回一个 pair 第二个参数返回 insert 是否成功
        if (seen.insert(next).second) {
          heap.push(next);
        }
      }
    }
    return ugly;
  }
};

int main(int argc, char const* argv[]) { return 0; }
