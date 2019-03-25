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

	//���ö�������+ȥ��
	//std::set<int>::iterator it1 = s1.begin();
	//while (it1 != s1.end())
	//{
	//	std::cout << *it1 << " ";
	//	//*it *= 2;  //���Ǵ�ģ������������޸�
	//	++it1;
	//}
	//std::cout << std::endl;
	for (auto e : s1)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	//����1��find
	int x;
	std::cin >> x;
	//s1.erase(x);  //ֱ��ɾ
	auto retit = s1.find(x);
	if (retit != s1.end())
	{
		std::cout << x << "��set������" << std::endl;
		s1.erase(retit);  //�ҵ���ɾ����ɾ����Ч�ĵ�����
	}
	else
		std::cout << x << "����set������" << std::endl;
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
	//dict.insert(std::pair<std::string, std::string>("insert", "����"));
	//dict.insert(std::pair<std::string, std::string>("hello", "���"));
	//dict.insert(std::pair<std::string, std::string>("erase", "ɾ��"));
	//std::map<std::string, std::string>::iterator dit = dict.begin();
	//while (dit != dict.end())
	//{
	//	std::cout << (*dit).first << ":" << (*dit).second << std::endl;
	//	dit++;
	//}
	//typedef std::map<std::string, std::string> Dict;
	//typedef std::map<std::string, std::string>::iterator DictIt;
	//Dict dict;
	//dict.insert(std::make_pair("insert", "����"));
	//dict.insert(std::make_pair("hello", "���"));
	//dict.insert(std::make_pair("erase", "ɾ��"));
	//dict.insert(std::make_pair("left", "���"));
	//DictIt dit = dict.begin();
	//while (dit != dict.end())
	//{
	//	//std::cout << (*dit).first << ":" << (*dit).second << std::endl;
	//	std::cout << dit->first << ":" << dit->second << std::endl;
	//	dit++;
	//}

	//����K�ڲ���
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
	//		std::cout << str << "���ڴʿ���" << std::endl;
	//	}
	//}

	////�޸�V
	////auto it = dict.find("left");
	////if (it != dict.end())
	////{
	////	it->second = "���/ʣ��";
	////}
	//dict["left"] = "���/ʣ��";
	//for (const auto& e : dict)
	//{
	//	std::cout << e.first << ":" << e.second << std::endl;
	//}


	//ͳ�ƴ���
	std::string str_arr[] = { "sort", "hello", "sort", "insert", "sort", "hello" };
	typedef std::map<std::string, int> ContMap;
	typedef std::map<std::string, int>::iterator ContMapIt;
	ContMap cont_map;
	for (const auto& e : str_arr)
	{
		//����һ��
		//ContMapIt it = cont_map.find(e);
		//if (it != cont_map.end())
		//{
		//	it->second += 1;
		//}
		//else
		//	cont_map.insert(make_pair(e, 1));

		//������������insert
		//auto ret = cont_map.insert(make_pair(e, 1));   //���ڲ���Ϥinsert������˵��auto�������Ǹ�ȱ�ݡ�
		//if (!ret.second)
		//{
		//	ret.first->second++;
		//}

		//������
		cont_map[e]++;   //operator[]����insertʵ�ֵģ��Ȳ��룬�ٶ�д
	}
}

int main()
{
	//test_set();
	//���ã�
	//1.key��ģ�ͳ������ж��ڲ���
	//2.����+ȥ��

	//test_multiset();
	//���������������ظ�

	test_map();
	return 0;
}