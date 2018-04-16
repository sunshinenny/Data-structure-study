/*2����������
��ģ����ɵ���Ҫ�����ǽ��ն�������ѯ��������ʾ������
��1�����ն���
ϵͳ��ʾ���ײ���Ϣ���û�ѡ����Ӧ���ײͱ�ţ������ײ������������������͵绰��ѡ�����͵�ַ�ȣ���ɶ����Ľ��ա�//struct����ṹ��//string(�ײͱ��,����������,���͵�ַ) int(�ײ�����,�����˵绰)
��2����ѯ����
�ɸ��ݶ����š������������Ƚ��в�ѯ����ʾ���з�����������Ϣ��
��3����ʾ����
��ʾ��ǰϵͳ�����еĶ�����Ϣ��//���ж��������������//ѭ��
��ѡ�����ܣ��ڶ��������У���������Ӷ����༭�Ͷ����������ܡ���
M001	��������	��������+�ϲ˵�����+�׷�	25	1
*/
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<string>
#include<iomanip>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct
{
	string o_info,p_name,address;
	int o_num,p_phone;
}ElemType;

typedef struct
{
	ElemType *elem;
	int length;
}o_SqList;

Status InitList(o_SqList &L); //��ʼ��˳��� 
Status Input(o_SqList &L,int i);//�������ݵ�˳���
void ShowList(o_SqList L);

int main()
{
	o_SqList L;
	InitList(L);
	
	cout<<"Please try to input the order info,numers,perple's name&phone number:'"<<endl;
	Input(L,1);	
	return 0;	
}
 
Status InitList(o_SqList &L)
{//��ʼ��˳��� 
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem) return ERROR;
	L.length=0;
	return OK;
}


Status Input(o_SqList &L,int i)  
{//�������ݵ�˳��� 
	//if(i>L.length||i<0) return ERROR;
	
	cin>>L.elem[i].o_info;	L.length++;		
	cin>>L.elem[i].o_num;		L.length++;
	cin>>L.elem[i].p_name;	L.length++;
	cin>>L.elem[i].p_phone;	L.length++;
	cin>>L.elem[i].address;	L.length++;
	
	ShowList(L);
	return OK;
}


void ShowList(o_SqList L)
{
	cout<<endl<<L.length;
	for(int i=1;i<=L.length;i++)
	{
		cout<<setw(4)<<L.elem[i].o_info<<endl;
		cout<<setw(4)<<L.elem[i].o_num<<endl;
		cout<<setw(4)<<L.elem[i].p_name <<endl;
		cout<<setw(4)<<L.elem[i].p_phone<<endl;
		cout<<setw(4)<<L.elem[i].address<<endl;
	}	
}
