#include<iostream>
#include<vector>

auto main() -> int
{
	// vector的动态分配
	std::vector<int> v;
	v.reserve(100); // 预留100个元素的空间
	std::cout << v.size() << " " << v.capacity() << std::endl;
	//0 <- 使用空间, 100 <- 预留空间
	v.resize(0); // 重置使用空间为0
	v.shrink_to_fit();
	for (size_t i = 0; i < 100; ++i)
	{
		v.push_back(i); // 增加元素
	}
	std::cout << v.size() << " " << v.capacity() << std::endl;

	// vector的动态分配带来的迭代器失效
	v.resize(5);
	v.shrink_to_fit();
	std::vector<int>::iterator it = v.begin() + 4;
	std::cout << *it;
	v.push_back(5);
	std::cout << *it;

	return 0;
}
