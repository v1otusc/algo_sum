## C++ 基本数据类型

C++ 中的基本类型包括算数类型以及空类型。空类型不对应具体的值，算数类型包含字符，整数型，布尔值和浮点数。

算数类型又分为两类，整型（包括字符和布尔类型在内）和浮点型。

C++ 中的字符类型多数支持国际化（扩展字符集），基本的字符类型是 char，一个 char 的大小最小尺寸为一个机器字节。

C++ 中的整型有规定如下，一个 int 至少和一个 short 一样大，一个 long 至少和一个 int 一样大，一个 long long 至少和一个 long 一样大，long long 为 C++11 中新定义的。

除了布尔型和带扩展的字符型之外，其他整型可以分为带符号的和无符号的，在类型 int, short, long, long long 之前加上 unsigned 可以得到无符号类型（大于等于零），仅仅一个 unsigned 表示 unsigned int 的缩写。

需要注意的是，char 实际上分为了三种：char, unsigned char 和 signed char，尽管有三种类型，但是在实际使用时实际上只能表现出两种，所以，类型 char 具体的表现形式实际上由编译器决定。

C++ 中的浮点类型可以表示单精度、双精度和扩展精度值。在大多数编译器中，float 以 1 个字(4 个字节，32 bit)来表示，double 以 2 个字来表示，long double 以 3 个或者 4 个字表示。

> C++ 中的指针这种复合类型(区别于基本数据类型)大小为定值 4 个字节。

### 基本数据类型使用建议

- 当明确知道数据不为负时，选用无符号类型；
- 使用 int 来表示整型，当超出范围时，选用 long long;
- 在算数表达式中不要使用 char 和布尔类型，毕竟 char 在一些机器上是有符号的，但是在另外一些机器上是无符号的。除非指定 unsigned char 或者 signed char;
- 执行浮点数运算使用 double。

### C++ 中算数类型的数值范围

> 注意不同机器中的不同编译器数据类型的取值范围不一定相同

| Type | Size | 数值范围 |
| :------ | ------ | ------ |
| void | 0 byte | 无值域 |
| 布尔型 bool | 1 byte | true false |
| 有符号字符型 signed char | 1 byte | -128~127 |
| 无符号字符型 unsigned char | 1 byte | 0~255 |
| 有符号短整型 short / signed short | 2 byte | -32768~32767 |
| 无符号短整型 unsigned short | 2 byte | 0~65535 |
| 有符号整型 int / signed int | 4 byte | -2147483648~2147483647 |
| 无符号整型 unsigned int | 4 byte | 0~4294967295 |
| 有符号长整型 long / signed long | 4 byte | -2147483648~2147483647 |
| 无符号整型 unsigned long | 4 byte | 0~4294967295 |
| 有符号 long long / signed long long | 8 byte | -9223372036854775808 ~ +9223372036854775807 |
| 有符号 unsigned long long | 8 byte | 0~1844674407370955161 |

