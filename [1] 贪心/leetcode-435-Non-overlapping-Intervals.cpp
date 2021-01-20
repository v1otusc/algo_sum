/*
 * @Description:
 *
 * 给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。
 * 注意:
 *  可以认为区间的终点总是大于它的起点。
 *  区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
 *
 * @输入示例：
 *
 * [ [1,2], [2,3], [3,4], [1,3] ]
 *
 * @输出实例：
 *
 * 1
 *
 * @输入输出说明：
 *
 * 移除 [1,3] 后，剩下的区间没有重叠。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 在选择要保留区间时,区间的结尾十分重要:选择的区间结尾越小,余留给其它区间的空间就越大,就越能保留更多的区间。
 * 因此,我们采取的贪心策略为,优先保留结尾小且不相交的区间。
 * 具体实现方法为：先把区间按照结尾的大小进行增序排序，每次选择结尾最小且和前一个选择的区间不重叠的区间
 * -- 使用 C++ 匿名函数--自定义排序规则。
 * 注意-需要根据实际情况判断按区间开头排序还是按区间结尾排序。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/[1] 贪心/non-overlapping-intervals.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // 一定要考虑特殊情况
    if (intervals.size() < 2) {
      return 0;
    }
    // 按照结尾的大小进行增序排列
    sort(intervals.begin(), intervals.end(),
         [](vector<int> a, vector<int> b) { return a[1] < b[1]; });

    int res = 0;
    int prev = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] < prev) {
        res++;
      } else {
        // 如果没有 else，例子 [[1,100],[11,22],[1,11],[2,12]] 会失败
        prev = intervals[i][1];
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  // 初始化输入
  vector<int> p1{1, 2};
  vector<int> p2{2, 3};
  vector<int> p3{3, 4};
  vector<int> p4{1, 3};
  vector<vector<int>> intervals;
  intervals.push_back(p1);
  intervals.push_back(p2);
  intervals.push_back(p3);
  intervals.push_back(p4);

  cout << Solution::eraseOverlapIntervals(intervals) << endl;

  return 0;
}