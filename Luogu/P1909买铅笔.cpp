#include<iostream>
#include<cmath>
using namespace std;
int min(int p,int q)
{
	return p<q?p:q;
}
int main()
{
	int n,a,b,ans=1<<30,cost;
	cin>>n;
	for(int i=0;i<3;i++)
	{
		cin>>a>>b;
		cost=ceil(n*1.0/a)*b;
		ans=min(ans,cost);
	}
	cout<<ans<<endl;
	return 0;
}
