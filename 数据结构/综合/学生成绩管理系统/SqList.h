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

Status InitList(SqList &L);//顺序表 
Status Input(SqList &L,int i);//输入内容到顺序表 
void Output(SqList L,int i);//单行输出顺序表的内容
void ShowRecord(SqList L);//全部按列输出 
void InitRecord(SqList &L);//创建顺序表与输入内容 
