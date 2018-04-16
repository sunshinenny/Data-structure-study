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
	int top;
}SqStack;

//��ʼ��
Status InitStack(SqStack &S); 
//��ջ 
Status Push(SqStack &S,ElemType e);
//��ջ
Status Pop(SqStack &S,ElemType &e); 
//ȡջ��Ԫ��
ElemType GetTop(SqStack S);
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(SqStack S); 
//����ջ
void StackTraverse(SqStack S);
//-----------------------------------------------------------

int main()
{
	int n,e;
	SqStack S;
	while(1)
	{
		cout<<"**************************************************************************************"<<endl;
		cout<<"1.��ʼ��ջ   2.��ջ   3.��ջ   4.ȡջ��Ԫ��   5.����ջ   6.�ж�ջ�Ƿ�Ϊ��   0.���Ƽ���"<<endl; 
		cout<<"**************************************************************************************"<<endl<<"��ѡ��:";
		cin>>n;
		
		switch(n)
		{
			case 1:{InitStack(S);
					if(InitStack(S)==OK) cout<<"��ʼ���ɹ�"<<endl;
					else cout<<"��ʼ��ʧ�� ������"<<endl;
					system("pause");
					system("cls");
					};break;
					
			case 2:{
					cout<<"�����룺";
					cin>>e;
					Push(S,e); 
					if(Push(S,e)==OK) cout<<"��ջ�ɹ�"<<endl;
					else cout<<"��ջʧ�� ������"<<endl;
					system("pause");
					system("cls");
					};break;
					
			case 3:	{
					Pop(S,e); 
					if(Pop(S,e)==OK) cout<<"��ջ�ɹ�"<<endl;
					else cout<<"��ջʧ�� ������"<<endl;
					system("pause");
					system("cls");
					};break;
					
			case 4:	{
					cout<<"ջ��Ԫ��Ϊ��"<<endl<<GetTop(S)<<endl; 
					system("pause");
					system("cls");
					};break;	
			
			case 5:	{
					cout<<"����ջΪ��"<<endl;
/*					cout<<StackTraverse(S)<<endl; */
					system("pause");
					system("cls");
					};break;
					
			case 6:{
					if(StackEmpty(S)==true) cout<<"NO empty";
					else cout<<"Is empty";
					system("pause");
					system("cls");
					};break;
			
			default:{cout<<"��������������"<<endl;
						system("pause");
						system("cls");
					};
									
		}
	}
	return 0;
}


//----------------------------------------------------------- 
//��ʼ��
Status InitStack(SqStack &S)
{
	S.elem=new ElemType[MAXSIZE];
	if(!S.elem) return ERROR;
	S.top=-1;
	return OK;
}
//��ջ 
Status Push(SqStack &S,ElemType e)
{
	if(S.top==MAXSIZE-1) return ERROR;
	S.top++;
	S.elem[S.top]=e;
	return OK;
}
//��ջ
Status Pop(SqStack &S,ElemType &e)
{
	if(S.top==-1)return ERROR;
	e=S.elem[S.top];
	S.top--;
	return OK;
}
//ȡջ��Ԫ��
ElemType GetTop(SqStack S)
{
	ElemType e;
	if(S.top==-1) return ERROR;
	e=S.elem[S.top];
	
	return e;
}
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(SqStack S)
{
	if(S.top==-1) return false;
	else return true;
}
//����ջ
void StackTraverse(SqStack S)
{
	ElemType e;
	if(S.top==-1) {cout<<"����һ����ջ"; exit;} 
	
	while(S.top!=-1)
	{
		e=GetTop(S);
		cout<<GetTop(S);
		Pop(S,e);
	}
}
