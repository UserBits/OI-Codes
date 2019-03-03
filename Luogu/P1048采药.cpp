#include<iostream>
#include<cstdio>
using namespace std;
int max(int a,int b)
{
	return a>b?a:b;
}
int a[1005],b[1005],f[1005];
inline void read()
{
	int i,t,m;
	scanf("%d%d",&t,&m);
	for(i=1;i<=m;i++)
		scanf("%d%d",&a[i],&b[i]);
	int j;
	for(i=1;i<=m;i++)
	{
		for(j=t;j>=a[i];j--)
			f[j]=max(f[j],f[j-a[i]]+b[i]);
	}
	printf("%d\n",f[t]);
}
int main()
{
	read();
	return 0;
}

