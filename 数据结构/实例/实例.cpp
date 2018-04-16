/*2．订单管理
该模块完成的主要功能是接收订单、查询订单和显示订单。
（1）接收订单
系统显示的套餐信息，用户选择相应的套餐编号，输入套餐数量、订餐人姓名和电话，选择派送地址等，完成订单的接收。//struct定义结构体//string(套餐编号,订单人姓名,派送地址) int(套餐数量,订餐人电话)
（2）查询订单
可根据订单号、订餐人姓名等进行查询，显示所有符合条件的信息。
（3）显示订单
显示当前系统中所有的订单信息。//案列对其遍历所有内容//循环
【选做功能：在订单管理中，还可以添加订单编辑和订单撤消功能。】
M001	宫保鸡丁	宫保鸡丁+紫菜蛋花汤+米饭	25	1
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

Status InitList(o_SqList &L); //初始化顺序表 
Status Input(o_SqList &L,int i);//输入内容到顺序表
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
{//初始化顺序表 
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem) return ERROR;
	L.length=0;
	return OK;
}


Status Input(o_SqList &L,int i)  
{//输入内容到顺序表 
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
