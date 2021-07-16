## 优先队列

- [优先队列](#优先队列)
  - [1. 基本使用](#1-基本使用)
  - [2. sort 和 priority_queue 中使用仿函数时的不同](#2-sort-和-priority_queue-中使用仿函数时的不同)
    - [2.1 sort 自定义排序](#21-sort-自定义排序)
    - [2.2 priority_queue 自定义排序](#22-priority_queue-自定义排序)
    - [2.3 区别](#23-区别)

### 1. 基本使用

既然是队列那么先要包含头文件`#include <queue>`, 和 `queue` 不同的就在于我们可以自定义其中数据的优先级，让优先级高的排在队列前面，优先出队。

优先队列具有队列的所有特性，包括基本操作，只是在这基础上添加了内部的一个排序，它本质是一个堆实现的：

和队列基本操作相同：

- top 访问队头元素
- empty 队列是否为空
- size 返回队列内元素个数
- push 插入元素到队尾 (并排序)
- emplace 原地构造一个元素并插入队列
- pop 弹出队头元素
- swap 交换内容

定义：`priority_queue<Type, Container, Functional>`

Type 就是数据类型，Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector），Functional 就是比较的方式，当需要用自定义的数据类型时才需要传入这三个参数，使用基本数据类型时，只需要传入数据类型，默认是大顶堆:

```c++
//升序队列，小根堆
priority_queue <int, vector<int>, greater<int>>  q;
//降序队列，大根堆
priority_queue <int, vector<int>, less<int>> q;

//greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数。其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了）

// 当进行 pair 的比较时，先比较第一个元素，第一个相等再比较第二个元素
```

### 2. sort 和 priority_queue 中使用仿函数时的不同

#### 2.1 sort 自定义排序

我们可以使用自定义的 cmp 函数、lambda 函数或者 `less<int>()`、`greater<int>()`作为自定义compare对象作为参数传给 sort 函数，达到自定义比较顺序的结果。代码如下：

使用自定义的 cmp 函数

```c++
bool cmp(const int &a, const int &b){
    return a < b;
}
// 升序
sort(vec.begin(), vec.end(), cmp);
```

使用 lambda 函数

```c++
sort(vec.begin(), vec.end(), [](int a, int b){return a < b;});
```

使用 `less<int>()` 或者 `greater<int>()`

```c++
sort(vec.begin(), vec.end(), less<int>());
```

#### 2.2 priority_queue 自定义排序

对于 priority_queue 优先队列可以使用仿函数自定义 compare 顺序：

```c++
class Cmp{
public:
    bool operator()(int a, int b){
        return a<b;
    }
}
priority_queue<int, vector<int>, Cmp> pri_que;
```

#### 2.3 区别

而自定义 sort 时并不能使用仿函数名 Cmp，例如如下代码是错的：

```c++
// 这个代码是错的
class Cmp{
public:
    bool operator()(int a, int b){
        return a<b;
    }
}
sort(vec.begin(), vec.end(), Cmp);
```

sort 函数的定义如下：

```c++
template< class RandomIt, class Compare >
constexpr void sort( RandomIt first, RandomIt last, Compare comp );
```

可以看到 sort 是一个模板函数，这里需要三个输入参数(第三个参数默认的), 第一、二个参数是需要排序的迭代器，第三个参数 comp 是一个 Compare 类的对象。

priority_queue 的定义如下：

```c++
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
```

priori_queue 是一个模板类，类型参数表为 T、Container 和 Compare，这三者都是类(Class)。我们关注的 Compare 类默认为 `std::less< typename Container::value_type>`。

从上面我们可以知道。对于模板函数 sort，我们需要在 sort 的参数列表"()"中给出自定义的Compare类的实例，而对于模板类priority_queue，我们需要在其类型参数表 "<>"中给出自定义的Compare类。

因此，使用仿函数作为cmp的合法代码如下:

```c++
class Cmp{
public:
    bool operator() (int a, int b){
        return a < b;
    }
};
...
sort(vec.begin(), vec.end(), Cmp());    //这里Cmp()相当于一个类Cmp实例化后的对象
// 或者也可以这样
Cmp cmp;
sort(vec.begin(), vec.end(), cmp);      // 这里的cmp是一个Cmp类型的对象
// priori_queue中类型参数表中使用Cmp类名，而不是Cmp类具体实例化后的对象
priority_queue<int, vector<int>, Cmp> pri_que; 
```

至于为什么一个需要使用实例化后的对象，一个需要使用类名。因为本质上 sort 是一个函数，函数参数列表中需要传入实例化后的具体对象，而 priority_queue 是一个模板类，模板的类型参数表中 <> 需要传入具体的类，而不是对象。
