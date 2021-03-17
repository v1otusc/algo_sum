/*
 * @Description:
 *
 * 给定一个大小为 n 的正方形国际象棋棋盘,求有多少种方式可以放置 n
 * 个皇后并使得她们互 不攻击,即每一行、列、左斜、右斜最多只有一个皇后。
 *
 * @输入示例：
 *
 * 一个整数 n
 *
 * @输出实例：
 *
 * 输出是一个二维字符串数组，表示所有的棋盘表示方法
 *
 * Output: [
   [".Q..", // Solution 1
    "...Q",
    "Q...",
    "..Q."],
   ["..Q.", // Solution 2
    "Q...",
    "...Q",
    ".Q.."]
  ]
 *
 * @输入输出说明：
 *
 * 在这个样例中，点表示空白位置，Q 代表皇后
 *
 * @限制条件：
 *
 * 1 <= n <= 9
 *
 * @题目思路：
 *
 类似于在矩阵中寻找字符串,本题也是通过修改状态矩阵来进行回溯。不同的是,我们需要
 对每一行、列、左斜、右斜建立访问数组,来记录它们是否存在皇后。
 *
 回溯的具体做法是：使用一个数组记录每行放置的皇后的列下标，依次在每一行放置一个皇后。每次新放置的皇后都不能和已经放置的皇后之间有攻击：
 即新放置的皇后不能和任何一个已经放置的皇后在同一列以及同一条斜线上，并更新数组中的当前行的皇后列下标。当
 N
 个皇后都放置完毕，则找到一个可能的解。当找到一个可能的解之后，将数组转换成表示棋盘状态的列表，并将该棋盘状态的列表加入返回列表。

 为了判断一个位置所在的列和两条斜线上是否已经有皇后，使用三个集合分别记录每一列以及两个方向的每条斜线上是否有皇后。

 如何表示两个方向的斜线呢？对于每个方向的斜线，需要找到斜线上的每个位置的行下标与列下标之间的关系。

 方向一的斜线为从左上到右下方向，同一条斜线上的每个位置满足行下标与列下标之差相等，例如
 (0,0) 和 (3,3)
 在同一条方向一的斜线上。因此使用行下标与列下标之差即可明确表示每一条方向一的斜线。

 方向二的斜线为从右上到左下方向，同一条斜线上的每个位置满足行下标与列下标之和相等，例如
 (3,0) 和 (1,2)
 在同一条方向二的斜线上。因此使用行下标与列下标之和即可明确表示每一条方向二的斜线。

 每次放置皇后时，对于每个位置判断其是否在三个集合中，如果三个集合都不包含当前位置，则当前位置是可以放置皇后的位置。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static void backtracking(vector<vector<string>>& ans, vector<string>& board,
                           vector<bool>& column, vector<bool>& ldiag,
                           vector<bool>& rdiag, int row, int n) {
    if (row == n) {
      ans.push_back(board);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (column[i] || ldiag[n - row + i - 1] || rdiag[row + i + 1]) {
        continue;
      }
      // 修改当前节点状态
      board[row][i] = 'Q';
      // 第 i 列，第 [n - row + i - 1] 个左斜对角线，第 [row + i + 1]
      // 个右斜对角线就不能放了
      column[i] = ldiag[n - row + i - 1] = rdiag[row + i + 1] = true;
      // 递归子节点
      backtracking(ans, board, column, ldiag, rdiag, row + 1, n);
      // 回改当前节点状态
      board[row][i] = '.';
      column[i] = ldiag[n - row + i - 1] = rdiag[row + i + 1] = false;
    }
  }

  static vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    if (n == 0) {
      return ans;
    }
    vector<string> board(n, string(n, '.'));
    // 列
    vector<bool> column(n, false);
    // 左上到右下的对角线，对于一个 4 × 4 的矩阵，这样的对角线一共有 7 个（2n -
    // 1）
    vector<bool> ldiag(2 * n - 1, false);
    vector<bool> rdiag(2 * n - 1, false);
    backtracking(ans, board, column, ldiag, rdiag, 0, n);
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
