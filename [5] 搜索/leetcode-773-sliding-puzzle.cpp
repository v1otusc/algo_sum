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
  int slidingPuzzle(vector<vector<int>>& board) {
    // 2 x 3 的 board
    int m = 2, n = 3;
    string start = "";
    string end = "123450";
    // 将 2 x 3 的数组转化为字符串，+'0'
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        start += to_string(board[i][j]);
      }
    }

    // cout << start << endl;

    // 记录一维字符串，表示拍平之后相邻的--索引
    vector<vector<int>> neighbor = {{1, 3}, {0, 4, 2}, {1, 5},
                                    {0, 4}, {3, 1, 5}, {4, 2}};

    // BFS
    queue<string> q;
    unordered_set<string> vis;
    q.push(start);
    vis.insert(start);

    int step = 0;
    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        string cur = q.front();
        q.pop();

        // 判断是否达到
        if (cur == end) {
          return step;
        }

        // 找到数字 '0' 的索引
        int idx = 0;
        for (; cur[idx] != '0'; ++idx) {
        };

        // 将数字 '0' 与 neighbor 交换
        for (auto pos : neighbor[idx]) {
          string new_board = cur;
          swap(new_board[pos], new_board[idx]);
          // 防止走回头路
          if (!vis.count(new_board)) {
            q.push(new_board);
            vis.insert(new_board);
          }
        }
      }
      step++;
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {}
