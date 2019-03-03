#include<iostream>
using namespace std;
int n,m,k,w,r,k1,a(0),c[10001],x(1),ans(0);
int main()
{
	cin>>n>>m>>k>>w>>r;
	for(int i=1; i<=n; i++)
		cin>>c[i];
	k1=m/k;
	while(a<r)
	{
		if(c[x]<=0)x++;
		c[x]-=k1*w;
		a++;
	}
	for(int i=1; i<=n; i++)
	{
		if(c[i]>0)
			ans++;
	}
	cout<<ans;
	return 0;
}
