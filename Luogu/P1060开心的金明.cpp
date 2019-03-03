#include<cstdio>
using namespace std;
int a[30005],b[30005],f[30005];
int max(int p,int q)
{
	return p>q?p:q;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<30005;i++)
		f[i]=0;
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=a[i];j--)
			f[j]=max(f[j],f[j-a[i]]+a[i]*b[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}

