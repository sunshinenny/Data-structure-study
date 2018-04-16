/*
遇到的问题：
1.折半查找需要有序表，我们在做的时候是先排序还是输入的时候就输入成有序？
2.按列输出多输出了一行
3.当写成项目的时候出现了一个makefile.win文件出错
4. 
*/

#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string>
#include<iomanip> //输出格式化 ,按列对齐,set(宽度) 

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef struct
{
	int num;
	string name;
	int grade1;
	int grade2;
} KeyType;

typedef struct
{
	KeyType key;
//	InfoType otherinfo;
 } ElemType;
 
typedef struct
{
	ElemType *R;
	int length;
} SSTable;

typedef struct
{
	ElemType *elem;
	int length;
} SqList;
//-------------------------------------------------
Status InitList(SqList &L);//顺序表 
Status Input(SqList &L,int i);//输入内容到顺序表 
void Output(SqList L,int i);//单行输出顺序表的内容
void ShowRecord(SqList L);//全部按列输出 
void InitRecord(SqList &L);//创建顺序表与输入内容 
//查找函数 
int SearchByName(SqList L,string key);//顺序查找姓名实现函数 
void Search_Seq(SqList L);//顺序查找姓名总函数 
int SearchNumber(SqList L,int num);//折半查找实现函数 
void Search_Bin(SqList L);//折半查找总函数 
//排序函数
void InsertSort(SqList &L);//直接插入排序姓名实现函数 
void InsertSort_show(SqList &L); //直接插入排序姓名总函数 
void BubbleSort(SqList &L);//直接选择排序数据结构成绩实现函数 
void BubbleSort_show(SqList &L);//直接选择排序数据结构成绩总函数 
//快速排序 
int Partition(SqList &L,int low,int high);//快速排序实现函数3
void QSort(SqList &L,int low,int high);//快速排序实现函数2
void QuickSort(SqList &L);//快速排序实现函数1
void QuickSort_show(SqList &L);//快速排序总函数 
//-----------------------------------------------------------------------
int main()
{
	SqList L;
	int ch;
	while(1)
	{
		cout<<"***********学生成绩管理系统***********"<<endl; 
		cout<<"*	1.信息初始化	2.顺序查找(name)*"<<endl; 
		cout<<"*	3.二分查找(num)	4.直接插入排序	*"<<endl; 
		cout<<"*	5.冒泡或选择排序6.快速排序		*"<<endl; 
		cout<<"*	0.退出							*"<<endl; 
		cout<<"**************************************"<<endl; 
		cout<<"请选择所要进行的操作:(plase choice what are you want:)"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:InitRecord(L); break;//调用信息初始化函数
			case 2:Search_Seq(L);break;//调用顺序查找  Search_Seq(L)
			case 3:Search_Bin(L);break;//调用二分查找   Search_Bin(L)			    
			case 4:InsertSort_show(L);break;//调用直接插入函数   InsertSort(L) 	
			case 5:BubbleSort_show(L); break;//调用选择排序函数 
			case 6:QuickSort_show(L);break;//调用快速排序函数 
			case 0:return 0;
		} 
		system("pause");
		system("cls");
	} 
	
	
	return 0;
} 

//-------------------------------------------------
//顺序表 
Status InitList(SqList &L)
{//初始化顺序表 
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem) return ERROR;
	L.length=1;
	return OK;
}

