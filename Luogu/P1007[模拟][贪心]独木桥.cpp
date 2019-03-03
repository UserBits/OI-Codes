#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int l,n,p,maxn=0,minn=0;
	scanf("%d%d",&l,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p);
		maxn+=max(0,max(p,l-p+1)-maxn);
		minn+=max(0,min(p,l-p+1)-minn);
	}
	printf("%d %d\n",minn,maxn);
	return 0;
}
