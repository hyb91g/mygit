#include"HashBacket.h"

void TestHB()
{
	HashBacket hb;
	HBInit(&hb, 53);
	HBInsert(&hb, 5, 1);
	HBInsert(&hb, 15, 1);
	HBInsert(&hb, 25, 1);

	for (int i = 0; i < 100; i++)
	{
		HBInsert(&hb, rand(), 1);
	}
	HBPrint(&hb);
	if (HBRemove(&hb, 14) == 1)
		HBPrint(&hb);

}

int main()
{
	TestHB();
	return 0;
}