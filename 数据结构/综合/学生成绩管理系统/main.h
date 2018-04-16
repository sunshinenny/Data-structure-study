#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string>
#include<iomanip>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 20
typedef int Status;

typedef struct
{
	int num;
	string name;
	int grade1;
	int grade2;
}KeyType;

typedef struct
{
	KeyType key;
//	InfoType otherinfo;
 } ElemType;
 
/*typedef struct
{
	ElemType *R;
	int length;
} SSTable;*/

typedef struct
{
	ElemType *elem;
	int length;
} SqList;

