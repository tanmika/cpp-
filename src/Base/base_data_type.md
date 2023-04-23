# [������������](base_data_type.cpp)

## �򵥱�������

- 1 ����������
> 1. ֻ��ʹ����ĸ�ַ������ֺ��»���
> 2. ��һ���ַ�����������
> 3. ���ִ�Сд
> 4. ����ʹ�ùؼ���

- 2 ����
> - short >= 16bit
> - int >= short
> - long >= 32bit
> - long long >= 64bit

- �Բ��뷽ʽ����
- ��ȡ�ռ� sizeof()
- ��ȡ���ų��� \<limits> 

```c++
// �������Ϳռ�
cout << "short:" << sizeof(short) << endl;
cout << "int:" << sizeof(int) << endl;
cout << "long:" << sizeof(long) << endl;
cout << "long long:" << sizeof(long long) << endl;
// �������ͷ�Χ
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
- ����ֵ
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
- ���
��Ϊ���������
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

- 3 �ַ���

- char
```c++
char c = 'a';	//ʹ�õ����Ÿ�ֵ�ַ�
cout<<sizeof(char)<<endl;
// ���
cout << c << " " << 'a' << " ";
cout.put('a')<<endl;
// ������
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
- ���ַ�
```c++
// wchar_t
wchar_t wc = L'��';
cout<<sizeof(wchar_t)<<endl;
// char16_t
char16_t c16 = u'��';
cout<<sizeof(char16_t)<<endl;
// char32_t
char32_t c32 = U'��';
cout<<sizeof(char32_t)<<endl;
```
out:
```c++
2
2
4
```

- 4 ������

> - float
> - double
> - long double

```c++
// �����Ϳռ��С
cout<<sizeof(float)<<endl;
cout<<sizeof(double)<<endl;
cout<<sizeof(long double)<<endl;
// �����ͷ�Χ
cout << "float:" << std::numeric_limits<float>::min() << "~" << std::numeric_limits<float>::max() << endl;
cout << "double : " << std::numeric_limits<double>::min() << "~" << std::numeric_limits<double> ::max() << endl;
cout << "long double : " << std::numeric_limits<long double>::min() << "~" << std::numeric_limits<long double> ::max() << endl;
// �����;���
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
- ��ѧ��������ʾ�µ���Ϊ������
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
- 5 ������

- bool

```c++
bool b = true;
cout << sizeof(bool)<<endl;
cout << b << endl;
// ������
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

## ������������

- 1 ����   

- ���ڴ������ԵĴ洢���ͬ���͵�ֵ������Ϊ����
- ����������Ϳ��Ա���Ϊָ��������Ԫ�ص�ָ�룬arr �� &arr[0] ��ֵ����ȵģ�����������Ԫ�صĵ�ַ
- �����СΪ����������ݵ�����С֮��

```c++
int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
cout << "arr:" << arr << " &arr[0]:" << &arr[0] << " *arr:" <<*arr<< " *(arr + 1):" << *(arr+1) 
	<< " arr[10] size:" << sizeof(arr) << endl;
```
out:
```c++
arr:0000007B73F7F398 &arr[0]:0000007B73F7F398 *arr:1 *(arr + 1):2 arr[10] size:50
```

>һά����ָ��

```c++
int *p = arr;
int(*q)[] = &arr;
```
ָ����� p ������ָ����� q ������������ʾ����ĵ�ַ����֮ͬ�����ڣ�ָ����� p ָ������������Ԫ�أ�
������ָ����� q ָ������������顣
```c++
cout << "pointer of arr[10] size:" << sizeof(p) << "\np -> *p p:" << p << " *p:" << *p << " *(p + 1):" 
	<< *(p + 1) << endl;
```
out:
```c++
pointer of arr[10] size:10
p -> *p p:0000007B73F7F398 *p:1 *(p + 1):2
```
ͨ��ָ����� p ��������Ԫ��ʱ��ʹ�õ��ǵ���ָ��*p�����Ƚ�ָ�� p ָ��ĵ�ַ����������
��ͨ�� * ����������ʸõ�ַ�д洢��ֵ��\*(p + 1)�У�p+1ָ������ָ��p�ĵ�ַ���ƶ�һ��int�ĳ���
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
����ָ��q��ָ�������ָ�룬�����Ա�ʾ�������飬�����������������Ԫ�ء���ˣ�q ������Ϊ int (*)[10]��
�� *q ��ʾָ�� q ָ��ĵ�ַ�д洢��ֵ�����������飬��� *q ������Ϊ int [10]�����������͡�
���**q ��ʾָ�� q ָ��ĵ�ַ�д洢��ֵ�����������Ԫ�ص�ֵ���� **q ������Ϊ int��

��ʹ������ָ��ʱ��ͨ����Ҫʹ��˫��ָ�� **q �����������е�Ԫ�أ���Ϊ����ָ��ָ������������飬
�������е�Ԫ�ؿ����Ǹ������ͣ���ṹ����࣬�����Ҫͨ��˫��ָ�������з��ʡ�
���磬����ʹ�� *(*q + i) ���������еĵ� i ��Ԫ�أ����� *q ��ʾ�������Ԫ�صĵ�ַ��
��ָ�� int ���͵�ָ�룬�� *(*q + i) ��ʾָ����� i ��ƫ��������ָ��ĵ�ַ�д洢��ֵ��
�������еĵ� i ��Ԫ�ص�ֵ��

