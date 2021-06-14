/*
 * @Description:
 *
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z
 * 字形排列。
 *
 * 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
 *
 * @输入示例：
 *
 * s = "PAYPALISHIRING", numRows = 3
 *
 * @输出实例：
 *
 * "PAHNAPLSIIGYIR"
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
 * 首先可以使用 min(numRows,len(s)) 个列表来表示 Z 字形图案中的非空行。
 * 从左到右迭代
 * s，将每个字符添加到合适的行。可以使用——当前行和当前方向这两个变量对合适的行进行跟踪。
 * 只有当我们向上移动到最上面的行或向下移动到最下面的行时，当前方向才会发生改变。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    int n_rows = min(numRows, static_cast<int>(s.size()));
    vector<string> rows(n_rows);
    int curRow = 0;
    bool goingDown = false;

    for (auto c : s) {
      rows[curRow] += c;
      if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
      curRow += goingDown ? 1 : -1;
    }

    string res = "";
    for (auto row : rows) res += row;
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }