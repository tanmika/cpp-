# [基础数据类型](base_data_type.cpp)

## 简单变量类型

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

## 复合数据类型

- 1 数组   

- 在内存中线性的存储多个同类型的值的类型为数组
- 数组名本身就可以被视为指向数组首元素的指针，arr 和 &arr[0] 的值是相等的，都是数组首元素的地址
- 数组大小为所储存的数据单独大小之和

```c++
int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
cout << "arr:" << arr << " &arr[0]:" << &arr[0] << " *arr:" <<*arr<< " *(arr + 1):" << *(arr+1) 
	<< " arr[10] size:" << sizeof(arr) << endl;
```
out:
```c++
arr:0000007B73F7F398 &arr[0]:0000007B73F7F398 *arr:1 *(arr + 1):2 arr[10] size:50
```

>一维数组指针

```c++
int *p = arr;
int(*q)[] = &arr;
```
指针变量 p 和数组指针变量 q 都可以用来表示数组的地址。不同之处在于，指针变量 p 指向的是数组的首元素，
而数组指针变量 q 指向的是整个数组。
```c++
cout << "pointer of arr[10] size:" << sizeof(p) << "\np -> *p p:" << p << " *p:" << *p << " *(p + 1):" 
	<< *(p + 1) << endl;
```
out:
```c++
pointer of arr[10] size:10
p -> *p p:0000007B73F7F398 *p:1 *(p + 1):2
```
通过指针变量 p 访问数组元素时，使用的是单层指针*p，即先将指针 p 指向的地址解析出来，
再通过 * 运算符来访问该地址中存储的值。\*(p + 1)中，p+1指的是在指针p的地址上移动一个int的长度
```c++
int(*q)[] = &arr;
cout << "pointer of arr[10] size:" << sizeof(q) << "\nq -> (*q)[] q:" << q << " *q:" << *q << " **q:" << **q 
	<< " *(*q + 1):" << *(*q + 1) << endl;
```
out:
```c++
pointer of arr[10] size:10
q -> (*q)[] q:0000007B73F7F398 *q:0000007B73F7F398 **q:1 *(*q + 1):2
```
数组指针q是指向数组的指针，它可以表示整个数组，而不仅仅是数组的首元素。因此，q 的类型为 int (*)[10]，
而 *q 表示指针 q 指向的地址中存储的值，即整个数组，因此 *q 的类型为 int [10]，即数组类型。
最后，**q 表示指针 q 指向的地址中存储的值，即数组的首元素的值，即 **q 的类型为 int。

在使用数组指针时，通常需要使用双层指针 **q 来访问数组中的元素，因为数组指针指向的是整个数组，
而数组中的元素可能是复合类型，如结构体或类，因此需要通过双层指针来进行访问。
例如，可以使用 *(*q + i) 访问数组中的第 i 个元素，其中 *q 表示数组的首元素的地址，
即指向 int 类型的指针，而 *(*q + i) 表示指针加上 i 个偏移量后所指向的地址中存储的值，
即数组中的第 i 个元素的值。

- 多维数组

```c++
int p2[3][3];
for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
	{
		p2[i][j] = i * 3 + j;
	}
}
```
基本定义

>二维数组指针
```c++
// int** 风格
int** p2;
p2 = new int* [3];
for (int i = 0; i < 3; i++)
{
	p2[i] = new int[3];
}
for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
	{
		p2[i][j] = i * 3 + j;
	}
}
for (int i = 0; i < 3; i++)
{
	delete[] p2[i];
}
delete[] p2;
```
int** 风格表示指向二维数组的指针，即一个指针数组，每个指针指向一个一维数组。

其优点是可以动态分配空间，每个一维数组的大小可以不同。
缺点是需要多次动态分配和释放内存，容易出错，并且由于指针数组和每个 int 类型的数组都是单独分配的，
不是连续的内存，因此可能会影响性能和缓存命中率，不便于指针移动和数组遍历。
```c++
// int*[] 风格
int* p2[3];
for (int i = 0; i < 3; i++)
{
	p2[i] = new int[3];
}
for (int i = 0; i < 3; i++)
{
	for (int j = 0; j < 3; j++)
	{
		p2[i][j] = i * 3 + j;
	}
}
for (int i = 0; i < 3; i++)
{
	delete[] p2[i];
}
``` 
int*[] 风格表示二维数组的数组指针，即一个数组，每个元素是一个指向一维数组的指针。

其优点是只需要动态分配一次内存，便于指针移动和数组遍历，也比较容易理解。
缺点是每个一维数组的大小必须相同，不便于动态改变大小，也不太适合存储稀疏矩阵等不规则数据结构。
```c++
// int(*)[] 风格
int (*p2)[3] = new int[3][3];
for (size_t i = 0; i < 3; i++)
{
	for (size_t j = 0; j < 3; j++)
	{
		p2[i][j] = i * 3 + j;
	}
}
delete[] p2;
```
int(*)[]风格表示二维数组指针，即一个指针，指向一个二维数组。

