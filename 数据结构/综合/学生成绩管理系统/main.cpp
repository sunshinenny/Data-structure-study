#include"main.h"
#include"SqList.h"
#include"Search.h"

int main()
{
	SqList L;
	int ch;
	while(1)
	{
		cout<<"***********ѧ���ɼ�����ϵͳ***********"<<endl; 
		cout<<"*	1.��Ϣ��ʼ��	2.˳�����		*"<<endl; 
		cout<<"*	3.���ֲ���		4.ֱ�Ӳ�������	*"<<endl; 
		cout<<"*	5.ð�ݻ�ѡ������6.��������		*"<<endl; 
		cout<<"*	0.�˳�							*"<<endl; 
		cout<<"**************************************"<<endl; 
		cout<<"��ѡ����Ҫ���еĲ���:"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:InitRecord(L); break;//������Ϣ��ʼ������
			case 2:				break;//����˳�����  Search_Seq(L)
			case 3:				break;//���ö��ֲ���   Search_Bin(L)			    
			case 4:				break;//����ֱ�Ӳ��뺯��   InsertSort(L) 		
		} 
		system("pause");
		system("cls");
	} 
	
	
	return 0;
} 
//-----------------------------------------------------------------------
//���Һ��� 
/*int SearchByName(SqList L,Key.name key)
{//˳����ҷ�����Ŀ����ʵ�ֵ�������name  ������Ҫʵ�ֵ��ǲ������е�  ���ܲ�����ʵ���������� 
	for(int i=L.length;i>=1;i--)
		if(L.elem[i].key.name==key) return i;
	return 0;
}

void Search_Seq(SqList L)
{
	//����Ҫ���ҵ�ѧ������nm
	i=SearchByName(L,nm);   //���ò��Һ��������ؽ��
	if(i==0)
	{   
	  cout<<"û�и��û�"<<endl;//��ʾδ�ҵ��� 
	} 
	else
	{
		Output(L,i);//����ҵ���ѧ����Ϣ
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
//ֱ�Ӳ������� 

