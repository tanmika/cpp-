#include<iostream>
#include<limits>
#include<typeinfo>
using std::cout;
using std::endl;

auto main() -> int
{
	// 整型类型
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
	// 字面量
	int dec_num = 42;
	int hex_num = 0x42;
	int oct_num = 042;
	cout << dec_num << " " << hex_num << " " << oct_num << endl;
	cout << std::hex;
	cout << hex_num << endl;
	cout << std::oct;
	cout << oct_num << endl;
	// 溢出
	cout << endl;
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
	cout << endl;

	// 字符类型
	// char
	char c = 'a';	//使用单引号赋值字符
	cout << sizeof(char) << endl;
	// 输出
	cout << c << " " << 'a' << " ";
	cout.put('a') << endl;
	// 字面量
	char dec_c = 77;
	char hex_c = '\x4d';
	char oct_c = '\115';
	cout << dec_c << " " << hex_c << " " << oct_c << endl;
	// wchar_t
	wchar_t wc = L'好';
	cout << sizeof(wchar_t) << endl;
	// char16_t
	char16_t c16 = u'好';
	cout << sizeof(char16_t) << endl;
	// char32_t
	char32_t c32 = U'好';
	cout << sizeof(char32_t) << endl;
	cout << endl;

	// 浮点类型
	// 浮点型空间大小
	cout << sizeof(float) << endl;
	cout << sizeof(double) << endl;
	cout << sizeof(long double) << endl;
	// 浮点型范围
	cout << "float:" << std::numeric_limits<float>::min() << "~" << std::numeric_limits<float>::max() << endl;
	cout << "double : " << std::numeric_limits<double>::min() << "~" << std::numeric_limits<double> ::max() << endl;
	cout << "long double : " << std::numeric_limits<long double>::min() << "~" << std::numeric_limits<long double> ::max() << endl;
	// 浮点型精度
	cout << "float precision:" << std::numeric_limits<float>::digits << endl;
	cout << "double precision:" << std::numeric_limits<double>::digits << endl;
	cout << "long double precision:" << std::numeric_limits<long double>::digits << endl;
	// 科学计数法下数值为浮点型
	auto f_small = 3.14e-30;
	auto f_huge = 3.14e30;
	cout << f_small << ":" << typeid(f_small).name() << endl;
	cout << f_huge << ":" << typeid(f_huge).name() << endl;
	cout << endl;

	// 布尔类型
	bool b = true;
	cout << sizeof(bool)<<endl;
	cout << b << endl;
	// 字面量
	bool b_true_p = true + 1;
	bool b_true_n = true - 1;
	bool b_false_p = false + 1;
	bool b_false_n = false - 1;
	cout << b_true_p << " " << b_true_n << " " << b_false_p << " " << b_false_n << endl;
	cout << endl;

	// 复合数据类型
	// 数组
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "arr:" << arr << " &arr[0]:" << &arr[0] << " *arr:" << *arr << " *(arr + 1):" << *(arr + 1) << " arr[10] size:" << sizeof(arr) << endl;
	// 指针
	int *p = arr;
	cout << "pointer of arr[10] size:" << sizeof(p) << "\np -> *p p:" << p << " *p:" << *p << " *(p + 1):" << *(p + 1) << endl;
	int(*q)[] = &arr;
	cout << "pointer of arr[10] size:" << sizeof(q) << "\nq -> (*q)[] q:" << q << " *q:" << *q << " **q:" << **q << " *(*q + 1):" << *(*q + 1) << endl;
	// 引用
	int &r = arr[0];
	cout << "reference of arr[0] size:" << sizeof(r) << endl;
	// 多维数组
	int arr2[3][3] = {0};
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
	return 0;
}