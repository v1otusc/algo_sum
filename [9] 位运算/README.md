## 位运算

<!-- TOC -->

- [位运算](#位运算)
  - [常用技巧](#常用技巧)
  - [移位运算符](#移位运算符)
    - [左移运算符](#左移运算符)
    - [右移运算符](#右移运算符)

<!-- /TOC -->

### 常用技巧



### 移位运算符

移位运算符包括左移 << 和 右移 >>。

#### 左移运算符

**无符号**

语法格式：需要移位的数字 << 移位的次数 n

运算规则：按**二进制形式**把所有数字向左移动相应的位数，高位移出（舍弃），低位的空位补 0。相当于乘以 2 的 n 次方。

例如:4 << 2 ，就是将数字 4 的二进制左移 2 位，具体过程是 4 的二进制形式：00000000 00000000 00000000 00000100；然后把高位2个0移出，其余所有位向左移动2位，低位补0，得到：00000000 00000000 00000000 00010000；十进制数为16，16=4*2<sup>2</sup>

测试程序：

```c++
#include <iostream>
#include <bitset>
using namespace std;
int main() {
  unsigned short short1 = 4;    
  bitset<16> bitset1{short1};   // the bitset representation of 4
  cout << bitset1 << endl;  // 0000000000000100

  unsigned short short2 = short1 << 1;     // 4 left-shifted by 1 = 8
  bitset<16> bitset2{short2};
  cout << bitset2 << endl;  // 0000000000001000

  unsigned short short3 = short1 << 2;     // 4 left-shifted by 2 = 16
  bitset<16> bitset3{short3};
  cout << bitset3 << endl;  // 0000000000010000
}
```

**有符号**

如果左移有符号的数字，以至于符号位受到影响，则结果是不确定的。

#### 右移运算符

**无符号**

语法格式：需要移位的数字 >> 移位的次数 n

运算规则：按二进制形式把所有数字向右移动相应的位数，低位移出（舍弃），高位的空位补 0。相当于除以 2 的 n 次方

例如:4 >> 2 ，就是将数字 4 左移 2 位，具体过程是4的二进制形式：00000000 00000000 00000000 00000100；然后把低位2个0移出，其余所有位向右移动2位，高位补0，得到：00000000 00000000 00000000 00000001；十进制数为1，1=4÷2<sup>2</sup>。

测试代码：

```c++
#include <iostream>
#include <bitset>
using namespace std;

int main() {
  unsigned short short11 = 1024;
  bitset<16> bitset11{short11};
  cout << bitset11 << endl;     // 0000010000000000

  unsigned short short12 = short11 >> 1;  // 512
  bitset<16> bitset12{short12};
  cout << bitset12 << endl;     // 0000001000000000

  unsigned short short13 = short11 >> 10;  // 1
  bitset<16> bitset13{short13};
  cout << bitset13 << endl;     // 0000000000000001

  unsigned short short14 = short11 >> 11;  // 0
  bitset<16> bitset14{short14};
  cout << bitset14 << endl;     // 0000000000000000}
}
```

**有符号**

语法格式：需要移位的数字 >> 移位的次数 n

运算规则：按二进制形式把所有数字向右移动相应的位数，低位移出（舍弃），正数，高位的空位补0。负数，高位的空位补1。

测试代码(正数)：

```c++
#include <iostream>
#include <bitset>
using namespace std;

int main() {
  short short1 = 1024;
  bitset<16> bitset1{short1};
  cout << bitset1 << endl;     // 0000010000000000

  short short2 = short1 >> 1;  // 512
  bitset<16> bitset2{short2};
  cout << bitset2 << endl;     // 0000001000000000

  short short3 = short1 >> 11;  // 0
  bitset<16> bitset3{short3};   
  cout << bitset3 << endl;     // 0000000000000000
}
```

测试代码(负数)：

```c++
#include <iostream>
#include <bitset>
using namespace std;

int main() {
  short neg1 = -16;
  bitset<16> bn1{neg1};
  cout << bn1 << endl;  // 1111111111110000

  short neg2 = neg1 >> 1; // -8
  bitset<16> bn2{neg2};
  cout << bn2 << endl;  // 1111111111111000

  short neg3 = neg1 >> 2; // -4
  bitset<16> bn3{neg3};
  cout << bn3 << endl;  // 1111111111111100

  short neg4 = neg1 >> 4; // -1
  bitset<16> bn4{neg4};    
  cout << bn4 << endl;  // 1111111111111111

  short neg5 = neg1 >> 5; // -1 
  bitset<16> bn5{neg5};    
  cout << bn5 << endl;  // 1111111111111111
}
```
