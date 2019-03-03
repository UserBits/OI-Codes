#include<iostream>
using namespace std;
int c[30];
int main()
{
	int n;
	cin>>n;
	c[0]=c[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<i;j++)
			c[i]+=c[j]*c[i-j-1];
	}
	cout<<c[n]<<endl;
	return 0;
}
