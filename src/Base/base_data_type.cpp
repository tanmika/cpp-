#include<iostream>
#include<limits>

using std::cout;
using std::endl;

auto main() -> int
{
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
	return 0;
}
