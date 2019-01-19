#ifndef __CONTACT_H__
#define __CONTACT_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000
#define DEFAULT_SZ 3

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDRESS 10

#define FILENAME "contact.dat"

enum 
{
	EXIT,
	add,
	del,
	search,
	modify,
	show,
	empty,
	sort
};

typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char address[MAX_ADDRESS];
	short age;
	long long phone;
}PeoInfo, *pPeoInfo;

//typedef struct Contact
//{
//	PeoInfo date[MAX];
//	unsigned int sz;
//}Contact, *pContact;

typedef struct Contact
{
	pPeoInfo date;
	unsigned int sz;
	int capacity;
}Contact, *pContact;

void SaveContact(pContact pc);
void LoadContact(pContact pc);
void InitContact(pContact pc);
void CheckContact(pContact pc);
void DestoryContact(pContact pc);
void AddContact(pContact pc);
void DelContact(pContact pc);
void SearchContact(pContact pc);
void ShowContact(pContact pc);
void ModifyContact(pContact pc);
void EmptyContact(pContact pc);
void SortContact(pContact pc);

#endif // __CONTACT_H__
