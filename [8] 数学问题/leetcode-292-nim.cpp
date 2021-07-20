/*
 * @Description:
 *
 * 你和你的朋友，两个人一起玩 Nim 游戏：

    桌子上有一堆石头。
    你们轮流进行自己的回合，你作为先手。
    每一回合，轮到的人拿掉 1 - 3 块石头。
    拿掉最后一块石头的人就是获胜者。

 * 假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 n
 * 的情况下赢得游戏。如果可以赢，返回 true；否则，返回 false 。
 *
 * @输入示例：
 *
 * n = 4
 *
 * @输出实例：
 *
 * false
 *
 * @输入输出说明：
 *
 * 如果堆中有 4 块石头，那么你永远不会赢得比赛；
 * 因为无论你拿走 1 块、2 块 还是 3 块石头，最后一块石头总是会被你的朋友拿走。
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
  bool canWinNim(int n) { return !(n % 4 == 0); }
};

int main(int argc, char const* argv[]) { return 0; }