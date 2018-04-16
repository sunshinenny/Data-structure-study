#include<iostream>
using namespace std;
int main()
{
	int i,n,*a;
	cout<<"请输入学生数量：";
	cin>>n;
	
	a=new int[n];
	
	for(i=0;i<n;i++)
	{
		cout<<"请输入第"<<i+1<<"个学生的成绩：";
		cin>>a[i];
	}
	
	cout<<endl;
	
	for(i=0;i<n;i++)
	{
		cout<<"第"<<i+1<<"个学生的成绩为："<<a[i];
	}	
	
	delete [] a;
	return 0;
}