- ��ά����

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
��������

>��ά����ָ��
```c++
// int** ���
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
int** ����ʾָ���ά�����ָ�룬��һ��ָ�����飬ÿ��ָ��ָ��һ��һά���顣

���ŵ��ǿ��Զ�̬����ռ䣬ÿ��һά����Ĵ�С���Բ�ͬ��
ȱ������Ҫ��ζ�̬������ͷ��ڴ棬���׳�����������ָ�������ÿ�� int ���͵����鶼�ǵ�������ģ�
�����������ڴ棬��˿��ܻ�Ӱ�����ܺͻ��������ʣ�������ָ���ƶ������������
```c++
// int*[] ���
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
int*[] ����ʾ��ά���������ָ�룬��һ�����飬ÿ��Ԫ����һ��ָ��һά�����ָ�롣

���ŵ���ֻ��Ҫ��̬����һ���ڴ棬����ָ���ƶ������������Ҳ�Ƚ�������⡣
ȱ����ÿ��һά����Ĵ�С������ͬ�������ڶ�̬�ı��С��Ҳ��̫�ʺϴ洢ϡ�����Ȳ��������ݽṹ��
```c++
// int(*)[] ���
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
int(*)[]����ʾ��ά����ָ�룬��һ��ָ�룬ָ��һ����ά���顣

���ŵ���ֻ��Ҫ��̬����һ���ڴ棬����ָ���ƶ������������Ҳ�Ƚ�������⣬����ÿ��ά�ȵĴ�С���Բ�ͬ���ʺϴ洢���������ݽṹ��
ȱ������Ҫʹ��new[]��delete[]��������ͷ��ڴ棬��΢��Щ���㡣

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
��һά��������ָ�����ƣ�p��ʾ��������ĵ�ַ��*(p + k)��ʾ��k���������ڵĵ�ַ����&arr[k]��
**(p + k)��ʾ��k���������Ԫ�أ���arr[k][0]��\*(\*(p + k) + b)��ʾarr[k][b]����(k, b)��Ԫ�ء�

�����˻�
```c++
int a[2];            // ���� 2 �� int Ԫ�ص�����
int* p1 = a;         // �˻���ָ�� a ����Ԫ�ص�ָ��
 
int b[2][3];         // ���� 2 �������� 3 �� int Ԫ�ص����顿Ԫ�ص�����
// int** p2 = b;     // ����b ���˻��� int**
int (*p2)[3] = b;    // b �˻���ָ�� b ���׸� 3 Ԫ���е�ָ��
 
int c[2][3][4];      // ���� 2 �������� 3 �������� 4 �� int Ԫ�ص����顿Ԫ�ص����顿Ԫ�ص�����
// int*** p3 = c;    // ����c ���˻��� int***
int (*p3)[3][4] = c; // c �˻���ָ�� c �׸� 3 �� 4 Ԫ��ƽ���ָ��
```

δ֪�߽�����

���Թ��ɵ�δ֪�߽���������ú�ָ�룬�����ܴ���֪�߽�������ָ����֪�߽������ָ��������г�ʼ����ֵ��
ע���� C ��������У�ָ��δ֪�߽������ָ����ָ����֪�߽������ָ����ݣ��Ӷ�����˫��ת���͸�ֵ��

```c++
extern int a1[];
int (&r1)[] = a1;  // OK
int (*p1)[] = &a1; // OK
int (*q)[2] = &a1; // ���󣨵� C �� OK��
 
int a2[] = {1, 2, 3};
int (&r2)[] = a2;  // ����
int (*p2)[] = &a2; // ���󣨵� C �� OK��
```
ָ��δ֪�߽������ָ�벻�ܲ���ָ�������Ҳ��������±����������࣬�����Խ����á�
��δ֪�߽���������ú�ָ���޷���Ϊ�����βΡ�

```c++
extern int x[];      // x �������ǡ��߽�δ֪�ĺ��� int Ԫ�ص����顱
int a[] = {1, 2, 3}; // a �������ǡ����� 3 �� int Ԫ�ص����顱

extern int a[][2]; // OK���߽�δ֪�ĺ��С����� 2 �� int Ԫ�ص����顿Ԫ�ص�����
extern int b[2][]; // ���������в���������
```
���������������ʡ�Ա��ʽ���������������ǡ�T ��δ֪�߽����顱������һ�ֲ��������ͣ�����������ʱ���оۺϳ�ʼ���� extern

��Ϊ����Ԫ�ز��ܾ���δ֪�߽��������ͣ����Զ�ά����ֻ���ڵ�һ��ά������δ֪�߽硣

- 2 �ַ���

\* �˴�ΪC-style string��\<string>�����뿴[�˴�]

```c++
char charray[8] = { 'g','r','e','a','t','d','a','y'};	// �ַ�����
char string0[8] = { 'h','o','l','i','d','a','y','\0'};	// �ַ���
char string1[] = "enjoy!!";								// �Դ�\0��ʵ�ʳ���8 + 2
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
ch array print ins:greatday������������������������holiday print div:greatday type:char [8] size:10
string:holiday type:char [8] size:10
```