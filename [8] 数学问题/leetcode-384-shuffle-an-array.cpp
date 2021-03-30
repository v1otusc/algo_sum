/*
 * @Description:
 *
 * 给定一个数组，要求实现两个指令函数，第一个函数 shuffle 可以随机打乱这个数组
 * 第二个函数可以恢复原来的顺序
 *
 * @输入示例：
 *
 * nums = [1,2,3], actions: ["shuffle","shuffle","reset"]
 *
 * @输出实例：
 *
 * [[2,1,3],[3,2,1],[1,2,3]]
 *
 * @输入输出说明：
 *
 * 在这个样例中，前两个打乱的结果只要是随机生成即可。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 采用 Fisher-Yates
 * 洗牌算法，原理是通过随机交换位置来实现随机打乱，有正向和反向两种写法
 * 且实现非常方便，注意这里的 reset 函数以及类的构造函数的实现细节
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 private:
  vector<int> origin;

 public:
  int solution(vector<int>& g, vector<int>& s) {}
};

int main(int argc, char const* argv[]) { return 0; }