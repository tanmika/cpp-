#include<iostream>
#include<vector>
#include <thread>
#include <mutex>

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
	std::cout << *it << std::endl;
	v.push_back(5);
	// std::cout << *it; undefind!

	// vector无线程安全性
	std::vector<int> tv;
	tv.reserve(2000);
	auto lam = [](std::vector<int>* v)
	{
		for (size_t i = 0; i < 1000; i++)
		{
			v->push_back(i);
		}
	};
	std::thread t1(lam, &tv);
	std::thread t2(lam, &tv);
	t1.join();
	t2.join();
	std::cout << tv.size() << std::endl;
	// less than 2000
	// thread safe -> 1
	tv.resize(0);
	tv.shrink_to_fit();
	tv.reserve(2000);
	std::mutex mtx;
	auto lam_mutex_safe = [](std::mutex* mtx, std::vector<int>* v)
	{
		for (size_t i = 0; i < 1000; i++)
		{
			mtx->lock();
			v->push_back(i);
			mtx->unlock();
		}
	};
	std::thread t3(lam_mutex_safe, &mtx, &tv);
	std::thread t4(lam_mutex_safe, &mtx, &tv);
	t3.join();
	t4.join();
	std::cout << tv.size() << std::endl;
	// 2000


	return 0;
}
