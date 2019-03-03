#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	unsigned long long n,x,ans=0;
	cin>>x>>n;
	for(int i=0;i<n;i++)
	{
		if(x!=6 && x!=7)
			ans+=250;
		if(x==7)
			x=1;
		else
			x++;
	}
	cout<<ans<<endl;
	return 0;
}
