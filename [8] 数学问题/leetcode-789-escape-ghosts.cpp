/*
 * @Description:
 *
 * 使用曼哈顿距离
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

int m_distance(vector<int>& points1, vector<int>& points2) {
  return abs(points1[0] - points2[0]) + abs(points1[1] - points2[1]);
}

bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
  vector<int> source(2);
  int distance = m_distance(source, target);
  for (auto& ghost : ghosts) {
    int ghost_distance = m_distance(ghost, target);
    if (ghost_distance <= distance) return false;
  }
  return true;
}

int main(int argc, char const* argv[]) { return 0; }
