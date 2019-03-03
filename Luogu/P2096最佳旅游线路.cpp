#include <cstdio>
using namespace std;
int a[205][23005];
inline int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int m,n,x,y,f,ans=0,sum=0;
	scanf("%d%d",&m,&n);
	for(int i=1; i<=m; i++)
	{
		for(int j=1; j<=n; j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=1; i<=n; i++)
	{
		f=-1<<30;
		for(int j=1; j<=m; j++)
			f=max(a[j][i],f);
		if(f<0)
		{
			ans=max(sum,ans);
			if(sum+f>0)
				sum+=f;
			else
				sum=0;
		}
		else
			sum+=f;
	}
	if(sum)
		ans=max(ans,sum);
	printf("%d\n",ans);
	return 0;
}

