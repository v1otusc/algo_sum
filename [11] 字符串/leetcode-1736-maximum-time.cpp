/*
 * @Description:
 *
 * 给你一个字符串 time ，格式为 hh:mm（小时：分钟），其中某几位数字被隐藏（用
 * ?表示）。有效的时间为 00:00 到 23:59 之间的所有时间，包括 00:00 和 23:59 。
 * 替换 time 中隐藏的数字，返回你可以得到的最晚有效时间。
 *
 * @输入示例：
 *
 * time = "2?:?0"
 *
 * @输出实例：
 *
 * 23：50
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
 * 使用贪心的思路
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  string maximumTime(string time) {
    if (time[0] == '?') {
      time[0] = (time[1] >= '4' && time[1] <= '9') ? '1' : '2';
    }
    if (time[1] == '?') {
      time[1] = (time[0] == '2') ? '3' : '9';
    }
    if (time[3] == '?') {
      time[3] = '5';
    }
    if (time[4] == '?') {
      time[4] = '9';
    }
    return time;
  }
};

int main(int argc, char const* argv[]) { return 0; }
