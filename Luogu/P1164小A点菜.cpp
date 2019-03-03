#include<iostream>
#include<cstdio>
using namespace std;
int a[105],f[10005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		f[i]=0;
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=a[i];j--)
			f[j]+=f[j-a[i]];
	}
	printf("%d\n",f[m]);
	return 0;
}

