#include<iostream>
using namespace std;
#include<stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


Status  InitQueue(SqQueue &Q);
Status EmptyQueue(SqQueue Q);
Status EnQueue(SqQueue &Q,char T);
Status DeQueue(SqQueue &Q);
void CreateBiTree(BiTree &T);
void PreOrderTravers(BiTree T);
void InOrderTravers(BiTree T);
void PostOrder_exchange(BiTree T);
void LevelOrderTravers(BiTNode *T);
int Depth(BiTree T);
int NodeCount(BiTree T);
void Exchange(BiTree &T);
void visit(BiTree T);

int main()
{
	BiTNode *T;
	cout<<"Please Input some words:"<<endl;
	CreateBiTree(T);

	visit(T); 
	cout<<endl;	
	cout<<"Depth="<<Depth(T)<<endl;
	cout<<"Count number="<<NodeCount(T)<<endl;
	cout<<endl;
	cout<<"After Exchange"; 
	Exchange(T);
	visit(T); 
	return 0;
}

//------------------------------------------------------------------------------
void CreateBiTree(BiTree &T)
{//�������������������нڵ��ֵ��һ���ַ������������������ʾ�Ķ�����T 
	char ch;
	cin>>ch;
	if(ch=='#') T=NULL;
	else
	{
		T=new BiTNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

void PreOrderTravers(BiTree T)
{//��������ݹ��㷨 
	if(T==NULL) return;
	cout<<(char)T->data;
	PreOrderTravers(T->lchild);
	PreOrderTravers(T->rchild);
}

void InOrderTravers(BiTree T)
{//��������ݹ��㷨 
	if(T)
	{	
		InOrderTravers(T->lchild);
		cout<<(char)T->data;
		InOrderTravers(T->rchild);
	} 
}

void PostOrderTravers(BiTree T)
{//��������ݹ��㷨 
	if(T)
	{	
		PostOrderTravers(T->lchild);
		PostOrderTravers(T->rchild);
		cout<<(char)T->data;
	} 
} 

void LevelOrderTravers(BiTNode *T)  
{//��α���������
    BiTNode *p;  
    BiTNode *Q[MAXSIZE];  
    int front,rear;  
    front=rear=-1;  
    rear++;  
    Q[rear]=T;  
    while(front!=rear)  
    {  
        front=(front+1)%MAXSIZE;  
        p=Q[front];  
        cout<<(char)p->data;  
  
        if(p->lchild!=NULL)  
        {  
            rear=(rear+1)%MAXSIZE;  
            Q[rear]=p->lchild;  
        }  
  
        if(p->rchild!=NULL)  
        {  
            rear=(rear+1)%MAXSIZE;  
            Q[rear]=p->rchild;  
        }  
    }  
} 

int Depth(BiTree T)
{//���������T����� 
	int m,n;
	if(T==NULL) return 0;
	else 
	{
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n) return (m+1);
		else return (n+1);
	}
}

int NodeCount(BiTree T)
{//ͳ�ƶ�����T�н��ĸ���
 	if(T==NULL) return 0;
 	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

void visit(BiTree T)
{//���ֱ��������������� 
	cout<<endl<<"PreOrder:";//���� 
	PreOrderTravers(T);	
	cout<<endl<<"InOrder:";//���� 
	InOrderTravers(T); 
	cout<<endl<<"PostOrder:";//���� 
	PostOrderTravers(T);
	cout<<endl<<"LevelOrder:";//��� 
	LevelOrderTravers(T);
	cout<<endl;	
} 

void Exchange(BiTree &T)
{//�������ҽ�� 
	BiTNode *t=NULL;
	if(T==NULL)
		return;
	else
	{
		t=T->lchild;
		T->lchild=T->rchild;
		T->rchild=t;
		
		if(T->lchild)		Exchange(T->lchild);
		if(T->rchild)		Exchange(T->rchild);		
	}

}


/*typedef struct
{
	ElemType *elem;
	int front;
	int rear;
	char *ch;
}SqQueue;*/

/*Status  InitQueue(SqQueue &Q)
{//��ʼ������ 
	Q.elem=new ElemType[MAXSIZE];
	if(!Q.elem) 
	{
		cout<<"����ʧ��"<<endl;
		exit(OVERFLOW);
	}
	Q.front=Q.rear=0;
	return OK;
}

Status EmptyQueue(SqQueue Q)
{//�ж϶����Ƿ�Ϊ�� 
	if(Q.front==Q.rear) return 1;
	else return -1;
}
 
Status EnQueue(SqQueue &Q,char ch)
{//���
	if((Q.rear+1)%MAXSIZE==Q.front) return ERROR;
	Q.elem[Q.rear]=ch;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}
Status DeQueue(SqQueue &Q)
{//�� �� 
	ElemType e;
	if(Q.front==Q.rear) return ERROR;
	e=Q.elem[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}*/

/*void LevelOrderTravers(BiTree T)
{//��α��������� 
	SqQueue Q;
	InitQueue(Q);
	if(T==NULL) return;
	EnQueue(Q,T);
	BiTNode *p;
	while(!EmptyQueue(Q))
	{
		DeQueue(Q,p);
		cout<<p->data;
		if(p->lchild)
		InitQueue(Q,p->lchild);
		if(p->rchild)
		InitQueue(Q,p->rchild);
	}	
}*/
