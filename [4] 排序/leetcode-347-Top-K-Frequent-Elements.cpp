/*
 * @Description:
 *
 * 给定一个数组，求前 k 个最频繁的数字
 *
 * @输入示例：
 *
 * 输入为一个数组和一个目标值
 *
 * nums = [1, 1, 1, 1, 2, 2, 3, 4], k = 2
 *
 * @输出实例：
 *
 * 输出为一个长度为 k 的数组，[1, 2]
 *
 * @输入输出说明：
 *
 * 在这个样例中，最频繁的两个数是 1 和 2。
 *
 * @限制条件：
 *
 * 给定的 k 总是合理的
 * 算法的时间复杂度必须优于 O(nlogn) , n 是数组的大小。
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
 *
 * @题目思路：
 *
 * 桶排序的基本思路就是为每个值设立一个桶，桶内记录这个值出现的次数（或者其他属性）
 * 然后对桶的频次进行排序，前 k 大个桶及是前 k
 * 个频繁的数，这里就可以使用各种排序算法。
 *
 * leetcode--
 *
 * 首先遍历整个数组，并使用哈希表记录每个数字出现的次数，并形成一个「出现次数数组」。找出原数组的前
 * k 个高频元素，就相当于找出「出现次数数组」的前 k
 * 大的值。最简单的做法是给「出现次数数组」排序。但由于可能有 O(N)
 * 个不同的出现次数（其中 N 为原数组长度），故总的算法复杂度会达到
 * O(Nlog⁡N)，不满足题目的要求。
 *
 * 在这里，我们可以利用堆的思想：建立一个小顶堆，然后遍历「出现次数数组」：
 *
 * - 如果堆的元素个数小于 k, 就可以直接插入堆中；
 * - 如果堆的元素个数等于 k, 则检查**堆顶与当前出现次数的大小**。
 *   如果堆顶更大，说明至少有 k 个数字的出现次数比当前值大，故舍弃当前值；
 *   否则，就弹出堆顶，并将当前值插入堆中
 *
 *  遍历完成后，堆中的元素就代表了「出现次数数组」中前 k 大的值
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/[4] 排序/
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  // 第二个元素表示数组中第一个 int 出现的次数
  static bool cmp(pair<int, int>& m, pair<int, int>& n) {
    return m.second > n.second;
  }

  static vector<int> topKFrequent(vector<int>& nums, int k) {
    // unordered_map和map类似，都是存储的 key-value 的值，可以通过 key
    // 快速索引到 value。不同的是 unordered_map 不会根据 key
    // 的大小进行排序，存储时是根据key的hash值判断元素是否相同，即 unordered_map
    // 内部元素是无序的。unordered_map
    // 的底层是一个防冗余的哈希表（开链法避免地址冲突）。unordered_map 的 key
    // 需要定义 hash_value 函数并且重载 operator==
    unordered_map<int, int> occurrences;
    for (auto& v : nums) {
      occurrences[v]++;
    }

    // priority_queue<Type, Container, Functional>，优先队列
    // Type 为数据类型，Contaainer 为保存数据的容器，Functional 为元素比较方式
    // 如果不写后两个参数，那么容器默认用的是 vector，比较方式默认的是
    // operator<，也就是优先队列是大顶堆，队头元素最大
    // 下面一行建立一个根据出现次数来比较的小顶堆，队头元素最小
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(
        cmp);

    // 因为pair<int,int>标准库没有写他的运算符排序，需要手写一个函数来确定他的优先级，cmp就相当于把这个函数作为参数进行传值

    for (auto& occur : occurrences) {
      if (q.size() == k) {
        if (q.top().second < occur.second) {
          q.pop();
          q.emplace(occur);
        }
      } else {
        q.emplace(occur);
      }
    }

    vector<int> ret;
    while (!q.empty()) {
      ret.emplace_back(q.top().first);
      q.pop();
    }
    return ret;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 1, 1, 2, 2, 3};
  int k = 2;
  vector<int> res(k, 0);
  res = Solution::topKFrequent(nums, k);

  for (auto i = res.begin(); i != res.end(); i++) {
    cout << *i << endl;
  }

  return 0;
}
