/*
 * @Description:
 *
 设计一个固定大小的,最少最近使用缓存 (least recently used cache,
 LRU)。每次将信息插入未
 满的缓存的时候,以及更新或查找一个缓存内存在的信息的时候,将该信息标为最近使用。在缓
 存满的情况下将一个新信息插入的时候,需要移除最旧的信息,插入新信息,并将该信息标为最
 近使用。
 *
 * @调用示例：
 *
 * // 2 为 capacity
 * LRUCache cache = new LRUCache(2);
 * // 表示键值对
 * cache.put(1,1)
 * cache.put(2,2)
 * cache.get(1) //return 1
 * // 去掉2，为什么？因为cache.get(1)的时候，已经将该信息标为最新使用
 * cache.put(3,3)
 * cache.get(2) return -1(not found)
 * cache.put(4,4) // evicit key 1
 * cache.get(1) // return -1(not found)
 * cache.get(3) // return 3
 * cache.get(4) // return 4
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 采用list<pair<int, int>>来储存信息的 key 和
 * value,链表的顺序就是最近使用的新旧顺序,最新的顺序在链表头节点。
 *
 * 同时我们需要一个嵌套着链表的迭代器的 unordered_map<int, list<pair<int,
 * int>>::iterator> 进行快速搜索。其中 int 代表 key
 *
 * 存迭代器的原因是方便调用链表的splice函数来直接更新查找成功(cache hit)时的信息
 * 即把迭代器对应的节点移动为链表的头结点
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class LRUCache {
 private:
  unordered_map<int, list<pair<int, int>>::iterator> hash;
  list<pair<int, int>> cache;
  int size;

 public:
  // 构造函数
  LRUCache(int capacity) : size(capacity) {}

  int get(int key) {
    auto it = hash.find(key);
    if (it == hash.end()) {
      return -1;
    }
    // 将其标记为最新的信息
    // 把 it->second 的值剪接到 cache 的 cache.begin() 位置
    cache.splice(cache.begin(), cache, it->second);
    return it->second->second;
  }

  void put(int key, int value) {
    auto it = hash.find(key);
    if (it != hash.end()) {
      // 如果有就更新一下对应的 value
      it->second->second = value;
      cache.splice(cache.begin(), cache, it->second);
      return;
    }
    // 如果没有就要插入
    cache.insert(cache.begin(), make_pair(key, value));
    hash[key] = cache.begin();
    // 然后检查是否超过 size()
    if(cache.size() > size) {
      hash.erase(cache.back().first);
      cache.pop_back();
    }
  }
};

int main(int argc, char const* argv[]) { return 0; }
