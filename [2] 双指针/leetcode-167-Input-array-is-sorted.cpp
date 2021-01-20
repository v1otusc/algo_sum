/*
 * @Description:
 *
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 已知有且只有一对解
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 说明:
 *  返回的下标值（index1 和 index2）从 1 开始计数
 *  你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 *
 * @输入示例：
 *
 * Input: numbers = [2,7,11,15], target = 9
 *
 * @输出实例：
 *
 * [2, 7]
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
 * 因为数组已经排好序,我们可以采用方向相反的双指针来寻找这两个数字,
 * 一个初始指向最小的元素,即数组最左边,向右遍历;
 * 一个初始指向最大的元素,即数组最右边,向左遍历。
 * 如果两个指针指向元素的和等于给定值,那么它们就是我们要的结果。如果两个指针指向元
 * 素的和小于给定值,我们把左边的指针右移一位,使得当前的和增加一点。如果两个指针指向元
 * 素的和大于给定值,我们把右边的指针左移一位,使得当前的和减少一点。
 *
 * 并且可以证明：对于排好序且有解的数组，双指针一定能够遍历到最优解，证明方法如下：
 * 假设最有解的两个数的位置分别是 l 和 r, 假设在左指针在 l
 * 左边的时候,右指针已经移动到了 r
 * 此时两个指针指向值的和小于给定值,因此左指针会一直右移直到到达
 * l。同理,如果我们假设在右指针在 r 右边的时候,左指针已经移动到了
 * l;此时两个指针指向值的和大于给定值。因此两个指针指向值的和大于定值，因此
 * 右指针会一直左移直到到达 r。所以双指针在任何时候都不可能处于 (l, r)
 * 之间,又因为不满足条件时指针必须移动一个,所以最终一定会收敛在 l 和 r
 * 这两个位置。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1;
    while (numbers[l] + numbers[r] != target && (l < r)) {
      if (numbers[l] + numbers[r] < target) {
        l++;
      } else {
        r--;
      }
    }
    vector<int> res;
    res.push_back(l + 1);
    res.push_back(r + 1);
    return res;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> numbers = {2, 7, 11, 15};
  vector<int> res = Solution::twoSum(numbers, 9);

  for (auto it = res.cbegin(); it != res.cend(); it++) {
    cout << *it << endl;
  }
  return 0;
}
