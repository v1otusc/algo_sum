/*
 * @Description:
 *
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1
 * 成为一个有序数组。
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1
 * 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素。
 *
 * @输入示例：
 *
 *  nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 *
 * @输出实例：
 *
 * nums1 = [1,2,2,3,5,6]
 *
 * @输入输出说明：
 *
 * 输入是两个数组和它们分别的长度 m 和 n。其中第一个数组的长度被延长至 m +
 * n,多出的 n 位被 0
 * 填补。题目要求把第二个数组归并到第一个数组上,不需要开辟额外空间。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 因为这两个数组已经排好序,我们可以把两个指针分别放在两个数组的末尾,即 nums1 的
 * m - 1 位和 nums2 的 n - 1 位
 * 每次将较大的数字复制到 nums1 的后面，然后向前移动一位。因为我们也要定位 nums1
 * 的末尾，所以我们还需要第三个指针，以便复制
 *
 * 在以下的代码里,我们直接利用 m 和 n 当作两个数组的指针,再额外创立一个 pos
 * 指针，起始位置为 m + n - 1。每次向前移动 m 和 n 时，也要向前移动
 * pos，这里需要注意，如果 nums1 的数字提前复制完，不要忘记把 nums2
 * 的数字继续复制，如果 nums2 的数字提前复制完，剩余 nums1
 * 的数字并不需要改变，因为他们已经被排好序
 *
 * **注意**：
 *
 * 这里我们使用了 ++ 和--的小技巧:a++ 和 ++a 的结果都是将 a 加 1,但是 a++
 * 返回值为 a，而
 * ++a 返回值为 a+1。如果只是希望增加 a 的值,而不需要返回值，**则推荐使用 ++a**， 
 * 其运行速度会略快一些。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/[2]双指针/
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  // 这道题的技巧，++a 和 a++ 的区别
  static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) { 
    int pos = m-- + n-- - 1;
    while(m >= 0 && n >= 0) {
      nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    while (n >= 0) {
      nums1[pos--] = nums2[n--];
    }
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums1{1, 2, 3, 0, 0};
  vector<int> nums2{2, 5, 6};
  int m = 3;
  int n = 3;
  Solution::merge(nums1, m, nums2, n);
  // 遍历输出 vector 中的元素，注意不需要加改为 (*i)
  for (auto i : nums1) {
    cout << i << endl;
  }

  return 0;
}
