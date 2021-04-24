/*
 * @Description:
 *
 * 给你一个二维数组 tasks ，用于表示 n​​​​​​ 项从 0
 * 到
 * n
 * - 1 编号的任务。其中 tasks[i] = [enqueueTimei, processingTimei] 意味着第
 * i​​​​​​​​​​ 项任务将会于 enqueueTimei
 * 时进入任务队列，需要 processingTimei 的时长完成执行。
 *
 * 现有一个单线程 CPU ，同一时间只能执行最多一项任务，该 CPU
 * 将会按照下述方式运行：
 *
 * - 如果 CPU 空闲，且任务队列中没有需要执行的任务，则 CPU 保持空闲状态。
 * - 如果 CPU 空闲，但任务队列中有需要执行的任务，则 CPU 将会选择 执行时间最短
 *
 的任务开始执行。如果多个任务具有同样的最短执行时间，则选择下标最小的任务开始执行。
 * - 一旦某项任务开始执行，CPU 在 执行完整个任务 前都不会停止。
 * - CPU 可以在完成一项任务后，立即开始执行一项新任务
 *
 * 返回 CPU 处理任务的顺序
 *
 * @输入示例：
 *
 * tasks = [[1,2],[2,4],[3,2],[4,1]]
 *
 * @输出实例：
 *
 * [0, 2, 3, 1]
 *
 * @输入输出说明：
 *
 * time = 1, 任务0进入任务队列，可执行任务项目 = {0}
 * 同样在 time = 1 ，空闲状态的 CPU 开始执行任务 0 ，可执行任务项 = {}
 * time = 2, 任务1进入任务队列，可执行任务项目 = {1}
 * time = 3, 任务2进入任务队列，可执行任务项目 = {1,2}
 * 同样在 time = 3 ，CPU 完成任务 0 并开始执行队列中用时最短的任务 2
 * ，可执行任务项 = {1}
 * time = 4, 任务3进入任务队列，可执行任务项目 = {1,3}
 * time = 5, CPU 完成任务2并开始执行队列中用时最短的任务3，可执行任务项 = {1}
 * time = 6, CPU 完成任务3并开始执行任务1，可执行任务项={}
 * time = 10, CPU 完成任务1并进入空闲状态
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 使用两个数据结构实现题目中描述的CPU操作
 * - 第一个数据结构负责按照时间顺序构造任务队列
 * - 第二个数据结构负责帮助CPU在所有任务中选择处理时间最小的执行
 *
 * - 第一个数据结构将数组 task 中的所有任务按照 enqueueTimei 升序排序即可。
 * - 第二个数据结构就是小根堆
 *
 * 还要维护一个时间戳变量
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
  using int_pair = pair<int, int>;
  using ll = long long;

 public:
  vector<int> getOrder(vector<vector<int>>& tasks) {
    int n = tasks.size();
    vector<int> indices(n);
    // 使得indices中的元素为 0 - n-1
    iota(indices.begin(), indices.end(), 0);
    // 捕获所有的引用，按照 enqueueTimei 从小到大排序
    sort(indices.begin(), indices.end(),
         [&](int i, int j) { return tasks[i][0] < tasks[j][0]; });

    vector<int> res;
    // 小根堆对 pair<int, int> 排序, 比较的是 pair 的第一个元素
    priority_queue<int_pair, vector<int_pair>, greater<int_pair>> q;
    ll timestamp = 0;
    // 用于遍历 indices 数组的指针
    int ptr = 0;

    // 每一次循环从小根堆中弹出一个，但是任务有可能先全部加入堆中
    for (int i = 0; i < n; ++i) {
      // 如果没有可以执行的任务，直接快进--快进的思路
      if (q.empty()) {
        timestamp = max(timestamp, (ll)tasks[indices[ptr]][0]);
      }
      // 将所有小于等于时间戳的任务放入优先队列
      while (ptr < n && (ll)tasks[indices[ptr]][0] <= timestamp) {
        q.emplace(tasks[indices[ptr]][1], indices[ptr]);
        ++ptr;
      }
      // 选择处理时间最小的任务
      int process = q.top().first;
      int index = q.top().second;
      timestamp += process;
      res.push_back(index);
      q.pop();
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
