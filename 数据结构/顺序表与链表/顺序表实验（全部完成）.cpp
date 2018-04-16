#include<iostream>
using namespace std;
#include<stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

#define MAXSIZE 100
typedef int ElemType;
typedef int Status;
typedef struct
{
	ElemType *elem;
	int length;
}SqList;

//��ʼ��
Status InitList(SqList &L);
//����
Status Input(SqList &L,int i,int e);
//���
void Output(SqList &L,int i); 
//ȡֵ
Status GetElem(SqList L,int i,ElemType &e);
/*int LocateElem(SqList L,ElemType e);//����
*/
//����
Status sort(SqList &L); 
//������� 
Status Fun(SqList &L,int e);
//����
Status ListInsert(SqList &L,int i,ElemType e);
//ɾ��
Status ListDelete(SqList &L,int i);
//---------------------------------------------------------------------------------------












int main()
{
	int i; 
	SqList L;
	ElemType e;
//����-------------------------	
	InitList(L);
	cout<<"���룺";
	for(i=0;i<6;i++)
	{
		cin>>e;
		Input(L,i,e);		
						
	}					 
	

//���------------------------- 
	cout<<"�����";
	for(i=0;i<L.length;i++)	Output(L,i); 
	cout<<endl;
//-----------------------------
	i=1,e=3;
	if(ListInsert(L,i,e)==OK)
		{
		 cout<<"����ɹ���"<<endl;
		 cout<<"���Ϊ��";
		for(i=0;i<L.length;i++)	Output(L,i); 
		cout<<endl;
		}
	else cout<<"����ʧ��"<<endl;
	
	i=8,e=21;
	if(ListInsert(L,i,e)==OK)
		{
		 cout<<"����ɹ���"<<endl;
		 cout<<"���Ϊ��";
		for(i=0;i<L.length;i++)	Output(L,i); 
		cout<<endl;
		}
	else cout<<"����ʧ��"<<endl;	
	
	i=4,e=15;
	if(ListInsert(L,i,e)==OK)
		{
		 cout<<"����ɹ���"<<endl;
		 cout<<"���Ϊ��";
		for(i=0;i<L.length;i++)	Output(L,i); 
		cout<<endl;
		}
	else cout<<"����ʧ��"<<endl;	
	
	i=12,e=99;
	if(ListInsert(L,i,e)==OK)
		{
		 cout<<"����ɹ���"<<endl;
		 cout<<"���Ϊ��";
		for(i=0;i<L.length;i++)	Output(L,i); 
		cout<<endl;
		}
	else cout<<"����ʧ��"<<endl;	
	
//------------------------------	
	i=1; 
	if(ListDelete(L,i)==OK)
		{
		 cout<<"ɾ���ɹ���"<<endl;
		 cout<<"���Ϊ��";
		for(i=0;i<L.length;i++)	Output(L,i); 
		cout<<endl;
		}
	else cout<<"ɾ��ʧ��"<<endl;	
	
	i=9; 
	if(ListDelete(L,i)==OK)
		{
		 cout<<"ɾ���ɹ���"<<endl;
		 cout<<"���Ϊ��";
		for(i=0;i<L.length;i++)	Output(L,i); 
		cout<<endl;
		}
	else cout<<"ɾ��ʧ��"<<endl;	

	i=12; 
	if(ListDelete(L,i)==OK)
		{
		 cout<<"ɾ���ɹ���"<<endl;
		 cout<<"���Ϊ��";
		for(i=0;i<L.length;i++)	Output(L,i); 
		cout<<endl;
		}
	else cout<<"ɾ��ʧ��"<<endl;	
//------------------------------
	sort(L);
	cout<<"�������Ϊ��"<<endl;//���� 
	for(i=0;i<L.length;i++)	Output(L,i); 
	cout<<endl;
//-------------------------------	
	cout<<"�������һ������"<<endl;
	Fun(L,20);                //������� 20
	cout<<"�������Ϊ��"<<endl;
	for(i=0;i<L.length;i++)	Output(L,i);
	cout<<endl;
	
	Fun(L,50);                //������� 50
	cout<<"�������Ϊ��"<<endl;
	for(i=0;i<L.length;i++)	Output(L,i);	
//--------------------------------
	return 0;
}















//��ʼ�� 
Status InitList(SqList &L)
{
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem) return ERROR;
	L.length=0;
	return OK;
}

//���� 
Status Input(SqList &L,int i,int e)  
{
	if(i>L.length||i<0) return ERROR;
	L.elem[i]=e;
	++L.length;
	return OK;
}

//���
void Output(SqList &L,int i)
{
	cout<<L.elem[i]<<" ";
}


//ȡֵ
Status GetElem(SqList L,int i,ElemType &e)
{
	if(i<1||i>L.length) return ERROR;
	e=L.elem[i-1];
	return OK;
}

//����
Status ListInsert(SqList &L,int i,ElemType e)
{
	int j;
	if((i<1)||(i>L.length+1)) return ERROR;
	if(L.length==MAXSIZE) return ERROR;
	for(j=L.length-1;j>=i-1;j--)
		L.elem[j+1]=L.elem[j];
	L.elem[i-1]=e;
	++L.length;
	return OK;	
}

//ɾ��
Status ListDelete(SqList &L,int i)
{
	if((i<1||i>L.length)) return ERROR;
	for(int j=1;j<=L.length;j++)
		L.elem[j-1]=L.elem[j];
	--L.length;
	return OK;	
} 

//���� 
Status sort(SqList &L)
{
	int i,j,t;
	for(i=0;i<L.length-1;i++)
	{
		for(j=0;j<L.length-1-i;j++)
		{
			if(L.elem[j]>L.elem[j+1])
			{
				t=L.elem[j];
				L.elem[j]=L.elem[j+1];
				L.elem[j+1]=t;
			}
		}
	}
	
}

//������� 
Status Fun(SqList &L,int e)
{
	int i,flag;
	for(i=0;i<L.length;i++)
	{
		if(e>=L.elem[i]) flag=i+1;
	}
	ListInsert(L,flag+1,e);
	return OK;
}
