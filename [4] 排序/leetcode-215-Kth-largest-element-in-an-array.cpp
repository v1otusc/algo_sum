/*
 * @Description:
 *
 * 在未排序的数组中找到第 K 个最大的元素。
 *
 * @输入示例：
 *
 * [3, 2, 1, 5, 6, 4]
 * k = 2
 *
 * [3, 2, 3, 1, 2, 4, 5, 5, 6]
 * k = 4
 *
 * @输出实例：
 *
 * 5
 * 4
 *
 * @输入输出说明：
 *
 * 可以假设 k 总是有效的，即 1 <= k <= 数组的长度
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 快速选择一般用于求解 k-th Element，可以在 O(n) 时间复杂度，O(1)
 * 空间复杂度完成求解工作。快速选择的实现和快速排序相似,不过只需要找到第 k
 * 大的枢(pivot)即可,不需要对其左右再进行排序。与快速排序一样，快速选择一般
 * 需要先打乱数据，否则最坏情况下时间复杂度为 O(n^2)
 *
 * leetcode 上讲得很好：
 *
 * 我们可以用快速排序来解决这个问题，先对原数组排序，再返回倒数第 k
 * 个位置，这样平均时间复杂度是
 * O(nlog⁡n)，但其实我们可以做的更快。对数组 a[l⋯r]
 * 做快速排序的过程是（参考《算法导论》）：
 *
 * - 分解： 将数组 a[l⋯r]「划分」成两个子数组 a[l⋯q−1]、a[q+1⋯r] 使得
 * a[l⋯q−1] 中的每个元素小于等于 a[q]，且
 * a[q] 小于等于 a[q+1⋯r] 中的每个元素。其中计算下标 q 也是划分过程的一部分
 *
 * - 解决： 通过递归调用，对两个子数组进行排序
 *
 * - 合并： 因为子数组都是原址排序的，所以不需要进行合并操作
 *
 * - 上文中提到的 「划分」 过程是：从子数组 a[l⋯r]
 * 中选择任意一个元素 x
 * 作为主元，调整子数组的元素使得左边的元素都小于等于它，右边的元素都大于等于它，
 * x 的最终位置就是 q。
 *
 * 由此可见每次经过划分后，我们一定可以确定一个元素的最终位置，即 x 的最终位置为
 * q，并可以保证左边的子数组都小于 a[q]，右边的子数组都大于
 * a[q]。所以只要某次划分的 q 为倒数第 k
 * 个下标的时候，我们就已经找到了答案。
 *
 * 因此我们可以改进快速排序算法来解决这个问题：在分解的过程当中，我们会对子数组进行划分，如果划分得到的
 * q 正好就是我们需要的下标，就直接返回 a[q]；否则，如果 q
 * 比目标下标小，就递归右子区间，否则递归左子区间。这样就可以把原来递归两个区间变成只递归一个区间，提高了时间效率。这就是「快速选择」算法。
 *
 * 快速排序在最差情况下的时间复杂度为
 * O(n^2)，可以进行随机化进行加速，时间代价的期望是
 * O(n)，证明过程参考算法导论 9.2：期望为线性的选择算法
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/[4] 排序/
 */

#include "bits/stdc++.h"

using namespace std;

// 采取**左闭右闭**的写法
class Solution {
 public:
  // 划分，将 nums[l] 作为 pivot，左边子数组小于 pivot, 右边子数组大于
  // pivot，返回划分后此 pivot 在数组中的下标
  static int partition(vector<int>& nums, int l, int r) {
    int first = l, last = r, pivot = nums[first];
    while (first < last) {
      while (first < last && nums[last] >= pivot) {
        --last;
      }
      nums[first] = nums[last];
      while (first < last && nums[first] <= pivot) {
        ++first;
      }
      nums[last] = nums[first];
    }
    nums[first] = pivot;
    return first;
  }

  // 进行随机化以加速划分过程，
  static int randomPartition(vector<int>& nums, int l, int r) {
    // 产生一个在 l 和 r 之间的随机数
    int i = rand() % (r - l + 1) + l;
    swap(nums[i], nums[l]);
    return partition(nums, l, r);
  }

  static int quickSelect(vector<int>& nums, int l, int r, int index) {
    int q = randomPartition(nums, l, r);
    if (q == index) {
      return nums[q];
    } else {
      return q < index ? quickSelect(nums, q + 1, r, index)
                       : quickSelect(nums, l, q - 1, index);
    }
  }

  static int findKthLargest(vector<int>& nums, int k) {
    srand(time(0));
    return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{3, 2, 1, 5, 6, 4};
  int k = 2;
  cout << Solution::findKthLargest(nums, k) << endl;
  return 0;
}