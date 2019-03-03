#include<iostream>
#include<cstdio>
using namespace std;
long long a[35];
int main()
{
	int n;
	cin>>n;
	a[0]=1;
	for(int	i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
			a[i]+=a[j]*a[i-j-1];
	}
	cout<<a[n]<<endl;
	return 0;
}