Status Input(SqList &L,int i)  
{//输入内容到顺序表 
	int num;	string name;	double grade1,grade2;
	if(i>L.length||i<1) return ERROR;
	
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
{//顺序表总函数，包含创建，输入，输出 
	int i,N;
	InitList(L);
	cout<<"请输入学生人数:(please input studens number:)";cin>>N;
	cout<<"请依次输入学生的学号，姓名，数据结构成绩，程序设计成绩:（please input student's number,name,grade1,grade2:'）"<<endl;
	for(i=1;i<=N;i++)
	{
		Input(L,i);
	}	
	cout<<"记录信息为:(the record is:)"<<endl;
	/*for(i=1;i<=N;i++)
	{
		Output(L,i);
		cout<<endl;
	}*/ 
	ShowRecord(L);
}

void Output(SqList L,int i)
{//单行输出顺序表的内容
	cout<<L.elem[i].key.num<<" "<<L.elem[i].key.name<<" "<<L.elem[i].key.grade1<<" "<<L.elem[i].key.grade2<<endl;
}

void ShowRecord(SqList L)
{//按列输出顺序表内容 
//	cout<<""<<L.length<<""<<endl;
	for(int i=1;i<=L.length;i++)
	{
		cout<<setw(4)<<L.elem[i].key.num;
		cout<<setw(8)<<L.elem[i].key.name;
		cout<<setw(8)<<L.elem[i].key.grade1;
		cout<<setw(8)<<L.elem[i].key.grade2;
		cout<<endl;
	}	
}

 
//-----------------------------------------------------------------------
//查找函数 
int SearchByName(SqList L,string nm)
{//顺序查找姓名实现函数 
	for(int i=L.length;i>=0;i--)
		if(L.elem[i].key.name==nm) return i;
	return 0;
}

void Search_Seq(SqList L)
{//顺序查找姓名总函数 
	int i; string nm;//输入要查找的学生姓名nm
	cout<<"请输入想查找学生姓名：(please input the student's name who are you want to search:)";cin>>nm;
	i=SearchByName(L,nm);   //调用查找函数，返回结果
	if(i==0)
	{   
	  cout<<"没有该用户(sorry,can't find the student)"<<endl;//提示未找到！ 
	} 
	else
	{
		Output(L,i);//输出找到的学生信息
	} 
}

int SearchNumber(SqList L,int num)
{//折半查找有序表实现函数 
	int low,high,mid;
	low=1;high=L.length;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(num==L.elem[mid].key.num) return mid;
		else if(num<L.elem[mid].key.num) high=mid-1;
		else low=mid+1;	
	}
	return 0;
}
void Search_Bin(SqList L)
{//折半查找有序表总函数						
	int i;int num;//输入要查找的学生姓名nm
	cout<<"请输入想查找学生姓名：(please input the student's name who are you want to search:)";cin>>num;
	i=SearchNumber(L,num);   //调用查找函数，返回结果
	if(i==0)
	{
	  cout<<"没有该用户(sorry,can't find the student)"<<endl;//提示未找到！ 
	} 
	else
	{
		Output(L,i);//输出找到的学生信息
	} 
 }

//-----------------------------------------------------------------------
//排序函数
void InsertSort(SqList &L)
{//直接插入排序姓名实现函数 
	int i,j;
	for(i=2;i<=L.length;i++)
		if(L.elem[i].key.name<L.elem[i-1].key.name)
		{
			L.elem[0]=L.elem[i];
			for(j=i-1;L.elem[0].key.name<L.elem[j].key.name;j--)
			{
					L.elem[j+1]=L.elem[j];
			}
			L.elem[j+1]=L.elem[0];
		}
 }

void InsertSort_show(SqList &L)
{//直接插入排序姓名总函数 
	cout<<"排序前:(Before Sort)"<<endl;
	ShowRecord(L);
	
	InsertSort(L);
	
	cout<<"排序后：(After Sort)"<<endl;
	ShowRecord(L);
}

void BubbleSort(SqList &L)
{//直接选择排序数据结构成绩实现函数 
	int m,j,flag,t;
	m=L.length-1;flag=1;
	while((m>0)&&(flag==1))
	{
		flag=0;
		for(j=1;j<=m;j++)
			if(L.elem[j].key.grade1>L.elem[j+1].key.grade1)
			{
				flag=1;
				t=L.elem[j].key.grade1;L.elem[j].key.grade1=L.elem[j+1].key.grade1;L.elem[j+1].key.grade1=t;
			}
			--m;
	}
 } 
void BubbleSort_show(SqList &L)
{////直接选择排序数据结构成绩总函数 
	cout<<"排序前:(Before Sort)"<<endl;
	ShowRecord(L);
	
	BubbleSort(L);
	
	cout<<"排序后：(After Sort)"<<endl;
	ShowRecord(L);
}

/*
7．使用快速排序方法，对学生信息中的程序设计成绩进行排序。输出排序前和排序后的学生信息表，验证排序结果。*/ 
int Partition(SqList &L,int low,int high)
{//快速排序实现函数3 
	int pivotkey;
	L.elem[0]=L.elem[low];
	pivotkey=L.elem[low].key.grade2;
	while(low<high)
	{
		while(low<high&&L.elem[high].key.grade2>=pivotkey) --high;
		L.elem[low]=L.elem[high];
		while(low<high&&L.elem[low].key.grade2<=pivotkey) ++low;
		L.elem[high]=L.elem[low];
	}
	L.elem[low]=L.elem[0];
	return low;
}

void QSort(SqList &L,int low,int high)
{//快速排序实现函数2 
	int pivotloc;
	if(low<high)
	{
		pivotloc=Partition(L,low,high);
		QSort(L,low,pivotloc-1);
		QSort(L,pivotloc+1,high);
	}
}

void QuickSort(SqList &L)
{//快速排序实现函数1 
	QSort(L,1,L.length);
}

void QuickSort_show(SqList &L)
{////直接选择排序数据结构成绩总函数 
	cout<<"排序前:(Before Sort)"<<endl;
	ShowRecord(L);
	
	QuickSort(L);
	
	cout<<"排序后：(After Sort)"<<endl;
	ShowRecord(L);
}
