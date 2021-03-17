/*
 * @Description:
 *
 * 给定一个无重复数字的整数数组,求其所有的排列方式。
 *
 * @输入示例：
 *
 * [1, 2, 3]
 *
 * @输出实例：
 *
 * [
    [1,2,3],
    [1,3,2],
    [2,1,3],
    [2,3,1],
    [3,1,2],
    [3,2,1]
 * ]
 *
 * @输入输出说明：
 *
 * 输入是一个一维整数数组,输出是一个二维数组,表示输入数组的所有排列方式。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 这个问题可以看作有 n 个排列成一行的空格，我们需要从左往右依此填入题目给定的
 * n
 *
 个数，每个数只能使用一次。那么很直接的可以想到一种穷举的算法，即从左往右每一个位置都依此尝试填入一个数，看能不能填完这
 * n 个空格，在程序中我们可以用「回溯法」来模拟这个过程。
 *
 * 怎样输出所有的排列方式呢?对于每一个当前位置
 * i,我们可以将其于之后的所有的任意位置交换, 然后继续处理位置
 * i+1,直到处理到最后一位。为了防止我们每此遍历时都要新建一个子数组储 存位置 i
 * 之前已经交换好的数字,我们可以利用回溯法,只对原数组进行修改,在递归完成后再
 * 修改回来。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    backtracking(nums, 0, ans);
    return ans;
  }

  static void backtracking(vector<int>& nums, int level,
                           vector<vector<int>>& ans) {
    if (level == nums.size() - 1) {
      ans.push_back(nums);
      return;
    } else {
      for (int i = level; i < nums.size(); ++i) {
        swap(nums[i], nums[level]);
        // 一是按引用传递状态
        backtracking(nums, level + 1, ans);
        // 二是所有的状态修改在递归完成后回改
        swap(nums[i], nums[level]);
      }
    }
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 2, 3};
  vector<vector<int>> ans = Solution::permute(nums);

  // 为什么 auto& i : ans 中需要用到引用？
  // TODO: 仍然是个需要解释的问题
  for (auto& i : ans) {
    for (auto& j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }

  return 0;
}
