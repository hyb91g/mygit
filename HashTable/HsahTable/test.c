#include"HashTable.h"

void TestHT()
{
	HTKeyType tables[53] = { 37, 25, 14, 36, 49, 68, 57, 11 };
	HashTable ht;
	int len = sizeof(tables) / sizeof(tables[0]);
	HTInit(&ht, len);
	HTInsert(&ht, 37, 1);
	HTInsert(&ht, 25, 1);
	HTInsert(&ht, 14, 1);
	HTInsert(&ht, 36, 1);
	HTInsert(&ht, 49, 1);
	HTInsert(&ht, 68, 1);
	HTInsert(&ht, 57, 1);
	HTInsert(&ht, 11, 1);
	HTInsert(&ht, 75, 1);
	HTInsert(&ht, 35, 1);
	HTInsert(&ht, 45, 1);
	HTInsert(&ht, 3, 1);
	for (int i = 0; i < 10000; i++)
	{
		HTInsert(&ht, rand(), i);
	}
	PrintHT(&ht);
	//printf("%d\n", HTFind(&ht, 14).key);
	HTRemove(&ht, 68);
	HTRemove(&ht, 14);
	HTRemove(&ht, 36);
	HTRemove(&ht, 57);
	PrintHT(&ht);

}


int main()
{
	TestHT();
	return 0;
}