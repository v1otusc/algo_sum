/*
 * @Description:
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
 * 编写一个函数来判断给定的目标值是否存在于数组中，若存在则返回 true
 * 否则返回 false。
 *
 * @输入示例：
 *
 * nums = [2, 5, 6, 0, 0, 1, 2], target = 0
 *
 * @输出实例：
 *
 * true
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
 * 即使数组被旋转过，我们仍然可以利用这个这个数组的递增性，使用二分查找，对于当前的中点，
 * 如果它指向的值小于等于右端,那么说明右区间是排好序的;反之,那么说明左区间是排好序的。
 * 如果目标值位于排好序的区间内,我们可以对这个区间继续二分查找;反之,我们对于另一半区间继续二分查找。
 *
 * 注意，因为数组存在重复数字，如果中点和左端的数字相同，并不能确定是左区间全部相同，还是右区间完全相同。
 * 在这种情况下，我们可以简单地将左端点右移一位，然后继续进行二分查找
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/[3] 二分查找/
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static bool search(vector<int>& nums, int target) {
    // 左闭右闭的写法
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
      int mid = (start + end) / 2;
      if (target == nums[mid]) {
        return true;
      }
      // **无法判断哪个区间是增序的,有可能是左边完全相同或者右边完全相同**
      if (nums[start] == nums[mid]) {
        ++start;
      } else if (nums[mid] <= nums[end]) {
        // 右区间是增序的
        if (target > nums[mid] && target <= nums[end]) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      } else {
        // 左区间是增序的
        if (target >= nums[start] && target < nums[mid]) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{2, 5, 6, 0, 0, 1, 2};
  int target = 0;
  if (Solution::search(nums, target)) {
    cout << "Search result -- True" << endl;
  } else {
    cout << "Search result -- False" << endl;
  }
  return 0;
}
