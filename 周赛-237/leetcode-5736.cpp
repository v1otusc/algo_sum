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
 *   的任务开始执行。如果多个任务具有同样的最短执行时间，则选择下标最小的任务开始执行。
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
  vector<int> getOrder(vector<vector<int>>& tasks) {
    vector<int> res;
    
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
