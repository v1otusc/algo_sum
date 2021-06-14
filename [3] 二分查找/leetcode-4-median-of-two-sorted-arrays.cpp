/*
 * @Description:
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 num1 和 num2
 * 找出并返回这两个正序数组的 中位数
 *
 * @输入示例：
 *
 * num1 = [1,3] num2 = [2]
 *
 * @输出实例：
 *
 * 2.00000
 *
 * @输入输出说明：
 *
 * 合并数组 = [1,2,3], 中位数 2
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 根据中位数的定义，当 m+n 是奇数时，中位数是两个有序数组中的第
 * (m+n)/2 个元素，当 m+n 是偶数时，中位数是两个有序数组中的第
 * (m+n)/2 个元素和第 (m+n)/2+1
 * 个元素的平均值。因此，这道题可以转化成寻找两个有序数组中的第 k 小的数，其中
 * k 为 (m+n)/2 或 (m+n)/2+1
 *
 * 单独写一个得到第 K 个最小元素的函数
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
    /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和
     * pivot2 = nums2[k/2-1] 进行比较 这里的 "/" 表示整除
     * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
     * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
     * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot
     * 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
     * 这样 pivot 本身最大也只能是第 k-1 小的元素 如果 pivot = pivot1，那么
     * nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部
     * "删除"，剩下的作为新的 nums1 数组 如果 pivot = pivot2，那么 nums2[0 ..
     * k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的
     * nums2 数组 由于我们 "删除" 了一些元素（这些元素都比第 k
     * 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
     */
    /**
     * 特殊情况处理：
     * 如果 nums[k/2−1] 或者 nums[k/2−1]
     * 越界，那么我们可以选取对应数组中的最后一个元素。
     * 在这种情况下，我们必须根据排除数的个数减少 k 的值，而不能直接将 k 减去
     * k/2。
     *
     * 如果一个数组为空，说明该数组中的所有元素都被排除，我们可以直接返回另一个数组中第
     * k 小的元素。
     *
     * 如果 k=1我们只要返回两个数组首元素的最小值即可。
     */
    int m = nums1.size();
    int n = nums2.size();
    // 是有效索引的边界，删除元素后，有效索引会发生变化
    int index1 = 0, index2 = 0;

    while (true) {
      // 边界情况
      if (index1 == m) {
        return nums2[index2 + k - 1];
      }
      if (index2 == n) {
        return nums1[index1 + k - 1];
      }
      if (k == 1) {
        return min(nums1[index1], nums2[index2]);
      }

      // 正常情况，需要判断是否越界了
      int newIndex1 = min(index1 + k / 2 - 1, m - 1);
      int newIndex2 = min(index2 + k / 2 - 1, n - 1);
      int pivot1 = nums1[newIndex1];
      int pivot2 = nums2[newIndex2];
      if (pivot1 <= pivot2) {
        // 删除不可能元素的过程
        k -= newIndex1 - index1 + 1;
        index1 = newIndex1 + 1;
      } else {
        // 删除不可能元素的过程
        k -= newIndex2 - index2 + 1;
        index2 = newIndex2 + 1;
      }
    }
  }

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if ((m + n) % 2 != 0) {
      return getKthElement(nums1, nums2, (m + n + 1) / 2);
    } else {
      return (getKthElement(nums1, nums2, (m + n) / 2) +
              getKthElement(nums1, nums2, (m + n) / 2 + 1)) / 2.0;
    }
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums1{1, 2};
  vector<int> nums2{3, 4};

  Solution s;
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;

  return 0;
}
