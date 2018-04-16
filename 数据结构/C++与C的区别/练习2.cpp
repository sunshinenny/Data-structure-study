#include<iostream>
using namespace std;
void Input(int &x)
{
	cin>>x;
}

int main()
{
	int x;
	cout<<"Input x:";
	Input(x);
	cout<<"x="<<x<<endl;
	return 0;
}
