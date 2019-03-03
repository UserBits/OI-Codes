#include<iostream>
using namespace std;
int main()
{
	long long n;
	int i=0;
	cin>>n;
	bool p[32]={0},ans[32]={0};
	long long sum=0,k=1;
	while(n!=0)
	{
		p[i++]=n%2;
		n/=2;
	}
	for(int j=0;j<i;j++)
		ans[31-j]=p[j];
	for(int j=0;j<=15;j++)
		p[j]=ans[16+j];
	for(int j=16;j<=31;j++)
		p[j]=ans[j-16];
	for(int j=31;j>=0;j--)
	{
		sum+=p[j]*k;
		k*=2;
	}
	cout<<sum<<endl;
	return 0;
}
