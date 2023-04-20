# Container

## vector

- 1 vector底层使用动态数组实现，其内存分配策略是每次申请一段比
当前容量更大的内存空间，并将原数据复制到新空间中，因此会产生
内存分配和复制数据的开销。为了避免频繁地分配内存，vector一般会
预留一定的容量，即capacity()，当需要插入的元素数量大于当前容量时，
才会重新分配内存空间。

```c++
	std::vector<int> v;
	v.reserve(100); // 预留100个元素的空间
	std::cout<<v.size()<<" " <<v.capacity()<<std::endl;
```
使用空间：0，预留空间：100
```c++
	v.resize(0); // 重置使用空间为0
	v.shrink_to_fit();
	for (size_t i = 0; i < 100; ++i)
	{
		v.push_back(i); // 增加元素
	}
	std::cout << v.size() << " " << v.capacity() << std::endl;
```
使用空间：100，预留空间：141

- 2 vector::push_back()的复杂度是摊线性的，也就是 O(1) 的均摊复杂度，
因为它的实现方式是在 vector 的末尾添加一个元素。
在大部分情况下，push_back() 的时间复杂度是 O(1)，但是当 vector 内存不足时，
需要重新分配内存，这时就需要把原有的元素复制到新的内存空间中，
时间复杂度变为 O(N)，其中 N 为元素个数。但是这种情况的出现是比较少见的，
因为 vector 通常会在分配内存时预留一定的空间，以避免频繁地重新分配内存。

- 3 数据访问：vector的数据是存储在一块连续的内存空间中，因此支持随机访问，
可以通过下标运算符[]或者迭代器访问数据。
由于数据是连续存储的，所以访问速度相对于链表等数据结构较快。

- 4 安全性：由于vector的内存分配策略，可能会导致在扩容时迭代器和指针失效，
因此需要注意迭代器和指针的有效性。
```c++
	std::vector<int>::iterator it = v.begin() + 4;
	std::cout << *it;
	v.push_back(5);
	// std::cout << *it; undefind!
```
- 5 无线程安全性：std::vector不是线程安全的，因为它的内部并没有实现
对于并发操作的保护机制，即多个线程同时修改 vector 的同一部分可能会
导致数据不一致或崩溃等问题。
```c++
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
	std::cout << tv.size();
	// less than 2000
```
解决方案：
- 使用互斥锁（std::mutex）或其他同步机制保护 vector 的操作，
确保同一时刻只有一个线程可以对其进行读写操作。
```c++
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
```
