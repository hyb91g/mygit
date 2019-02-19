#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int HTKeyType;
typedef int HTValueType;

typedef enum State
{
	EMPTY,
	EXIST,
	DELETE
}State;

typedef struct HashData
{
	HTKeyType key;
	HTValueType value;
	State state;
}HashData;

typedef struct HashTable
{
	HashData* _tables;
	int _size; //数据个数
	int _len;  //长度
}HashTable;

void HTInit(HashTable* ht, int len);
void HTDestroy(HashTable* ht);

void HTInsert(HashTable* ht, HTKeyType key, HTValueType value);
void HTRemove(HashTable* ht, HTKeyType key);

HashData HTFind(HashTable* ht, HTKeyType key);

int HTSize(HashTable* ht);
int HTEmpty(HashTable* ht);
void PrintHT(HashTable* ht);

