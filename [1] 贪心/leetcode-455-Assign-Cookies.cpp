/*
 * @Description:
 *
 * 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
 * 对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；
 * 并且每块饼干 j，都有一个尺寸 s[j] 如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i
 * 这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
 *
 * @输入示例：
 *
 * [1, 2] [1, 2, 3] 输入两个数组,分别代表孩子的饥饿度和饼干的大小。
 *
 * @输出实例：
 *
 * 2 输出最多有多少孩子可以吃饱的数量
 *
 * @输入输出说明：
 *
 * 在这个样例中,我们可以给两个孩子喂 [1,2]、[1,3]、[2,3] 这三种组合的任意一种。
 *
 * @限制条件：
 *
 *  1 <= g.length <= 3 * 104
 *  0 <= s.length <= 3 * 104
 *  1 <= g[i], s[j] <= 231 - 1
 *
 * @解题思路：
 *
 * 属于贪心算法中的分配问题，这里的贪心是指--用最小的代价满足尽可能多的孩子
 * 因为饥饿度最小的孩子最容易吃饱,所以我们先考虑这个孩子。
 * 为了尽量使得剩下的饼干可以满足饥饿度更大的孩子,所以我们应该把大于等于这个孩子饥饿度的、且大小最小的饼干给这个孩子。
 * 满足了这个孩子之后,我们采取同样的策略,考虑剩下孩子里饥饿度最小的孩子,直到没有满足条件的饼干存在。
 * 简而言之,这里的贪心策略是,给剩余孩子里最小饥饿度的孩子分配最小的能饱腹的饼干。（局部最优到整体最优）
 * 至于具体实现,因为我们需要获得大小关系,一个便捷的方法就是把孩子和饼干分别排序。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/贪心/leetcode-455-Assign-Cookies.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int findContentChildren(vector<int>& children, vector<int>& cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    int child = 0, cookie = 0;
    while (child < children.size() && cookie < cookies.size()) {
      if (children[child] <= cookies[cookie]) {
        child++;
      }
      cookie++;
    }
    return child;
  }
};

int main(int argc, char const* argv[]) {
  // 孩子的饥饿度
  vector<int> g{1, 2};
  // 饼干的大小
  vector<int> s{1, 2, 3};

  // TODO:将输入作为孩子的饥饿度 & 饼干的大小

  cout << Solution::findContentChildren(g, s);
  return 0;
}
