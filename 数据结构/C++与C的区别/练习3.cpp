#include<iostream>
using namespace std;
int main()
{
	int i,n,*a;
	cout<<"������ѧ��������";
	cin>>n;
	
	a=new int[n];
	
	for(i=0;i<n;i++)
	{
		cout<<"�������"<<i+1<<"��ѧ���ĳɼ���";
		cin>>a[i];
	}
	
	cout<<endl;
	
	for(i=0;i<n;i++)
	{
		cout<<"��"<<i+1<<"��ѧ���ĳɼ�Ϊ��"<<a[i];
	}	
	
	delete [] a;
	return 0;
}
