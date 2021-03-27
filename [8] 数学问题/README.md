## 数学问题

### 公倍数与公因数

利用辗转相除法,我们可以很方便地求得两个数的最大公因数(greatest common divisor, gcd);将两个数相乘再除以最大公因数即可得到最小公倍数(least common multiple, lcm)。

```c++
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a% b);
}
int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

```

### 质数


