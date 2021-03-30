## 数学问题

### 公倍数与公因数

利用辗转相除法,我们可以很方便地求得两个数的最大公因数(greatest common divisor, gcd);将两个数相乘再除以最大公因数即可得到最小公倍数(least common multiple, lcm)。

```c++
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
  return a * b / gcd(a, b);
}
```

进一步地，,我们也可以通过扩展欧几里得算法(extended gcd)在求得 a 和 b 最大公因数的同时,也得到它们的系数 x 和 y,从而使 ax + by = gcd(a, b)。

```c++
int xGCD(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
  }
  int x1, y1, gcd = xGCD(b, a%b, x1, y1);
  x = x1, y = x1 - (a / b) * y1;
  return gcd;
}
```

### 质数

质数又称素数,指的是指在大于 1 的自然数中,除了 1 和它本身以外不再有其他因数的自然数。**值得注意的是,每一个数都可以分解成质数的乘积，并且最小的质数是 2。**

埃拉托斯特尼筛法(Sieve of Eratosthenes,简称埃氏筛法)是非常常用的,判断一个整数是否是质数的方法。其原理也十分易懂:从 1 到 n 遍历,假设当前遍历到 m,则把所有小于 n 的、且是 m 的倍数的整数标为和数;遍历完成后,没有被标为和数的数字即为质数。





