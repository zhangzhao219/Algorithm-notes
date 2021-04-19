# 算法笔记总结

## C/C++快速入门

---

### 1. 数的范围

|标识符|实际范围|实用范围|备注|
|-|-|-|-|
|```int```|$-2^{31}$ ~ $2^{31} - 1$</br>$-2147483648$ ~ $2147483647$|$-2 \times 10^{9}$ ~ $2 \times 10^{9}$|绝对值在 $10^{9}$ 范围内的数都可以定义为 ```int``` 型|
|```long long```|$-2^{63}$ ~ $2^{63} - 1$|$-9 \times 10^{18}$ ~ $9 \times 10^{18}$|```long long``` 赋大于 $2^{31} - 1$ 的初值，需要在初值后面加上 ```LL```|
|```float```||$6$ ~ $7$ 位|尽量不用，四位数乘四位数都不准|
|```double```||$15$ ~ $16$ 位||

```cpp
long long bignum = 123456789012345LL;
```

---

|无穷大的数|十六进制的形式|十进制的形式|
|-|-|-|
|$2^{30} - 1$</br>（避免相加超过```int```的情况）|```0x3fffffff```|```1000000000```|

---

### 2. 常用 ```math``` 函数

| 函数名|作用|返回值|备注
|-|-|-|-|
|```fabs(double x)```|对 ```double``` 型变量 ```x``` 取绝对值|返回 ```double``` 型变量||
|```floor(double x)```|对 ```double``` 型变量 ```x``` 向下取整|返回 ```double``` 型变量||
|```ceil(double x)```|对 ```double``` 型变量 ```x``` 向上取整|返回 ```double``` 型变量||
|```pow(double r,double p)```|对 ```double``` 型变量 ```r``` 和 ```p``` 计算 $r^p$|返回 ```double``` 型变量||
|```sqrt(double x)```|对 ```double``` 型变量 ```x``` 计算算数平方根|返回 ```double``` 型变量||
|```log(double x)```|对 ```double``` 型变量 ```x``` 取以自然对数为底的对数|返回 ```double``` 型变量|不能对任意底数求对数|
|```round(double x)```|对 ```double``` 型变量 ```x``` 进行四舍五入|返回 ```double``` 型变量|需进行取整才能用</br> ```(int)x```|

---

### 3. ```sscanf``` 与 ```sprintf``` 函数

|写法|实际|含义|
|-|-|-|
|```scanf("%d",&a)```|```scanf(screen,"%d",&a)```|把 ```screen``` 的内容以  ```%d``` 的形式传输至 ```a``` 中|
|```printf("%d",a)```|```printf(screen,"%d",a)```|把 ```a``` 的内容以  ```%d``` 的形式传输至 ```screen``` 中|
|```sscanf(str,"%d",&a)```||把 ```str``` 的内容以  ```%d``` 的形式传输至 ```a``` 中|
|```sprintf(str,"%d",a)```||把 ```a``` 的内容以  ```%d``` 的形式传输至 ```str``` 中|

---

```sscanf``` 示例：

```cpp
int n;
char str[5] = "123";
sscanf(str,"%d",&n); // 将str以%d的形式写到n中
printf("%d\n",n);
// 123

int n;
double db;
char str2[100];

char str[100] = "2048:3.14,hello";
sscanf(str,"%d:%lf,%s",&n,&db,str2);
printf("%d:%lf,%s",n,db,str2);
// 2048:3.140000,hello
```

```sprintf``` 示例：

```cpp
int n = 233;
char str[5];
sprintf(str,"%d",n); // 将n以%d的形式写到str中
printf("%s\n",str);
return 0;
// 233

int n = 2048;
double db = 3.14;
char str2[100] = "hello";

char str[100];
sprintf(str,"%d:%lf,%s",n,db,str2);
printf("%s",str);
// 2048:3.140000,hello
```
