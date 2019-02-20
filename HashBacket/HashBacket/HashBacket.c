#include"HashBacket.h"

void HBInit(HashBacket* hb, int len)
{
	int i = 0;
	hb->_len = len;
	hb->_size = 0;
	hb->_tables = (HashNode**)malloc(sizeof(HashNode*)*len);
	for (i; i < len; i++)
	{
		hb->_tables[i] = NULL;
	}
	//memset(hb->_tables, NULL, sizeof(HashNode*)*len);
}

void HBDestory(HashBacket* hb)
{
	HashNode* cur, *del;
	assert(hb);
	hb->_len = 0;
	hb->_size = 0;
	for (int i = 0; i < hb->_len; i++)
	{
		cur = hb->_tables[i];
		if (cur)
		{
			while (cur)
			{
				del = cur;
				cur = cur->_next;
				free(del);
				del = NULL;
			}
		}
	}	
	free(hb->_tables);
}

int calc(Keytype key, int len)
{
	return key % len;
}

HashNode* BuyNode(Keytype key, Valuetype value)
{
	HashNode* newnode;
	newnode = (HashNode*)malloc(sizeof(HashNode));
	newnode->_key = key;
	newnode->_value = value;
	newnode->_next = NULL;
	return newnode;
}

void CheckHBCapacity(HashBacket* hb)
{
	assert(hb);
	if (hb->_size == hb->_len)
	{
		int i;
		HashBacket newhtb;
		newhtb._len = hb->_len*2;
		HBInit(&newhtb, newhtb._len);
		for (i = 0; i < hb->_len; ++i)
		{
			HashNode* cur = hb->_tables[i];
			while (cur)
			{
				HashNode* next = cur->_next;
				int index = calc(cur->_key, newhtb._len);

				cur->_next = newhtb._tables[index];
				newhtb._tables[index] = cur;

				cur = next;
			}

			hb->_tables[i] = NULL;
		}

		HBDestory(hb);

		hb->_tables = newhtb._tables;
		hb->_size = newhtb._size;
		hb->_len = newhtb._len;
	}
}

void HBInsert(HashBacket* hb, Keytype key, Valuetype value)
{
	int index;
	HashNode* newnode;
	assert(hb);
	CheckHBCapacity(hb);
	index = calc(key, hb->_len);
	newnode = BuyNode(key, value);
	//Í·²å
	newnode->_next = hb->_tables[index];
	hb->_tables[index] = newnode;
	hb->_size++;
}

int HBRemove(HashBacket* hb, Keytype key)
{
	HashNode* cur, *prev;
	int index;
	assert(hb);
	index = calc(key, hb->_len);
	cur = hb->_tables[index];
	prev = NULL;
	while (cur)
	{
		if (cur->_key == key)
		{
			if (prev == NULL)
			{
				hb->_tables[index] = NULL;
			}
			else
			{
				prev->_next = cur->_next;
			}
			free(cur);
			cur = NULL;
			hb->_size--;
			return 1;
		}
		prev = cur;
		cur = cur->_next;
	}
	return 0;
}

HashNode* HBFind(HashBacket* hb, Keytype key)
{
	HashNode* cur;
	int index;
	assert(hb);
	index = calc(key, hb->_len);
	cur = hb->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

int HBSize(HashBacket* hb)
{
	assert(hb);
	return hb->_size;
}

int HBEmpty(HashBacket* hb)
{
	assert(hb);
	return hb->_size == 0 ? 0 : 1;
}

void HBPrint(HashBacket* hb)
{
	HashNode* cur;
	assert(hb);
	for (int i = 0; i < hb->_len; i++)
	{
		cur = hb->_tables[i];
		printf("tables[%d]:", i);
		while (cur)
		{
			printf("%d->", cur->_key);
			cur = cur->_next;
		}
		printf("ÎÞ\n");
	}
	printf("\n");
}