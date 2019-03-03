#include<iostream>
using namespace std;
int work(int m,int n)
{
	if(n==1 || m==0)
		return 1;
	if(m<n)
		return work(m,m);
	else
		return work(m,n-1)+work(m-n,n);
}
int main()
{
	int i;
	cin>>i;
	while(i--)
	{
		int a,b;
		cin>>a>>b;
		cout<<work(a,b)<<endl;
	}
	return 0;
}
