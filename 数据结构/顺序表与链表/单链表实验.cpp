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
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//��ʼ��
Status InitList(LinkList &L);
//���
void OutList(LinkList &L); 
//����
Status ListInsert(LinkList &L,int i,ElemType e);
//ɾ��
Status ListDelete(LinkList &L,int i);
//���� 
void Sort(LinkList &L,LinkList &LB);
//ȡֵ
int GetElem(LinkList L,int min);
//������� 
void Fun(LinkList &L,int e);

int main()
{
	LNode *L,*LB;
	int i,e,flag;
	
	InitList(L);
	InitList(LB);
//�������-------------------------------------------
	cout<<"Please Input Some numbers:"<<endl;
	for(i=1;i<=6;i++)
	{
		cin>>e;
		ListInsert(L,i,e);
	}

	OutList(L);

	
//���β���3��21��15��99�ĸ������ֱ�����ڵ�1��8��4��12λ�ã�ÿ����һ�ζ�Ҫ���һ�ε�����
	e=3,i=1;
	cout<<"��3���뵽��1��λ��"<<endl;
	flag=ListInsert(L,i,e);	
	if(flag==ERROR) cout<<"����ʧ��"<<endl;
	OutList(L);	
	
	e=21,i=8;
	cout<<"��21���뵽��8��λ��"<<endl;
	flag=ListInsert(L,i,e);	
	if(flag==ERROR) cout<<"����ʧ��"<<endl;
	OutList(L);

	e=15,i=4;
	cout<<"��15���뵽��4��λ��"<<endl;
	flag=ListInsert(L,i,e);	
	if(flag==ERROR) cout<<"����ʧ��"<<endl;
	OutList(L);	

	e=99,i=12;
	cout<<"��99���뵽��12��λ��"<<endl;
	flag=ListInsert(L,i,e);
	if(flag==ERROR) cout<<"����ʧ��"<<endl;
	OutList(L);	
//------------------------------------------------------------------	
//5��ɾ����1����9�͵�12��λ���ϵ�Ԫ�أ�ÿɾ��һ��Ԫ�ض�Ҫ���һ�ε�����	
	i=1;
	cout<<"ɾ����1��λ���ϵ�Ԫ��"<<endl;
	flag=ListDelete(L,i);	
	if(flag==ERROR) cout<<"ɾ��ʧ��"<<endl;
	OutList(L);	
	
	i=9;
	cout<<"ɾ����9��λ���ϵ�Ԫ��"<<endl;
	flag=ListDelete(L,i);	
	if(flag==ERROR) cout<<"ɾ��ʧ��"<<endl;
	OutList(L);

	i=12;
	cout<<"ɾ����12��λ���ϵ�Ԫ��"<<endl;
	flag=ListDelete(L,i);	
	if(flag==ERROR) cout<<"ɾ��ʧ��"<<endl;
	OutList(L);		
//��дһ�������㷨����������Ԫ�ش�С�������С�

	cout<<"��С��������Ϊ��"<<endl;	
	Sort(L,LB);	
//����������ֱ����20��50����������Ȼ����

	cout<<"�������20�����Ϊ��"<<endl;
	Fun(LB,20);
	OutList(LB);
	
	cout<<"�������50�����Ϊ��"<<endl;
	Fun(LB,50);
	OutList(LB);
	return 0;
}













//��ʼ��
Status InitList(LinkList &L)
{
	L=new LNode;
	L->next=NULL;
	return OK;
}

//���
void OutList(LinkList &L) 
{
	LNode *p;
	p=L->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl<<endl;
}
//����
Status ListInsert(LinkList &L,int i,ElemType e)
{
	LNode *p,*s;
	int j;
	
	p=L;j=0;
	while(p&&(j<i-1))
	{p=p->next;j++;}
	
	if(!p||j>i-1) return ERROR;
	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}
//ɾ��
Status ListDelete(LinkList &L,int i)
{
	LNode *p,*q;
	int j;
	
	p=L;j=0;
	while((p->next)&&(j<i-1))
	{p=p->next;j++;}
	
	if(!(p->next)||j>i-1) return ERROR;
	q=p->next;
	p->next=q->next;
	delete q;
	return OK;
}
//����
void Sort(LinkList &L,LinkList &LB)
{
	LNode *p;
	InitList(LB);
	int i=1,t,min;

	p=L->next;
	while(p!=NULL)
	{
		min=p->data;
		while(p!=NULL)
		{	

			if(p->data<min) 
			{
				min=p->data;
			}
			p=p->next;
		}
		p=L->next; 
		ListDelete(L,GetElem(L,min));		
		ListInsert(LB,i,min);
		i++;
		p=L->next;
		
	}
	OutList(LB);	
}


//ȡֵ
int GetElem(LinkList L,int min)
{
	LNode *p;
	int j;
	p=L->next;
	j=1;
	while(p!=NULL)													
	{
		if(p->data==min) break;
		j++;		
		p=p->next;
	}
	return j;
} 

//������� 
void Fun(LinkList &LB,int e)
{
	LNode *p;
	int i=0,flag;
	p=LB->next;
		
	while(p)
	{
		if(e>=p->data) flag=i+1;
		i++;
		p=p->next;
	}
	
	ListInsert(LB,flag+1,e);
}
