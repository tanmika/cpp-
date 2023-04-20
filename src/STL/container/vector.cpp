#include<iostream>
#include<vector>

auto main() -> int
{
	// vector�Ķ�̬����
	std::vector<int> v;
	v.reserve(100); // Ԥ��100��Ԫ�صĿռ�
	std::cout << v.size() << " " << v.capacity() << std::endl;
	//0 <- ʹ�ÿռ�, 100 <- Ԥ���ռ�
	v.resize(0); // ����ʹ�ÿռ�Ϊ0
	v.shrink_to_fit();
	for (size_t i = 0; i < 100; ++i)
	{
		v.push_back(i); // ����Ԫ��
	}
	std::cout << v.size() << " " << v.capacity() << std::endl;

	// vector�Ķ�̬��������ĵ�����ʧЧ
	v.resize(5);
	v.shrink_to_fit();
	std::vector<int>::iterator it = v.begin() + 4;
	std::cout << *it;
	v.push_back(5);
	std::cout << *it;

	return 0;
}
