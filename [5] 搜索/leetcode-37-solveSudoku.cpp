/*
 * @Description:
 *
 * 9 x 9
 * 数字 1-9 在每一行只能出现一次
 * 数字 1-9 在每一列只能出现一次
 * 数字 1-9 在每一个以粗实线分隔的 3 x 3 宫内只能出现一次
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
 * 回溯
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    backtrace(board, 0, 0);
    return;
  }

  bool backtrace(vector<vector<char>>& board, int i, int j) {
    int m = 9, n = 9;
    if (j == n) {
      return backtrace(board, i + 1, 0);
    }
    // 说明以及穷举完了最后一行 i == m - 1
    if (i == m) {
      return true;
    }
    // 如果有预设数字，不必操心
    if (board[i][j] != '.') {
      return backtrace(board, i, j + 1);
    }

    // 进入选择列表
    for (char ch = '1'; ch <= '9'; ++ch) {
      if (!is_valid(board, i, j, ch)) {
        continue;
      }
      board[i][j] = ch;
      if (backtrace(board, i, j + 1)) {
        return true;
      }
      board[i][j] = '.';
    }
    // 穷举完 1-9 仍然没有找到可行解
    // 需要前面的格子换个数字了
    return false;
  }

  bool is_valid(vector<vector<char>>& board, int row, int col, char n) {
    for (int i = 0; i < 9; ++i) {
      // 判断行是否存在重复
      if (board[row][i] == n) return false;
      // 判断列是否存在重复
      if (board[i][col] == n) return false;
      // 判断 3 x 3 宫中是否存在重复, 还是比较巧妙的
      if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == n)
        return false;
    }
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }
