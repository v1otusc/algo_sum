/*
 * @Description:
 *
 * 在无向图找出一条边,移除它之后该图能够成为一棵树(即无向无环图)
 * 。如果有多个解,返回在原数组中位置最靠后的那条边
 *
 * 该图由一个有着 N 个节点(节点值不重复1， 2...N)
 *
 * @输入示例：
 *
 * [[1, 2], [1, 3], [2, 3]]
 *
 * @输出实例：
 *
 * [2, 3]
 *
 * @输入输出说明：
 *
 * 输入是一个二维数组,表示所有的边(对应的两个节点);输出是一个一维数组,表示需要
 * 移除的边(对应两个节点)
 *
 * 其中 [2, 3] 在原来数组的位置最靠后
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 *
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

// 并查集
class UF {
  vector<int> id;

 public:
  UF(int n) : id(n) {
    // 用顺序递增的值赋值指定范围内的元素
    // 把数组初始化为 0 到 n-1
    // id[0] = 0, id[1] = 1 ...
    // id[p] == q 表示 q 为 p 的父节点
    iota(id.begin(), id.end(), 0);
  }

  // 找到 p 的祖先
  int find(int p) {
    while (p != id[p]) {
      id[p] = id[id[p]];
      p = id[p];
    }
    return p;
  }

  // 把祖先连接起来
  void connect(int p, int q) { id[find(p)] = find(q); }

  bool isConnected(int p, int q) { return find(p) == find(q); }
};

class Solution {
 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    UF uf(n + 1);
    for (auto e : edges) {
      int u = e[0];
      int v = e[1];
      if (uf.isConnected(u, v)) {
        return e;
      }
      uf.connect(u, v);
    }
    return vector<int>{-1, -1};
  }
};

int main(int argc, char const* argv[]) { return 0; }
