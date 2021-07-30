/*
 * @Description:
 *
 * 最小未被占据椅子的编号
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
  int smallestChair(vector<vector<int>>& times, int targetFriend) {
    // 朋友的个数，同时也代表需要的椅子
    int n = times.size();
    // 达到的时刻 —— 朋友的编号
    vector<pair<int, int>> arrivals;
    // 离开的时刻 —— 朋友的编号
    vector<pair<int, int>> leavings;

    for (int i = 0; i < n; ++i) {
      arrivals.push_back(make_pair(times[i][0], i));
      leavings.push_back(make_pair(times[i][1], i));
    }
    // 需要排序，不能用哈希
    sort(arrivals.begin(), arrivals.end());
    sort(leavings.begin(), leavings.end());

    // 未被占据的椅子, 小顶堆
    priority_queue<int, vector<int>, greater<int>> available_chairs;
    // 初始时刻所有椅子都是 available
    for (int i = 0; i < n; ++i) {
      available_chairs.push(i);
    }
    // 每个人的编号 —— 椅子
    unordered_map<int, int> seats;
    // 开始模拟
    int j = 0;
    for (auto arrival : arrivals) {
      // 处理达到时间之前的操作
      // 将释放的椅子加入到 available_chairs 中
      while (j < n && leavings[j].first <= arrival.first) {
        available_chairs.push(seats[leavings[j].second]);
        ++j;
      }
      // 处理达到操作
      // 占据当前编号最小且未被占据的椅子
      int seat = available_chairs.top();
      seats[arrival.second] = seat;
      available_chairs.pop();
      if (arrival.second == targetFriend) {
        return seat;
      }
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) { return 0; }
