#include<iostream>
#include<cstdio>
using namespace std;
bool p[10005];
int main()
{
	int n,m,l,r,cut=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<10005;i++)
		p[i]=1;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++)
			p[j]=0;//printf("%d ",j);
	}
	//cout<<endl;
	for(int i=0;i<=n;i++)
	{
		//printf("%d ",p[i]);
		if(p[i]==0)
			cut++;
	}
	//cout<<endl;
	printf("%d\n",n+1-cut);
	return 0;
}
