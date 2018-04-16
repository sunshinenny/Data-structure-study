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

//��ʼ��
Status  InitQueue(SqQueue &Q);
//��ѭ�����г���
int QueueLength(SqQueue Q);
//ȷ����������λ�� 
int FindQueue(SqQueue Q,int number);
//��ӡ������� 
Status EnQueue_number(SqQueue &Q,ElemType e);
//��ӡ���������
Status EnQueue_name(SqQueue &Q,char name[]);
//����
Status DeQueue(SqQueue &Q);
//ȡѭ�����ж�ͷԪ��
ElemType GetHead(SqQueue Q); 
//�ж϶����Ƿ�Ϊ��
Status QueueEmpty(SqQueue Q); 

//----------------------------
int main()
{
	int a,number;
	char name[20];
	SqQueue Q;
	while(1)
	{
		cout<<"******************ҽԺ�źŹ���ϵͳ******************"<<endl;
		cout<<"*                                                  *"<<endl;
		cout<<"*	1.�ϰ�		2.����		3.����	   *"<<endl;	
		cout<<"*                                                  *"<<endl;		
		cout<<"*	4.�鿴�Ŷ�	5.�鿴����	0.�°�	   *"<<endl;
		cout<<"*                                                  *"<<endl;		
		cout<<"****************************************************"<<endl;
	
		cout<<"����������ѡ�";
		cin>>a;
		
		switch(a)
		{
			case 1:{
				InitQueue(Q);
				if(InitQueue(Q)==OK) cout<<"��ӭ���ϰ�"<<endl;
				system("pause");
				system("cls");
			};break;
			
			case 2:{
				cout<<"���������Ĳ����ţ�"<<endl;
				cin>>number;
				if(EnQueue_number(Q,number)==OK) cout<<"����ɹ�"<<endl;
				/*cout<<"��������������"<<endl;
				cin>>name[20];
				EnQueue_name(Q,name);*/
				system("pause");
				system("cls");
			};break;
			
			case 3:{
				if(DeQueue(Q)==OK)	cout<<"�ѳɹ��������һλ����׼��"<<endl;
				else cout<<"������ȴ�"<<endl;
				system("pause");
				system("cls");
			};break;
			
			
			
			case 4:{
				if(QueueEmpty(Q)!=1)
				{					
					cout<<"���������Ĳ����ţ�"<<endl;
					cin>>number;
					cout<<"��ǰ�滹��"<<FindQueue(Q,number)-Q.front<<"��"<<endl; 
					cout<<"���ǵĲ����ź�����Ϊ��"<<endl;
					for(int i=Q.front;i<=FindQueue(Q,number)-1;i++)
					{
						cout<<Q.elem[i]<<"   "<<endl;//Q.name[i]<<endl;
					}
				}
				else if(QueueEmpty(Q)==1)cout<<"�����Ŷ�"<<endl;
				
				system("pause");
				system("cls");	
			};break;
			
			case 5:{
				if(QueueEmpty(Q)==1)
				{
					cout<<"���˺���"<<endl;
				}
				else if(QueueEmpty(Q)==-1)
				{
					cout<<"�ܹ�����"<<QueueLength(Q)<<"��"<<endl;
				}
				system("pause");
				system("cls");
			};break;
			
			case 0:{
				if(QueueEmpty(Q)!=1) 
				{
					cout<<"������δ�������������"<<endl;
					system("pause");
					system("cls"); 
				}
				else 
				{
					cout<<"�°�ɹ�"<<endl;
					system("pause");
					return 0;
				}
			}
				
			default:{
				cout<<"�������������"<<endl;
				system("pause");
				system("cls");
				};	
			}
	}
	
}
//-----------------------------

//��ʼ��
Status  InitQueue(SqQueue &Q)
{
	Q.elem=new ElemType[MAXSIZE];
	if(!Q.elem) 
	{
		cout<<"����ʧ��"<<endl;
		exit(OVERFLOW);
	}
	Q.front=Q.rear=0;
	return OK;
}
//��ѭ�����г���
int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
//ȷ����������λ��
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
		cout<<"�޴�����"<<endl;
		return ERROR;
	}
} 
//��ӡ������� 
Status EnQueue_number(SqQueue &Q,ElemType e)
{
	if((Q.rear+1)%MAXSIZE==Q.front) return ERROR;
	Q.elem[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}
/*��ӡ���������
Status EnQueue_name(SqQueue &Q,char name[])
{
	if((Q.rear+1)%MAXSIZE==Q.front) return ERROR;
	Q.name[Q.rear]=name;
	Q.rear=(Q.rear+1)%MAXSIZE;
	return OK;
}*/
//����
Status DeQueue(SqQueue &Q)
{
	ElemType e;
	if(Q.front==Q.rear) return ERROR;
	e=Q.elem[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	return OK;
}
//ȡѭ�����ж�ͷԪ��
ElemType GetHead(SqQueue Q)
{
	if(Q.front!=Q.rear)
		return Q.elem[Q.front]; 
}
//�ж϶����Ƿ�Ϊ��
Status QueueEmpty(SqQueue Q)
{
	if(Q.front==Q.rear) return 1;
	else return -1;
}
