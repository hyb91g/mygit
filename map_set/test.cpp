#include<iostream>
#include<set>
#include<map>
#include<string>

void test_set()
{
	std::set<int> s1;
	s1.insert(10);
	s1.insert(1);
	s1.insert(7);
	s1.insert(7);
	s1.insert(7);
	s1.insert(5);
	s1.insert(5);
	s1.insert(16);

	//作用二：排序+去重
	//std::set<int>::iterator it1 = s1.begin();
	//while (it1 != s1.end())
	//{
	//	std::cout << *it1 << " ";
	//	//*it *= 2;  //这是错的，搜索树不能修改
	//	++it1;
	//}
	//std::cout << std::endl;
	for (auto e : s1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	//作用1：find
	int x;
	std::cin >> x;
	//s1.erase(x);  //直接删
	auto retit = s1.find(x);
	if (retit != s1.end())
	{
		std::cout << x << "在set集合中" << std::endl;
		s1.erase(retit);  //找到后删除，删除有效的迭代器
	}
	else
		std::cout << x << "不在set集合中" << std::endl;
	for (auto e : s1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test_multiset()
{
	std::multiset<int> s2;
	s2.insert(10);
	s2.insert(1);
	s2.insert(7);
	s2.insert(7);
	s2.insert(7);
	s2.insert(5);
	s2.insert(5);
	s2.insert(16);
	for (auto e : s2)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	std::set<std::string> strs;
	strs.insert("hello");
	strs.insert("haha");
	strs.insert("bye");
	for (auto e : strs)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void test_map()
{
	//std::map<std::string, std::string> dict;
	//dict.insert(std::pair<std::string, std::string>("insert", "插入"));
	//dict.insert(std::pair<std::string, std::string>("hello", "你好"));
	//dict.insert(std::pair<std::string, std::string>("erase", "删除"));
	//std::map<std::string, std::string>::iterator dit = dict.begin();
	//while (dit != dict.end())
	//{
	//	std::cout << (*dit).first << ":" << (*dit).second << std::endl;
	//	dit++;
	//}
	//typedef std::map<std::string, std::string> Dict;
	//typedef std::map<std::string, std::string>::iterator DictIt;
	//Dict dict;
	//dict.insert(std::make_pair("insert", "插入"));
	//dict.insert(std::make_pair("hello", "你好"));
	//dict.insert(std::make_pair("erase", "删除"));
	//dict.insert(std::make_pair("left", "左边"));
	//DictIt dit = dict.begin();
	//while (dit != dict.end())
	//{
	//	//std::cout << (*dit).first << ":" << (*dit).second << std::endl;
	//	std::cout << dit->first << ":" << dit->second << std::endl;
	//	dit++;
	//}

	//查找K在不在
	//std::string str;
	//while (std::cin >> str)
	//{
	//	auto it = dict.find(str);
	//	if (it != dict.end())
	//	{
	//		std::cout << str << "->" << it->second << std::endl;
	//	}
	//	else
	//	{
	//		std::cout << str << "不在词库中" << std::endl;
	//	}
	//}

	////修改V
	////auto it = dict.find("left");
	////if (it != dict.end())
	////{
	////	it->second = "左边/剩余";
	////}
	//dict["left"] = "左边/剩余";
	//for (const auto& e : dict)
	//{
	//	std::cout << e.first << ":" << e.second << std::endl;
	//}


	//统计次数
	std::string str_arr[] = { "sort", "hello", "sort", "insert", "sort", "hello" };
	typedef std::map<std::string, int> ContMap;
	typedef std::map<std::string, int>::iterator ContMapIt;
	ContMap cont_map;
	for (const auto& e : str_arr)
	{
		//方法一：
		//ContMapIt it = cont_map.find(e);
		//if (it != cont_map.end())
		//{
		//	it->second += 1;
		//}
		//else
		//	cont_map.insert(make_pair(e, 1));

		//方法二：借助insert
		//auto ret = cont_map.insert(make_pair(e, 1));   //对于不熟悉insert的人来说，auto在这里是个缺陷。
		//if (!ret.second)
		//{
		//	ret.first->second++;
		//}

		//方法三
		cont_map[e]++;   //operator[]借助insert实现的，先插入，再读写
	}
}

int main()
{
	//test_set();
	//作用：
	//1.key的模型场景，判断在不在
	//2.排序+去重

	//test_multiset();
	//场景：排序、允许重复

	test_map();
	return 0;
}