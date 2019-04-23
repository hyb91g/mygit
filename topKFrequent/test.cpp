#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <functional> // std::greater
using namespace std;

class Solution {
private:
	vector<string> v;
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> m;
		for (auto e : words)
		{
			//auto it = m.find(e);
			//if (it != m.end())
			//{
			//	it->second += 1;
			//}
			//else
			//	m.insert(make_pair(e, 1));

			//auto ret = m.insert(make_pair(e, 1)); 
			//if (!ret.second)
			//{
			//	ret.first->second++;
			//}

			m[e]++;
		}
		
		//方法一
		//while (k--)
		//{
		//	int max = 0;
		//	string st;
		//	for (auto e : m)
		//	{
		//		if (e.second > max)
		//		{
		//			st = e.first;
		//			max = e.second;
		//		}
		//	}
		//	v.push_back(st);
		//	m.erase(st);
		//}

		//方法二：借助multimap并设置第三个模板参数为greater
		//K可以重复，且从大到小排序
		multimap<int, string, greater<int>> sort_map;
		for (const auto& e : m)
		{
			sort_map.insert(make_pair(e.second, e.first));
		}

		vector<string> v;
		auto it = sort_map.begin();
		while (it != sort_map.end() && k-- != 0)
		{
			v.push_back(it->second);
			++it;
		}

		return v;
	}
};

int main()
{
	vector<string> v;
	v.push_back("the");
	v.push_back("day");
	v.push_back("is");
	v.push_back("sunny");
	v.push_back("day");
	v.push_back("day");
	v.push_back("is");
	v.push_back("is");
	v.push_back("is");
	v.push_back("sunny");




	Solution s;
	vector<string> vs = s.topKFrequent(v, 4);
	for (auto e : vs)
	{
		cout << e << endl;
	}
	return 0;
}