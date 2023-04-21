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

- 获取空间 sizeof()
- 获取符号常量 \<limits> 


```c++
// MSVC 10.0
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