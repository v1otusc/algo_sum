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
 * 考虑 z 的特殊情况，优先上移左移
 *
 * @LastEditors: zzh
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  string alphabetBoardPath(string target) {
    string res;
    int cx = 0, cy = 0;
    for (char c : target) {
      int nx = (c - 'a') / 5;
      int ny = (c - 'a') % 5;
      // 优先上移，左移
      if (nx < cx) {
        res.append(cx - nx, 'U');
      }
      if (ny < cy) {
        res.append(cy - ny, 'L');
      }
      if (nx > cx) {
        res.append(nx - cx, 'D');
      }
      if (ny > cy) {
        res.append(ny - cy, 'R');
      }
      res.push_back('!');
      cx = nx;
      cy = ny;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
