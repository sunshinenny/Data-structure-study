//#include"main.h"
#include"SqList.h"

Status InitList(SqList &L)
{//初始化顺序表 
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem) return ERROR;
	L.length=0;
	return OK;
}

Status Input(SqList &L,int i)  
{//输入内容到顺序表 
	int num;	string name;	double grade1,grade2;
	if(i>L.length||i<0) return ERROR;
	
	cin>>num;
	L.elem[i].key.num=num;
	cin>>name;
	L.elem[i].key.name=name;
	cin>>grade1;
	L.elem[i].key.grade1=grade1;	
	cin>>grade2;
	L.elem[i].key.grade2=grade2;
	++L.length;
	return OK;
}

void InitRecord(SqList &L)
{
	int i;
	InitList(L);
	cout<<"请依次输入学生的学号，姓名，数据结构成绩，程序设计成绩:"<<endl;
	for(i=0;i<3;i++)
	{
		Input(L,i);
	}	
	cout<<"记录信息为:"<<endl;
/*	for(i=0;i<3;i++)
	{
		Output(L,i);
		cout<<endl;
	}	*/
	ShowRecord(L);
}

void Output(SqList L,int i)
{//单行输出顺序表的内容
	cout<<L.elem[i].key.num<<" "<<L.elem[i].key.name<<" "<<L.elem[i].key.grade1<<" "<<L.elem[i].key.grade2;
}

void ShowRecord(SqList L)
{
	cout<<""<<L.length<<""<<endl;
	for(int i=0;i<L.length;i++)
	{
		cout<<setw(4)<<L.elem[i].key.num<<endl;
		cout<<setw(8)<<L.elem[i].key.name<<endl;
		cout<<setw(8)<<L.elem[i].key.grade1<<endl;
		cout<<setw(8)<<L.elem[i].key.grade2<<endl;
	}	
}

 
