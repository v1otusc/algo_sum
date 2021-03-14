/*
 * @Description:
 *
 * 给定一个包含了一些 0 和 1 的非空二维数组 grid 。
 *
 * 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1
 * 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被
 * 0（代表水）包围着。
 *
 * @输入示例：
 *
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,1,1,0,1,0,0,0,0,0,0,0,0],
 *  [0,1,0,0,1,1,0,0,1,0,1,0,0],
 *  [0,1,0,0,1,1,0,0,1,1,1,0,0],
 *  [0,0,0,0,0,0,0,0,0,0,1,0,0],
 *  [0,0,0,0,0,0,0,1,1,1,0,0,0],
 *  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 *
 * @输出实例：
 *
 * 对于上面这个给定矩阵应返回 6。注意答案不应该是 11
 * ，因为岛屿只能包含水平或垂直的四个方向的 1 。
 *
 * @输入输出说明：
 *
 * NULL
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 1. 使用 dfs 进行递归的做法，刷题的时候还是用递归吧
 *    如果我们在一个土地上，以 4
 *    个方向探索与之相连的每一个土地（以及与这些土地相连的土地），那么探索过的土地总数将是该连通形状的面积。
 *    为了确保每个土地访问不超过一次，我们每次经过一块土地时，将这块土地的值置为
 *    0。这样我们就不会多次访问同一土地。（很关键）
 *
 * 2. 使用 dfs + 栈的做法：
 *    方法一通过函数的调用来表示接下来想要遍历哪些土地，让下一层函数来访问这些土地。而方法二把接下来想要遍历的土地放在栈里，然后在取出这些土地的时候访问它们。
 *    访问每一片土地时，我们将对围绕它四个方向进行探索，找到还未访问的土地，加入到栈
 *    stack 中；
 *    另外，只要栈 stack
 *    不为空，就说明我们还有土地待访问，那么就从栈中取出一个元素并访问。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

// 使用 dfs + 栈的写法，刷题的时候还是使用递归的写法吧
/* class Solution {
 public:
  static int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;
    for (size_t i = 0; i < grid.size(); ++i) {
      for (size_t j = 0; j < grid[0].size(); ++j) {
        int cur = 0;
        stack<int> stacki;
        stack<int> stackj;
        stacki.push(i);
        stackj.push(j);
        while (!stacki.empty()) {
          int cur_i = stacki.top();
          int cur_j = stackj.top();
          stacki.pop();
          stackj.pop();
          if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() ||
              cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
            continue;
          }
          ++cur;
          grid[cur_i][cur_j] = 0;
          int di[4] = {0, 0, 1, -1};
          int dj[4] = {1, -1, 0, 0};
          for (int index = 0; index != 4; ++index) {
            int next_i = cur_i + di[index];
            int next_j = cur_j + dj[index];
            stacki.push(next_i);
            stackj.push(next_j);
          }
        }
        ans = max(ans, cur);
      }
    }
    return 0;
  }
}; */

// 使用 dfs 递归的做法
class Solution {
 public:
  static int dfs(vector<vector<int>>& grid, int cur_i, int cur_j) {
    // 判断边界条件，如果判断为土地才接着搜索
    if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() ||
        cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
      return 0;
    }
    int ans = 1;
    // 可以把这块土地的值置为 0 了
    grid[cur_i][cur_j] = 0;
    // 表示周围的土地
    int di[4] = {0, 0, -1, 1};
    int dj[4] = {-1, 1, 0, 0};
    for (int index = 0; index < 4; ++index) {
      int next_i = cur_i + di[index];
      int next_j = cur_j + dj[index];
      ans += dfs(grid, next_i, next_j);
    }
    return ans;
  }

  static int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;
    for (size_t i = 0; i < grid.size(); ++i) {
      for (size_t j = 0; j < grid[0].size(); ++j) {
        ans = max(ans, dfs(grid, i, j));
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  vector<vector<int>> grid{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

  cout << Solution::maxAreaOfIsland(grid) << endl;
  return 0;
}
