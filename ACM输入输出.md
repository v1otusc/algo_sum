## ACM 输入输出

主要知识点是，在 C++ 中，可以使用 istringstream 配合 getline 根据分隔符来分割字符串。

### 字符串分割

首先，我们使用一个字符串s来初始化输入字符串流 istringstream

```c++
string s = "a/b/c/d";
istringstream iss(s);
```

然后，我们使用 getline 函数通过 iss 对字符串进行分割，getline 函数的原型为

```c++
istream& getline (istream &is , string &str , char delim);
```

第一个参数为 is 表示一个 istringstream，这里就是 iss，第二个参数表示我们要将字符串分割的结果通过 getline 逐个放入 str 中，第三个参数为分隔符，注意分隔符只能为字符型。示例如下：

```c++
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s = "a/b/c/d";
    istringstream iss(s);
    string buffer;
    while(getline(iss, buffer, '/'))
    {
        cout<<buffer<<endl;
    }
    return 0;
}
```

输出为

```
a
b
c
d
```

如果我们将字符串 s 设为 a/b//c//d，代码其余不变，则结果为

```
a
b

c

d
```

可以看到，两个连续的分隔符会被解析为空串。

### while 和 cin 配合使用的解析

从输入缓存区读取数据时会跳过空格和回车，把他们当做字符之间的间隔。要想结束输入 ctrl+z 或者读到了文件末尾或者在 while 循环中添加条件语句跳出循环

```c++
#include <iostream>
using namespace std;

int main() {
  char c;
  cout << "enter a sentence:" << endl;
  while(cin >> c)
    cout << c;
  
  return 0;
}
```

原因是：

### C++ cin.get 用法


