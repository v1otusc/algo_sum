/*
 * @Description:
 *
 * 给一个数组 target，包含若干互不相同的整数，以及另一个整数数组
 * arr，arr可能包含重复元素
 *
 * 可以在arr的任意位置插入任一整数
 *
 * 返回最小的操作数，使得target成为arr的一个子序列
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
 * 令 target 的长度为 n, arr 的长度为 m，target 和 arr 的最长公共子序列长度为
 * max 返回的结果应该是 n-max
 *
 * [抽象成 LCS 问题]->--[利用 target 数组元素各不相同，转换为求 arr 下标的 LIS
 * 问题]->[利用 LIS 的贪心解法]
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int minOperations(vector<int>& target, vector<int>& arr) {
    int n = target.size();
    int m = arr.size();
    unordered_map<int, int> pos;
    for (int i = 0; i < n; ++i) {
      // target 的元素互不相同
      pos[target[i]] = i;
    }
    vector<int> d;
    for (int val : arr) {
      if (pos.count(val)) {
        int idx = pos[val];
        // 二分查找
        auto it = lower_bound(d.begin(), d.end(), idx);
        if (it != d.end()) {
          // 贪心地替换最小值
          /*为什么这样能使d成为"最长上升子序列"：
           * 假如已有d=[0,1,3,4],
           * 此时idx=2,会将d变成[0,1,2,4]。d的长度不变。
           *（虽然此时4对应的arr中的元素位于2对应的元素之前，但这不会影响d的长度。）
           * 如果再下一个idx=5(>4),会加在末尾变成d=[0,1,2,4,5],
           * 那么d的长度和[0,1,3,4,5]是一样的。
           * 也就是说,如果位置靠后的子序列短于位置靠前的子序列,*it=idx这一步不会影响d的长度。
           * 我们最终只需要d的长度，并不要求d的内容对应正确的arr的最长上升子序列。
           * 而如果位置靠后的子序列长于位置靠前的子序列,则会正确取到更长的这段子序列,比如
           * d=[0,1,3,4]之后,idx依次为2,3,4,则会将d变为[0,1,2,3,4]。
           * 如果去掉“*it=idx;”这一步则无法达成这个效果。
           */
          *it = idx;
        } else {
          d.push_back(idx);
        }
      }
    }
    return n - d.size();
  }
};

int main(int argc, char const* argv[]) { return 0; }
