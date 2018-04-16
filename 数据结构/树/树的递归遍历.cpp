#include<iostream>
using namespace std;

typedef char TElemType;
typedef int status;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


void PreOrderTraverse(BiTree T)
{
	if(T)
	{
		cout<<T->data;
	    PreOrderTraverse(T->lchild);
	    PreOrderTraverse(T->rchild);
	}
    
} 

void InOrderTraverse(BiTree T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
	    cout<<T->data;
	    InOrderTraverse(T->rchild);
	}
	
}

void PostOrderTraverse(BiTree T)
{
	if(T)
	{
		PostOrderTraverse(T->lchild);
	    PostOrderTraverse(T->rchild);
	    cout<<T->data;
	}
	
}


int main()
{
	BiTree T;
	char ch;
	cout<<"�����������:"<<endl; 
	cin>>ch;
	cout<<"���������Ϊ:"<<endl;
	PreOrderTraverse(T);
	cout<<"���������Ϊ:"<<endl;
	InOrderTraverse(T);
	cout<<"���������Ϊ:"<<endl;
	PostOrderTraverse(T);
	return 0; 
}
