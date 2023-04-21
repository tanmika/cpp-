# 基础数据类型

## 简单变量

- 1 变量的命名
> 1. 只可使用字母字符、数字和下划线
> 2. 第一个字符不可是数字
> 3. 区分大小写
> 4. 不可使用关键字

- 2 整型
> - short >= 16bit
> - int >= short
> - long >= 32bit
> - long long >= 64bit

- 以补码方式储存
- 获取空间 sizeof()
- 获取符号常量 \<limits> 

```c++
// 常用整型空间
cout << "short:" << sizeof(short) << endl;
cout << "int:" << sizeof(int) << endl;
cout << "long:" << sizeof(long) << endl;
cout << "long long:" << sizeof(long long) << endl;
// 常用整型范围
cout << "short range:" << SHRT_MIN << "~" << SHRT_MAX << endl;
cout << "unsigned short range:0~" << USHRT_MAX << endl;
cout << "int range:" << INT_MIN << "~" << INT_MAX << endl;
cout << "unsigned int range:0~" << UINT_MAX << endl;
cout << "long range:" << LONG_MIN << "~" << LONG_MAX << endl;
cout << "unsigned long range:0~" << ULONG_MAX << endl;
cout << "long long range:" << LLONG_MIN << "~" << LLONG_MIN << endl;
cout << "unsigned long long range:0~" << ULLONG_MAX << endl;
```
out:
```c++
// MSVC 10.0 x64
short:2
int:4
long:4
long long:8
short range:-32768~32767
unsigned short range:0~65535
int range:-2147483648~2147483647
unsigned int range:0~4294967295
long range:-2147483648~2147483647
unsigned long range:0~4294967295
long long range:-9223372036854775808~-9223372036854775808
unsigned long long range:0~18446744073709551615
```
- 字面值
```c++
int dec_num = 42;
int hex_num = 0x42;
int oct_num = 042;

cout << dec_num << " " << hex_num << " " << oct_num << endl;
cout << std::hex;
cout << hex_num << endl;
cout << std::oct;
cout << oct_num << endl;
```
out:
```c++
42 66 34
42
42
```
- 溢出
分为上溢和下溢
```c++
cout << SHRT_MIN - 1 << endl;
cout << SHRT_MAX + 1 << endl;
cout << USHRT_MAX + 1 << endl;
cout << INT_MIN - 1 << endl;
cout << INT_MAX + 1 << endl;
cout << UINT_MAX + 1 << endl;
cout << LONG_MIN - 1 << endl;
cout << LONG_MAX + 1 << endl;
cout << ULONG_MAX + 1 << endl;
cout << LLONG_MIN - 1 << endl;
cout << LLONG_MAX + 1 << endl;
cout << ULLONG_MAX + 1 << endl;
```
out:
```c++
37777677777
100000
200000
17777777777
20000000000
0
17777777777
20000000000
0
777777777777777777777
1000000000000000000000
0
```

- 3 字符型

- char
```c++
char c = 'a';	//使用单引号赋值字符
cout<<sizeof(char)<<endl;
// 输出
cout << c << " " << 'a' << " ";
cout.put('a')<<endl;
// 字面量
char dec_c = 77;
char hex_c = '\x4d';
char oct_c = '\115';
cout<<dec_c<<" "<<hex_c<<" "<<oct_c<<endl;
```
out:
```c++
1
a a a
M M M
```
- 宽字符
```c++
// wchar_t
wchar_t wc = L'好';
cout<<sizeof(wchar_t)<<endl;
// char16_t
char16_t c16 = u'好';
cout<<sizeof(char16_t)<<endl;
// char32_t
char32_t c32 = U'好';
cout<<sizeof(char32_t)<<endl;
```
out:
```c++
2
2
4
```

- 4 浮点型

> - float
> - double
> - long double

```c++
// 浮点型空间大小
cout<<sizeof(float)<<endl;
cout<<sizeof(double)<<endl;
cout<<sizeof(long double)<<endl;
// 浮点型范围
cout << "float:" << std::numeric_limits<float>::min() << "~" << std::numeric_limits<float>::max() << endl;
cout << "double : " << std::numeric_limits<double>::min() << "~" << std::numeric_limits<double> ::max() << endl;
cout << "long double : " << std::numeric_limits<long double>::min() << "~" << std::numeric_limits<long double> ::max() << endl;
// 浮点型精度
cout << "float precision:" <<std::numeric_limits<float>::digits<<endl;
cout << "double precision:" <<std::numeric_limits<double>::digits<<endl;
cout << "long double precision:" <<std::numeric_limits<long double>::digits<<endl; 
```
out:
```c++
4
10
10
float:1.17549e-38~3.40282e+38
double : 2.22507e-308~1.79769e+308
long double : 2.22507e-308~1.79769e+308
float precision:30
double precision:65
long double precision:65
```
- 科学计数法表示下的数为浮点型
```c++
auto f_small = 3.14e-30;
auto f_huge = 3.14e30;
cout << f_small << ":" << typeid(f_small).name() << endl;
cout << f_huge << ":" << typeid(f_huge).name() << endl;
```
out:
```c++
3.14e-30:double
3.14e+30:double
```
- 5 布尔型

- bool

```c++
bool b = true;
cout << sizeof(bool)<<endl;
cout << b << endl;
// 字面量
bool b_true_p = true + 1;
bool b_true_n = true - 1;
bool b_false_p = false + 1;
bool b_false_n = false - 1;
cout << b_true_p << " " << b_true_n << " " << b_false_p << " " << b_false_n << endl;
```
out:
```c++
1
1
1 0 1 1
```