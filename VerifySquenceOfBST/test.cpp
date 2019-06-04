#include <iostream>
#include <vector>
using namespace std;
bool IsBST(vector<int>& sequence, int begin, int end, int num)
{
	if (begin == end)
		return true;
	//左子树都比num小
	int i = begin;
	for (; i < end; ++i)
	{
		if (sequence[i] > num)
			break;
	}
	//右子树都比num大
	int j = i;
	for (; j < end; ++j)
	{
		if (sequence[j] < num)
			return false;
	}

	bool left = true;
	if (i > begin)  //左
	{
		left = IsBST(sequence, begin, i-1, sequence[i - 1]);
	}
	bool right = true;
	if (i < end)
	{
		if(i == begin)
			right = IsBST(sequence, i, end-1, sequence[end-1]);
		else
			right = IsBST(sequence, i, end, sequence[end]);

	}

	return left&&right;
}

bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.empty())
		return false;
	int root = sequence.back();
	return IsBST(sequence, 0, sequence.size()-1, root);
}

int main()
{
	vector<int> v = { 4,6,9,3,2,1 };
	cout << VerifySquenceOfBST(v) << endl;
	return 0;
}