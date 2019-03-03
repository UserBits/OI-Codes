#include<iostream>
#include<cstdio>
using namespace std;
int a[1005][1005];
int main()
{
	int n,ans=-1,p,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]>0)
				continue;
			p=0;
			for(k=0;k<n;k++)
			{
				if(a[i][k]>0)
					p+=a[i][k];
			}
			for(k=0;k<n;k++)
			{
				if(a[k][j]>0)
					p+=a[k][j];
			}
			if(p>ans)
				ans=p;
		}
	}
	if(p==-1)
		printf("Bad Game!\n");
	else
		printf("%d\n",ans);
	return 0;
}

