#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef int Keytype;
typedef int Valuetype;

typedef struct HashNode
{
	Keytype _key;
	Valuetype _value;
	struct HashNode* _next;
}HashNode;

typedef struct HashBacket
{
	HashNode** _tables;
	int _size;
	int _len;
}HashBacket;

void HBInit(HashBacket* hb, int len);
void HBDestory(HashBacket* hb);

void HBInsert(HashBacket* hb, Keytype key, Valuetype value);
int HBRemove(HashBacket* hb, Keytype key);
HashNode* HBFind(HashBacket* hb, Keytype key);

int HBSize(HashBacket* hb);
int HBEmpty(HashBacket* hb);

void HBPrint(HashBacket* hb);
