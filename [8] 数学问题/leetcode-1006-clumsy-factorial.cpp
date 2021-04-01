/*
 * @Description:
 *
 通常，正整数 n 的阶乘是所有小于或等于 n 的正整数的乘积。例如，factorial(10) =
 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1。

 相反，我们设计了一个笨阶乘
 clumsy：在整数的递减序列中，我们以一个固定顺序的操作符序列来依次替换原有的乘法操作符：乘法(*)，除法(/)，加法(+)和减法(-)。

 例如，clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 *
 1。然而，这些运算仍然使用通常的算术运算顺序：我们在任何加、减步骤之前执行所有的乘法和除法步骤，并且按从左到右处理乘法和除法步骤。

 另外，我们使用的除法是地板除法（floor division），所以 10 * 9 / 8 等于
 11。这保证结果是一个整数。

 实现上面定义的笨函数：给定一个整数 N，它返回 N 的笨阶乘。
 *
 * @输入示例：
 *
 * 4
 *
 * @输出实例：
 *
 * 7
 *
 * @输入输出说明：
 *
 * 7 = 4 * 3 / 2 + 1
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 从 N 开始，枚举 N-1, N-2 直到
 1，枚举这些数的时候，认为它们之前的操作符按照「乘」「除」「加」「减」交替进行。

 - 出现乘法、除法的时候可以把栈顶元素取出，与当前的 N
 进行乘法运算、除法运算（除法运算需要注意先后顺序），并将运算结果重新压入栈中；
 -
 出现加法、减法的时候。把减法视为加上另一个数的相反数，然后压入栈，等待以后遇到「乘」「除」法的时候取出。

 简而言之，遇到乘除立即算，遇到加减先入栈。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int clumsy(int N) {
    stack<int> stk;
    stk.push(N);
    N--;
    // 用于控制加减乘除
    int index = 0;
    while (N > 0) {
      if (index % 4 == 0) {
        stk.top() *= N;
      } else if (index % 4 == 1) {
        stk.top() /= N;
      } else if (index % 4 == 2) {
        stk.push(N);
      } else {
        stk.push(-N);
      }
      index++;
      N--;
    }
    int sum = 0;
    // 把栈中所有的数字依次弹出求和
    while (!stk.empty()) {
      sum += stk.top();
      stk.pop();
    }
    return sum;
  }
};

int main(int argc, char const* argv[]) { return 0; }
