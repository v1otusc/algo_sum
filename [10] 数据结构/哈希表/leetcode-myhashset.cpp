/*
 * @Description:
 *
 *
 *
 * @输入示例：
 *
 *
 *
 * @输出实例：
 *
 *
 *
 * @输入输出说明：
 *
 *
 *
 * @限制条件：
 *
 *
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

/*
 * @Description:
 *
 *
 *
 * @输入示例：
 *
 *
 *
 * @输出实例：
 *
 *
 *
 * @输入输出说明：
 *
 *
 *
 * @限制条件：
 *
 *
 *
 * @题目思路：
 *
 * 哈希函数：能够将集合中任意可能的元素映射到一个固定范围的整数值，并将该元素存储到整数值对应的地址上
 *
 * 解决冲突的策略
 * 链地址法：为每个哈希值维护一个链表，并将具有相同哈希值的元素都放入这一链表中
 * 开放地址法 
 * 再哈希法 
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class MyHashSet {
 private:
  // 存放真正的数据
  vector<list<int>> data;
  // 质数
  static const int base = 769;
  // 求哈希值
  static int hash(int key) { return key % base; }

 public:
  /** Initialize your data structure here. */
  MyHashSet() : data(base) {}

  void add(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); ++it) {
      if ((*it) == key) {
        return;
      }
    }
    data[h].push_back(key);
  }

  void remove(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); ++it) {
      if ((*it) == key) {
        // 参数是 position
        data[h].erase(it);
        return;
      }
    }
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    int h = hash(key);
    for (auto it = data[h].begin(); it != data[h].end(); ++it) {
      if ((*it) == key) {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) { return 0; }
