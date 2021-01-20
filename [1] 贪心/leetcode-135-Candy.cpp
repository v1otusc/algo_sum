/*
 * @Description:
 *
 * 老师想给孩子们分发糖果，有 N
 * 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 *  每个孩子至少分配到 1 个糖果。
 *  评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 *
 * @输入示例：
 *
 * [1, 0, 2] 一个数组，表示孩子的评分
 * [1, 2, 2] 一个数组，表示孩子的评分
 *
 * @输出实例：
 *
 * 5 最少糖果的数量，可以分别给三个孩子发 2， 1， 2 个糖果
 * 4 你可以分别给这三个孩子分发 1、2、1 颗糖果，第三个孩子只得到 1
 * 颗糖果，这已满足上述两个条件。
 *
 * @输入输出说明：
 *
 * 在第一个样例中，最少的糖果分法是 [2, 1, 2]
 *
 * @限制条件：
 *
 * NULL
 *
 * @解题思路：
 *
 * 做完了题目
 * 455,你会不会认为存在比较关系的贪心策略一定需要排序或是选择?虽然这一
 * 道题也是运用贪心策略,但我们只需要简单的两次遍历即可:把所有孩子的糖果数初始化为
 * 1;
 * 先从左往右遍历一遍,如果右边孩子的评分比左边的高,则右边孩子的糖果数更新为左边孩子的糖果数加
 * 1;
 * 再从右往左遍历一遍,如果左边孩子的评分比右边的高,且左边孩子当前的糖果数不大于右边孩子的糖果数,则左边孩子的糖果数更新为右边孩子的糖果数加
 * 1。
 * 通过这两次遍历, 分配的糖果就可以满足题目要求了。
 * 这里的贪心策略即为,在每次遍历中,只考虑并更新相邻一侧的大小关系。(局部最优到整体最优)
 * 在样例中,我们初始化糖果分配为 [1,1,1],第一次遍历更新后的结果为
 * [1,1,2],第二次遍历 更新后的结果为 [2,1,2]。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/贪心/leetcode-135-Candy.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int candy(vector<int>& ratings) {
    int child_num = ratings.size();
    // 一定要先考虑特殊情况
    if (child_num < 2) {
      return child_num;
    }

    vector<int> candy_num(child_num, 1);

    for (size_t i = 0; i < child_num - 1; i++) {
      if (ratings[i + 1] > ratings[i]) {
        candy_num[i + 1] = candy_num[i] + 1;
      }
    }

    for (size_t i = child_num - 1; i > 0; i--) {
      if (ratings[i - 1] > ratings[i]) {
        // 这里有问题，不应该采取以下代码
        // candy_num[i - 1] = candy_num[i] + 1;
        // 而应该采取下列代码，原因是，如果输入是 [1, 2, 3, 4,
        // 1]，输出会有问题（从右到左的时候）
        candy_num[i - 1] = max(candy_num[i] + 1, candy_num[i - 1]);
      }
    }

    // std::accumulate 求和
    // 第三个参数为 starting value to add other values to
    return std::accumulate(candy_num.begin(), candy_num.end(), 0);
  }
};

int main(int argc, char const* argv[]) {
  // vector<int> r1{1, 0, 2};
  // vector<int> r2{1, 2, 2};
  vector<int> r3{1, 2, 87, 87, 87, 2, 1};

  // cout << Solution::candy(r1) << endl;
  // cout << Solution::candy(r2) << endl;
  cout << Solution::candy(r3) << endl;

  return 0;
}
