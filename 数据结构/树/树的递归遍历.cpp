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
	cout<<"请输入二叉树:"<<endl; 
	cin>>ch;
	cout<<"先序遍历后为:"<<endl;
	PreOrderTraverse(T);
	cout<<"中序遍历后为:"<<endl;
	InOrderTraverse(T);
	cout<<"后序遍历后为:"<<endl;
	PostOrderTraverse(T);
	return 0; 
}
