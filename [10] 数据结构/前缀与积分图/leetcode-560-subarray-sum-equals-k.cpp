/*
 * @Description:
 *
 * 给定一个数组，寻找和为 k 的连续区间个数
 *
 * @输入示例：
 *
 * nums = [1, 1, 1]
 * k = 2
 *
 * @输出实例：
 *
 * 2
 *
 * @输入输出说明：
 *
 * 输入一个一维整数数组和一个整数值 k;输出一个整数,表示满足条件的连续区间个数。
 * 在这个样例中，我们可以找到两个[1, 1]连续区间满足条件
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 使用一个哈希 map，其键为前缀和，而值是该前缀和出现的次数。在我们遍历到位置 i
 时,假设当前的前缀和是 psum,那么 hashmap[psum-k] 即为以当前位置结尾、满足条件的
 区间个数。

 psum[i] = psum[i-1] + nums[i]
 如果 [i...j] 之和为 k
 psum[j] - psum[i - 1] = k
 所以 psum[i - 1] = psum[j] - k
 所以我们考虑以 j 结尾的和为 k 的连续子数组个数时只要统计有多少个前缀和为
 psum[j]−k 的次数
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    // 前缀和
    int psum = 0;
    unordered_map<int, int> hashmap;
    // 初始化很重要
    hashmap[0] = 1;
    for (int& i : nums) {
      psum += i;
      count += hashmap[psum - k];
      ++hashmap[psum];
    }
    return count;
  }
};

int main(int argc, char const* argv[]) { return 0; }
