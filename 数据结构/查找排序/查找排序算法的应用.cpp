/*
���������⣺
1.�۰������Ҫ���������������ʱ�����������������ʱ������������
2.��������������һ��
3.��д����Ŀ��ʱ�������һ��makefile.win�ļ�����
4. 
*/

#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string>
#include<iomanip> //�����ʽ�� ,���ж���,set(���) 

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
Status InitList(SqList &L);//˳��� 
Status Input(SqList &L,int i);//�������ݵ�˳��� 
void Output(SqList L,int i);//�������˳��������
void ShowRecord(SqList L);//ȫ��������� 
void InitRecord(SqList &L);//����˳������������� 
//���Һ��� 
int SearchByName(SqList L,string key);//˳���������ʵ�ֺ��� 
void Search_Seq(SqList L);//˳����������ܺ��� 
int SearchNumber(SqList L,int num);//�۰����ʵ�ֺ��� 
void Search_Bin(SqList L);//�۰�����ܺ��� 
//������
void InsertSort(SqList &L);//ֱ�Ӳ�����������ʵ�ֺ��� 
void InsertSort_show(SqList &L); //ֱ�Ӳ������������ܺ��� 
void BubbleSort(SqList &L);//ֱ��ѡ���������ݽṹ�ɼ�ʵ�ֺ��� 
void BubbleSort_show(SqList &L);//ֱ��ѡ���������ݽṹ�ɼ��ܺ��� 
//�������� 
int Partition(SqList &L,int low,int high);//��������ʵ�ֺ���3
void QSort(SqList &L,int low,int high);//��������ʵ�ֺ���2
void QuickSort(SqList &L);//��������ʵ�ֺ���1
void QuickSort_show(SqList &L);//���������ܺ��� 
//-----------------------------------------------------------------------
int main()
{
	SqList L;
	int ch;
	while(1)
	{
		cout<<"***********ѧ���ɼ�����ϵͳ***********"<<endl; 
		cout<<"*	1.��Ϣ��ʼ��	2.˳�����(name)*"<<endl; 
		cout<<"*	3.���ֲ���(num)	4.ֱ�Ӳ�������	*"<<endl; 
		cout<<"*	5.ð�ݻ�ѡ������6.��������		*"<<endl; 
		cout<<"*	0.�˳�							*"<<endl; 
		cout<<"**************************************"<<endl; 
		cout<<"��ѡ����Ҫ���еĲ���:(plase choice what are you want:)"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:InitRecord(L); break;//������Ϣ��ʼ������
			case 2:Search_Seq(L);break;//����˳�����  Search_Seq(L)
			case 3:Search_Bin(L);break;//���ö��ֲ���   Search_Bin(L)			    
			case 4:InsertSort_show(L);break;//����ֱ�Ӳ��뺯��   InsertSort(L) 	
			case 5:BubbleSort_show(L); break;//����ѡ�������� 
			case 6:QuickSort_show(L);break;//���ÿ��������� 
			case 0:return 0;
		} 
		system("pause");
		system("cls");
	} 
	
	
	return 0;
} 

//-------------------------------------------------
//˳��� 
Status InitList(SqList &L)
{//��ʼ��˳��� 
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem) return ERROR;
	L.length=1;
	return OK;
}

Status Input(SqList &L,int i)  
{//�������ݵ�˳��� 
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
{//˳����ܺ������������������룬��� 
	int i,N;
	InitList(L);
	cout<<"������ѧ������:(please input studens number:)";cin>>N;
	cout<<"����������ѧ����ѧ�ţ����������ݽṹ�ɼ���������Ƴɼ�:��please input student's number,name,grade1,grade2:'��"<<endl;
	for(i=1;i<=N;i++)
	{
		Input(L,i);
	}	
	cout<<"��¼��ϢΪ:(the record is:)"<<endl;
	/*for(i=1;i<=N;i++)
	{
		Output(L,i);
		cout<<endl;
	}*/ 
	ShowRecord(L);
}

void Output(SqList L,int i)
{//�������˳��������
	cout<<L.elem[i].key.num<<" "<<L.elem[i].key.name<<" "<<L.elem[i].key.grade1<<" "<<L.elem[i].key.grade2<<endl;
}

void ShowRecord(SqList L)
{//�������˳������� 
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
//���Һ��� 
int SearchByName(SqList L,string nm)
{//˳���������ʵ�ֺ��� 
	for(int i=L.length;i>=0;i--)
		if(L.elem[i].key.name==nm) return i;
	return 0;
}

void Search_Seq(SqList L)
{//˳����������ܺ��� 
	int i; string nm;//����Ҫ���ҵ�ѧ������nm
	cout<<"�����������ѧ��������(please input the student's name who are you want to search:)";cin>>nm;
	i=SearchByName(L,nm);   //���ò��Һ��������ؽ��
	if(i==0)
	{   
	  cout<<"û�и��û�(sorry,can't find the student)"<<endl;//��ʾδ�ҵ��� 
	} 
	else
	{
		Output(L,i);//����ҵ���ѧ����Ϣ
	} 
}

int SearchNumber(SqList L,int num)
{//�۰���������ʵ�ֺ��� 
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
{//�۰����������ܺ���						
	int i;int num;//����Ҫ���ҵ�ѧ������nm
	cout<<"�����������ѧ��������(please input the student's name who are you want to search:)";cin>>num;
	i=SearchNumber(L,num);   //���ò��Һ��������ؽ��
	if(i==0)
	{
	  cout<<"û�и��û�(sorry,can't find the student)"<<endl;//��ʾδ�ҵ��� 
	} 
	else
	{
		Output(L,i);//����ҵ���ѧ����Ϣ
	} 
 }

//-----------------------------------------------------------------------
//������
void InsertSort(SqList &L)
{//ֱ�Ӳ�����������ʵ�ֺ��� 
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
{//ֱ�Ӳ������������ܺ��� 
	cout<<"����ǰ:(Before Sort)"<<endl;
	ShowRecord(L);
	
	InsertSort(L);
	
	cout<<"�����(After Sort)"<<endl;
	ShowRecord(L);
}

void BubbleSort(SqList &L)
{//ֱ��ѡ���������ݽṹ�ɼ�ʵ�ֺ��� 
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
{////ֱ��ѡ���������ݽṹ�ɼ��ܺ��� 
	cout<<"����ǰ:(Before Sort)"<<endl;
	ShowRecord(L);
	
	BubbleSort(L);
	
	cout<<"�����(After Sort)"<<endl;
	ShowRecord(L);
}

/*
7��ʹ�ÿ������򷽷�����ѧ����Ϣ�еĳ�����Ƴɼ����������������ǰ��������ѧ����Ϣ����֤��������*/ 
int Partition(SqList &L,int low,int high)
{//��������ʵ�ֺ���3 
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
{//��������ʵ�ֺ���2 
	int pivotloc;
	if(low<high)
	{
		pivotloc=Partition(L,low,high);
		QSort(L,low,pivotloc-1);
		QSort(L,pivotloc+1,high);
	}
}

void QuickSort(SqList &L)
{//��������ʵ�ֺ���1 
	QSort(L,1,L.length);
}

void QuickSort_show(SqList &L)
{////ֱ��ѡ���������ݽṹ�ɼ��ܺ��� 
	cout<<"����ǰ:(Before Sort)"<<endl;
	ShowRecord(L);
	
	QuickSort(L);
	
	cout<<"�����(After Sort)"<<endl;
	ShowRecord(L);
}
