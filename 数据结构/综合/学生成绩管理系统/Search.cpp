//#include"main.h"
#include"Search.h"
#include"SqList.h"

int SearchByName(SqList L,string key)
{//顺序查找姓名 
	for(int i=L.length;i>=0;--i)
		if(L.elem[i].key.name==key) return i;
	return 0;
}


int Search_Bin(SSTable ST,KeyType key)
{//折半查找有序表											
	int low,high,mid;
	low=1;high=ST.length;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key==ST.elem[mid].key) return mid;
		else if(key<ST.elem[mid].key) high=mid-1;
		else low=mid+1;	
	}
	return 0;
 }

