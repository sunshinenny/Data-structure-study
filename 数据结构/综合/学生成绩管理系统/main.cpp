#include"main.h"
#include"SqList.h"
#include"Search.h"

int main()
{
	SqList L;
	int ch;
	while(1)
	{
		cout<<"***********学生成绩管理系统***********"<<endl; 
		cout<<"*	1.信息初始化	2.顺序查找		*"<<endl; 
		cout<<"*	3.二分查找		4.直接插入排序	*"<<endl; 
		cout<<"*	5.冒泡或选择排序6.快速排序		*"<<endl; 
		cout<<"*	0.退出							*"<<endl; 
		cout<<"**************************************"<<endl; 
		cout<<"请选择所要进行的操作:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:InitRecord(L); break;//调用信息初始化函数
			case 2:				break;//调用顺序查找  Search_Seq(L)
			case 3:				break;//调用二分查找   Search_Bin(L)			    
			case 4:				break;//调用直接插入函数   InsertSort(L) 		
		} 
		system("pause");
		system("cls");
	} 
	
	
	return 0;
} 
//-----------------------------------------------------------------------
//查找函数 
/*int SearchByName(SqList L,Key.name key)
{//顺序查找方法，目标是实现单独查找name  不过想要实现的是查找所有的  可能不大现实，继续尝试 
	for(int i=L.length;i>=1;i--)
		if(L.elem[i].key.name==key) return i;
	return 0;
}

void Search_Seq(SqList L)
{
	//输入要查找的学生姓名nm
	i=SearchByName(L,nm);   //调用查找函数，返回结果
	if(i==0)
	{   
	  cout<<"没有该用户"<<endl;//提示未找到！ 
	} 
	else
	{
		Output(L,i);//输出找到的学生信息
	} 
}

//
int Search_Bin(SSTable ST,KeyType.num key)							int Search_Bin(SSTable ST,KeyType.num key)
{																	{
	int low,high,mid;													int low,high,mid;
	low=1;high=ST.length;												low=1;high=ST.length;
	while(low<=high)													while(low<=high)
	{																	{
		mid=(low+high)/2;													mid=(low+high)/2;
		if(key==ST.elem[mid].key) return mid;								if(key==ST.elem[mid].key) return mid;
		else if(key<ST.elem[mid].key) high=mid-1;							else if(key<ST.elem[mid].key) high=mid-1;
		else low=mid+1;														else low=mid+1;
	}																	}
	return 0;															return 0;	
 } 																	}
*/
//-----------------------------------------------------------------------
//直接插入排序 

