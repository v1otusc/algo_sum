/*
 * @Description:
 *
 * 二进制手表顶部有 4 个 LED 代表小时(0-11),底部的 6 个 LED 代表分钟(0-59)。
 * 每个 LED 代表一个 0 或 1，最低位在右侧。
 *
 * @输入示例：
 *
 * turnedOn = 1
 *
 * @输出实例：
 *
 * "0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
 *
 * @输入输出说明：
 *
 * 给你一个整数 turnedOn ，表示当前亮着的 LED
 * 的数量，返回二进制手表可以表示的所有可能时间。你可以 按任意顺序 返回答案。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 使用打表的思路，需确保全局唯一，即使存在多组测试数据只生成一次打表数据
 * 然后在返回数据的时候直接 O(1) 查表返回。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  // 保存打表的结果
  static unordered_map<int, vector<string>> mp;
  static int cnt;
  // 判断 x 以二进制表示中有几个 1
  static int getCnt(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowBit(i)) {
      ans++;
    }
    return ans;
  }
  // 位运算，返回表示中位级最低的那一位(参考 readme.md)
  static int lowBit(int x) { return x & -x; }

  static void preTable() {
    cnt++;
    for (int h = 0; h <= 11; ++h) {
      for (int m = 0; m <= 59; ++m) {
        int tot = getCnt(h) + getCnt(m);
        char buffer[6];
        sprintf(buffer, "%d:%02d", h, m);
        mp[tot].push_back(buffer);
      }
    }
  }

  vector<string> readBinaryWatch(int turnedOn) {
    // 打表，把所有的结果提前存好
    if (cnt == 1) preTable();
    return mp[turnedOn];
  }
};

int Solution::cnt = 1;
unordered_map<int, vector<string>> Solution::mp = {};

int main(int argc, char const* argv[]) { return 0; }
