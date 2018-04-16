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

//初始化
Status InitStack(SqStack &S); 
//入栈 
Status Push(SqStack &S,ElemType e);
//出栈
Status Pop(SqStack &S,ElemType &e); 
//取栈顶元素
ElemType GetTop(SqStack S);
//判断栈是否为空
int StackEmpty(SqStack S); 
//遍历栈
void StackTraverse(SqStack S);
//-----------------------------------------------------------

int main()
{
	int n,e;
	SqStack S;
	while(1)
	{
		cout<<"**************************************************************************************"<<endl;
		cout<<"1.初始化栈   2.入栈   3.出栈   4.取栈顶元素   5.遍历栈   6.判断栈是否为空   0.进制计算"<<endl; 
		cout<<"**************************************************************************************"<<endl<<"请选择:";
		cin>>n;
		
		switch(n)
		{
			case 1:{InitStack(S);
					if(InitStack(S)==OK) cout<<"初始化成功"<<endl;
					else cout<<"初始化失败 请重试"<<endl;
					system("pause");
					system("cls");
					};break;
					
			case 2:{
					cout<<"请输入：";
					cin>>e;
					Push(S,e); 
					if(Push(S,e)==OK) cout<<"入栈成功"<<endl;
					else cout<<"入栈失败 请重试"<<endl;
					system("pause");
					system("cls");
					};break;
					
			case 3:	{
					Pop(S,e); 
					if(Pop(S,e)==OK) cout<<"出栈成功"<<endl;
					else cout<<"出栈失败 请重试"<<endl;
					system("pause");
					system("cls");
					};break;
					
			case 4:	{
					cout<<"栈顶元素为："<<endl<<GetTop(S)<<endl; 
					system("pause");
					system("cls");
					};break;	
			
			case 5:	{
					cout<<"遍历栈为："<<endl;
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
			
			default:{cout<<"输入有误，请重试"<<endl;
						system("pause");
						system("cls");
					};
									
		}
	}
	return 0;
}


//----------------------------------------------------------- 
//初始化
Status InitStack(SqStack &S)
{
	S.elem=new ElemType[MAXSIZE];
	if(!S.elem) return ERROR;
	S.top=-1;
	return OK;
}
//入栈 
Status Push(SqStack &S,ElemType e)
{
	if(S.top==MAXSIZE-1) return ERROR;
	S.top++;
	S.elem[S.top]=e;
	return OK;
}
//出栈
Status Pop(SqStack &S,ElemType &e)
{
	if(S.top==-1)return ERROR;
	e=S.elem[S.top];
	S.top--;
	return OK;
}
//取栈顶元素
ElemType GetTop(SqStack S)
{
	ElemType e;
	if(S.top==-1) return ERROR;
	e=S.elem[S.top];
	
	return e;
}
//判断栈是否为空
int StackEmpty(SqStack S)
{
	if(S.top==-1) return false;
	else return true;
}
//遍历栈
void StackTraverse(SqStack S)
{
	ElemType e;
	if(S.top==-1) {cout<<"这是一个空栈"; exit;} 
	
	while(S.top!=-1)
	{
		e=GetTop(S);
		cout<<GetTop(S);
		Pop(S,e);
	}
}
