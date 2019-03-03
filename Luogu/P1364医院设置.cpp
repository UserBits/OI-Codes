#include <cstdio>
using namespace std;
int a[105],p[105][105];
int main()
{
	int n,i,j,k,l,r,minn=0x7fffffff,tmp;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			p[i][j]=100000000;
	}
	for(i=1;i<=n;i++)
	{
		p[i][i]=0;
		scanf("%d%d%d",&a[i],&l,&r);
		if(l>0)
			p[i][l]=1,p[l][i]=1;
		if(r>0)
			p[i][r]=1,p[r][i]=1;
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			if(i!=k)
			{
				for(j=1;j<=n;j++)
				{
					if(i!=j && k!=j && p[i][k]+p[k][j]<p[i][j])
						p[i][j]=p[i][k]+p[k][j];
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		tmp=0;
		for(j=1;j<=n;j++)
		{
			if(i!=j)
				tmp+=p[i][j]*a[j];
		}
		if(tmp<minn)
			minn=tmp;
	}
	printf("%d\n",minn);
	return 0;
}