其优点是只需要动态分配一次内存，便于指针移动和数组遍历，也比较容易理解，而且每个维度的大小可以不同，适合存储不规则数据结构。
缺点是需要使用new[]和delete[]来分配和释放内存，稍微有些不便。

```c++
int arr2[3][3] = { 0 };
for (size_t i = 0; i < 3; i++)
{
	for (size_t j = 0; j < 3; j++)
	{
		arr2[i][j] = i * 3 + j;
	}
}
cout << "arr[3][3] size:" << sizeof(arr2) << endl;
int(*p2)[3] = arr2;
cout << "pointer of arr[3][3] size:" << sizeof(p2) << endl;
cout << "p -> (*p)[3] p:" << p2 << " *p:" << *p2 << " *(p + 1):" << *(p2 + 1) << " *(*p + 1):" << *(*p2 + 1) 
	<< " *((*p + 1) + 1):" << *((*p2 + 1) + 1) << " *(*(p + 1) + 1):" <<*(*(p2 + 1) + 1)<< endl;
```
out:
```c++
pointer of arr[3][3] size:10
p -> (*p)[3] p:0000007B73F7F438 *p:0000007B73F7F438 *(p + 1):0000007B73F7F444 *(*p + 1):1 *((*p + 1) + 1):2 *(*(p + 1) + 1):4
```
与一维数组数组指针类似，p表示整个数组的地址，*(p + k)表示第k个数组所在的地址，即&arr[k]，
**(p + k)表示第k个数组的首元素，即arr[k][0]，\*(\*(p + k) + b)表示arr[k][b]，即(k, b)中元素。

数组退化
```c++
int a[2];            // 含有 2 个 int 元素的数组
int* p1 = a;         // 退化到指向 a 的首元素的指针
 
int b[2][3];         // 含有 2 个【含有 3 个 int 元素的数组】元素的数组
// int** p2 = b;     // 错误：b 不退化到 int**
int (*p2)[3] = b;    // b 退化到指向 b 的首个 3 元素行的指针
 
int c[2][3][4];      // 含有 2 个【含有 3 个【含有 4 个 int 元素的数组】元素的数组】元素的数组
// int*** p3 = c;    // 错误：c 不退化到 int***
int (*p3)[3][4] = c; // c 退化到指向 c 首个 3 × 4 元素平面的指针
```

未知边界数组

可以构成到未知边界数组的引用和指针，但不能从已知边界的数组或指向已知边界数组的指针对它进行初始化或赋值。
注意在 C 编程语言中，指向未知边界数组的指针与指向已知边界数组的指针兼容，从而可以双向转换和赋值。

```c++
extern int a1[];
int (&r1)[] = a1;  // OK
int (*p1)[] = &a1; // OK
int (*q)[2] = &a1; // 错误（但 C 中 OK）
 
int a2[] = {1, 2, 3};
int (&r2)[] = a2;  // 错误
int (*p2)[] = &a2; // 错误（但 C 中 OK）
```
指向未知边界数组的指针不能参与指针算术且不能用在下标运算符的左侧，但可以解引用。
到未知边界数组的引用和指针无法作为函数形参。

```c++
extern int x[];      // x 的类型是“边界未知的含有 int 元素的数组”
int a[] = {1, 2, 3}; // a 的类型是“含有 3 个 int 元素的数组”

extern int a[][2]; // OK：边界未知的含有【含有 2 个 int 元素的数组】元素的数组
extern int b[2][]; // 错误：数组有不完整类型
```
如果在数组声明中省略表达式，则声明的类型是“T 的未知边界数组”，这是一种不完整类型，除非在声明时带有聚合初始化器 extern

因为数组元素不能具有未知边界数组类型，所以多维数组只能在第一个维度中有未知边界。

- 2 字符串

\* 此处为C-style string，\<string>类型请看[此处]

```c++
char charray[8] = { 'g','r','e','a','t','d','a','y'};	// 字符数组
char string0[8] = { 'h','o','l','i','d','a','y','\0'};	// 字符串
char string1[] = "enjoy!!";								// 自带\0，实际长度8 + 2
cout << "ch array print ins:" << charray << " print div:";
for (auto ch :charray)
{
	cout << ch;
}
cout << " type:" << typeid(charray).name() << " size:" << sizeof(charray) << endl;
cout << "string:" << string0 << " type:" << typeid(string0).name() << " size:" << sizeof(string0) << endl;
```
out:
```c++
ch array print ins:greatday烫烫烫烫烫烫烫烫烫烫烫烫holiday print div:greatday type:char [8] size:10
string:holiday type:char [8] size:10
```