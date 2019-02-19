#include"HashTable.h"

static const unsigned long _PrimeList[28] =
{
53,         97,         193,       389,       769,
1543,       3079,       6151,      12289,     24593,
49157,      98317,      196613,    393241,    786433,
1572869,    3145739,    6291469,   12582917,  25165843,
50331653,   100663319,  201326611, 402653189, 805306457,
1610612741, 3221225473, 4294967291
};

void HTInit(HashTable* ht, int len)
{
	int i = 0;
	ht->_tables = (HashData*)malloc(sizeof(HashData)*len);
	ht->_len = len;
	ht->_size = 0;
	for (i; i < len; i++)
	{
		ht->_tables[i].state = EMPTY;
		ht->_tables[i].value = 0;
	}
}

void HTDestroy(HashTable* ht)
{
	assert(ht);
	free(ht->_tables);
	ht->_len = 0;
	ht->_size = 0;
}

int calc(HashTable* ht, HTKeyType key)
{
	return key % ht->_len;
}
int PrimeList = 0;
void InCapacity(HashTable* ht)
{
	HashTable cur;
	//HTInit(&cur, ht->_len * 2);
	if (ht->_size == _PrimeList[PrimeList])
	{
		PrimeList += 1;
		HTInit(&cur, _PrimeList[PrimeList]);
		int i = 0;
		//cur._tables = realloc(ht->_tables, sizeof(HashData)*cur._len);
		for (i; i < ht->_len; i++)
		{
			if (ht->_tables[i].value == EXIST)
				HTInsert(&cur, ht->_tables[i].key, ht->_tables[i].value);
		}
		HTDestroy(ht);

		ht->_len = cur._len;
		ht->_size = cur._size;
		ht->_tables = cur._tables;
	}
	else
		return;
}


void HTInsert(HashTable* ht, HTKeyType key, HTValueType value)
{
	assert(ht);
	InCapacity(ht);
	
	int ret = calc(ht, key);
	while (ht->_tables[ret].state == EXIST && ht->_tables[ret].key != key)
	{
		ret++;
		if (ret == ht->_len)
			ret = 0;
	}
	if (ht->_tables[ret].key == key)
		return;
	ht->_tables[ret].key = key;
	ht->_tables[ret].state = EXIST;
	ht->_tables[ret].value = value;

	ht->_size++;

}

void HTRemove(HashTable* ht, HTKeyType key)
{
	assert(ht);
	int ret = calc(ht, key);
	if (ht->_tables[ret].key == key && ht->_tables[ret].state == EXIST)
	{
		ht->_size--;
		ht->_tables[ret].state = DELETE;
		ht->_tables[ret].value--;
	}
	else if (ht->_tables[ret].key != key)
	{
		while (ht->_tables[ret].key != key)
		{
			ret++;
		}
		ht->_size--;
		ht->_tables[ret].state = DELETE;
		ht->_tables[ret].value--;
	}
	else
		return;
}

HashData HTFind(HashTable* ht, HTKeyType key)
{
	assert(ht);
	int ret = calc(ht, key);
	if (ht->_tables[ret].key == key && ht->_tables[ret].state == EXIST)
		return ht->_tables[ret];
	else if (ht->_tables[ret].key != key)
	{
		while (ht->_tables[ret].key != key)
		{
			ret++;
		}
		return ht->_tables[ret];
	}
	else
		return;
}

int HTSize(HashTable* ht)
{
	assert(ht);
	return ht->_size;
}

int HTEmpty(HashTable* ht)
{
	assert(ht);
	if (ht->_size == 0)
		return 0;
	else
		return 1;
}

void PrintHT(HashTable* ht)
{
	int i = 0;
	char* state[] = { "EMPTY", "EXIST", "DELETE" };
	assert(ht);
	for (i; i < ht->_len; i++)
	{
		//if(ht->_tables[i].state == EXIST)
			printf("tables[%d]%s:%d\n", i, state[ht->_tables[i].state], ht->_tables[i].key);
	}
	printf("\n");
}