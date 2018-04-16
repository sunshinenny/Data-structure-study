#include<iostream>
using namespace std;
#include<stdlib.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int ElemType;
typedef int Status;

#define MAXSIZE 100
typedef struct
{
	ElemType *elem;
	int front;
	int rear;
	char *name;
}SqQueue;

//初始化
Status  InitQueue(SqQueue &Q);
//求循环队列长度
int QueueLength(SqQueue Q);
//确认数据所在位置 
int FindQueue(SqQueue Q,int number);
//入队·病历号 
Status EnQueue_number(SqQueue &Q,ElemType e);
//入队·患者姓名
Status EnQueue_name(SqQueue &Q,char name[]);
//出队
Status DeQueue(SqQueue &Q);
//取循环队列队头元素
ElemType GetHead(SqQueue Q); 
//判断队列是否为空
Status QueueEmpty(SqQueue Q); 

//----------------------------
int main()
{
	int a,number;
	char name[20];
	SqQueue Q;
	while(1)
	{
		cout<<"******************医院排号管理系统******************"<<endl;
		cout<<"*                                                  *"<<endl;
		cout<<"*	1.上班		2.候诊		3.就诊	   *"<<endl;	
		cout<<"*                                                  *"<<endl;		
		cout<<"*	4.查看排队	5.查看就诊	0.下班	   *"<<endl;
		cout<<"*                                                  *"<<endl;		
		cout<<"****************************************************"<<endl;
	
		cout<<"请输入您的选项：";
		cin>>a;
		
		switch(a)
		{
			case 1:{
				InitQueue(Q);
				if(InitQueue(Q)==OK) cout<<"欢迎您上班"<<endl;
				system("pause");
				system("cls");
			};break;
			
			case 2:{
				cout<<"请输入您的病历号："<<endl;
				cin>>number;
				if(EnQueue_number(Q,number)==OK) cout<<"候诊成功"<<endl;
				/*cout<<"请输入您的姓名"<<endl;
				cin>>name[20];
				EnQueue_name(Q,name);*/
				system("pause");
				system("cls");
			};break;
			
			case 3:{
				if(DeQueue(Q)==OK)	cout<<"已成功就诊，请下一位做好准备"<<endl;
				else cout<<"请继续等待"<<endl;
				system("pause");
				system("cls");
			};break;
			
			
			
			case 4:{
				if(QueueEmpty(Q)!=1)
				{					
					cout<<"请输入您的病历号："<<endl;
					cin>>number;
					cout<<"您前面还有"<<FindQueue(Q,number)-Q.front<<"人"<<endl; 
					cout<<"他们的病历号和姓名为："<<endl;
					for(int i=Q.front;i<=FindQueue(Q,number)-1;i++)
					{
						cout<<Q.elem[i]<<"   "<<endl;//Q.name[i]<<endl;
					}
				}
				else if(QueueEmpty(Q)==1)cout<<"无人排队"<<endl;
				
				system("pause");
				system("cls");	
			};break;
			
			case 5:{
				if(QueueEmpty(Q)==1)
				{
					cout<<"无人候诊"<<endl;
				}
				else if(QueueEmpty(Q)==-1)
				{
					cout<<"总共还有"<<QueueLength(Q)<<"人"<<endl;
				}
				system("pause");
				system("cls");
			};break;
			
			case 0:{
				if(QueueEmpty(Q)!=1) 
				{
					cout<<"还有人未就诊，请就诊后再试"<<endl;
					system("pause");
					system("cls"); 
				}
				else 
				{
					cout<<"下班成功"<<endl;
					system("pause");
					return 0;
				}
			}
				
			default:{
				cout<<"输入错误，请重试"<<endl;
				system("pause");
				system("cls");
				};	
			}
	}
	
}
//-----------------------------

//初始化
Status  InitQueue(SqQueue &Q)
{
	Q.elem=new ElemType[MAXSIZE];
	if(!Q.elem) 
	{
		cout<<"操作失败"<<endl;
		exit(OVERFLOW);
	}
	Q.front=Q.rear=0;
	return OK;
}
//求循环队列长度
int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
//确认数据所在位置
int FindQueue(SqQueue Q,int number)
{
	int i,flag=1;
	for(i=Q.front;i<=Q.rear;i++)
	{
		if(number==Q.elem[i]) return i;
		else flag=0;
	}
	if(flag==0) 
	{
		cout<<"无此数据"<<endl;
		return ERROR;
	}
} 
//入队·病历号 
Status EnQueue_number(SqQueue &Q,ElemType e)
{
	if((Q.rear+1)%MAXSIZE==Q.front) return ERROR;
	Q.elem[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}
/*入队·患者姓名
Status EnQueue_name(SqQueue &Q,char name[])
{
	if((Q.rear+1)%MAXSIZE==Q.front) return ERROR;
	Q.name[Q.rear]=name;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}*/
//出队
Status DeQueue(SqQueue &Q)
{
	ElemType e;
	if(Q.front==Q.rear) return ERROR;
	e=Q.elem[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}
//取循环队列队头元素
ElemType GetHead(SqQueue Q)
{
	if(Q.front!=Q.rear)
		return Q.elem[Q.front]; 
}
//判断队列是否为空
Status QueueEmpty(SqQueue Q)
{
	if(Q.front==Q.rear) return 1;
	else return -1;
}
