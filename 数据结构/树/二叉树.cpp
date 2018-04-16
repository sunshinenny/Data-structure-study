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
{//按先序次序输入二叉树中节点的值（一个字符），创建二叉链表表示的二叉树T 
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
{//先序遍历递归算法 
	if(T==NULL) return;
	cout<<(char)T->data;
	PreOrderTravers(T->lchild);
	PreOrderTravers(T->rchild);
}

void InOrderTravers(BiTree T)
{//中序遍历递归算法 
	if(T)
	{	
		InOrderTravers(T->lchild);
		cout<<(char)T->data;
		InOrderTravers(T->rchild);
	} 
}

void PostOrderTravers(BiTree T)
{//后序遍历递归算法 
	if(T)
	{	
		PostOrderTravers(T->lchild);
		PostOrderTravers(T->rchild);
		cout<<(char)T->data;
	} 
} 

void LevelOrderTravers(BiTNode *T)  
{//层次遍历二叉树
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
{//计算二叉树T的深度 
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
{//统计二叉树T中结点的个数
 	if(T==NULL) return 0;
 	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

void visit(BiTree T)
{//四种遍历法遍历二叉树 
	cout<<endl<<"PreOrder:";//先序 
	PreOrderTravers(T);	
	cout<<endl<<"InOrder:";//中序 
	InOrderTravers(T); 
	cout<<endl<<"PostOrder:";//后序 
	PostOrderTravers(T);
	cout<<endl<<"LevelOrder:";//层次 
	LevelOrderTravers(T);
	cout<<endl;	
} 

void Exchange(BiTree &T)
{//交换左右结点 
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
{//初始化队列 
	Q.elem=new ElemType[MAXSIZE];
	if(!Q.elem) 
	{
		cout<<"操作失败"<<endl;
		exit(OVERFLOW);
	}
	Q.front=Q.rear=0;
	return OK;
}

Status EmptyQueue(SqQueue Q)
{//判断队列是否为空 
	if(Q.front==Q.rear) return 1;
	else return -1;
}
 
Status EnQueue(SqQueue &Q,char ch)
{//入队
	if((Q.rear+1)%MAXSIZE==Q.front) return ERROR;
	Q.elem[Q.rear]=ch;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}
Status DeQueue(SqQueue &Q)
{//出 队 
	ElemType e;
	if(Q.front==Q.rear) return ERROR;
	e=Q.elem[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}*/

/*void LevelOrderTravers(BiTree T)
{//层次遍历二叉树 
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
